#include <sys/socket.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFSIZE 		1500
#define LISTENSIZE 		128
#define MYPORT  		8000
#define MAXBUF 			1500
#define MAXQUESIZE 		30
#define PATHSIZE 		260
void * taskfun (void* arg);
void * manager (void* arg);
typedef struct node1
{
	void*(*fun)(void*);
	void* arg;
}task_t;

typedef struct node2
{
	int max;
	int min;
	int size;
	int sear;
	int wait;
	int front;
	int alive;
	int maxsize;
	int busy;
	pthread_mutex_t mt_poolarg;
	pthread_mutex_t mt_pool;
	pthread_cond_t  full;
	pthread_cond_t  empty;
	task_t * task;//arr
	pthread_t* manager_pthread;
	pthread_t* tid;//arr
}pool_t;

typedef struct node3
{
	int clientfd;
}mynode;

pool_t * pool_create(int min ,int max,int maxsize)
{
	pool_t* pool=(pool_t*)malloc(sizeof(pool_t));
	memset(pool,0,sizeof(pool_t));
	pool->max=max;
	pool->min=min;
	pool->maxsize=maxsize;
	if(!(pthread_mutex_init(&(pool->mt_pool),NULL)||pthread_mutex_init(&(pool->mt_pool),NULL)||pthread_cond_init(&(pool->full),NULL)||pthread_cond_init(&(pool->empty),NULL)))
	{
		pool->manager_pthread=(pthread_t*)malloc(sizeof(pthread_t));
		pool->tid=(pthread_t*)malloc(sizeof(pthread_t)*maxsize);
		pool->task=(task_t*)malloc(sizeof(task_t)*maxsize);
		
		pthread_create(pool->manager_pthread,NULL,manager,(void*)pool);
		for(int i=0;i<min;i++)
		{
			pthread_create(&(pool->tid[i]),NULL,taskfun,(void*)pool);
			pthread_mutex_lock(&(pool->mt_poolarg));
			pool->alive++;
			pthread_mutex_unlock(&(pool->mt_poolarg));
		}
		return pool;
	}
	else
	{
		free(pool);
		perror("init\n");
		return NULL;
	}
}
void * taskfun (void* arg)
{
	pthread_detach(pthread_self());
	pool_t * pool=(pool_t*)arg;
	task_t  task;
	while(1)
	{
		pthread_mutex_lock(&(pool->mt_pool));
		if(pool->size==0)
		{
			pthread_cond_wait(&(pool->empty),&(pool->mt_pool));
			if(pool->wait>0 && pool->alive>pool->min)
			{

				pthread_mutex_lock(&(pool->mt_poolarg));
				pool->wait--;
				pool->alive--;
				pthread_mutex_unlock(&(pool->mt_poolarg));
				pthread_mutex_unlock(&(pool->mt_pool));
				pthread_cond_signal(&(pool->empty));
				pthread_exit(0);
			}
			else
				pthread_mutex_unlock(&(pool->mt_pool));

		}
		else
		{
			task.fun=(pool->task[pool->front]).fun;
			task.arg=(pool->task[pool->front]).arg;
			pool->front=(pool->front+1)%(pool->maxsize);
			pool->size--;
			pool->busy++;
			pthread_mutex_unlock(&(pool->mt_pool));
			(*(task.fun))(task.arg);
			pthread_mutex_lock(&(pool->mt_pool));
			pool->busy--;
			pthread_cond_signal(&(pool->full));
			pthread_mutex_unlock(&(pool->mt_pool));
		}
	}

}
void task_add(pool_t* pool ,void*(*fun)(void*),void*arg)
{
	pthread_mutex_lock(&(pool->mt_pool));
	while(pool->size==pool->maxsize)
	{
		pthread_cond_wait(&(pool->full),&(pool->mt_pool));
	}
	if((pool->task[pool->sear]).arg!=NULL)
	{
		free((pool->task[pool->sear]).arg);
		(pool->task[pool->sear]).arg=NULL;
	}
	(pool->task[pool->sear]).arg=arg;
	(pool->task[pool->sear]).fun=fun;
	pool->sear=(pool->sear+1)%(pool->maxsize);
	pool->size++;
	pthread_cond_signal(&(pool->empty));
	pthread_mutex_unlock(&(pool->mt_pool));
	
}
int getbusy(void*arg)
{
	int busy;
	pool_t* pool=(pool_t*)arg;
	pthread_mutex_lock(&(pool->mt_poolarg));
	busy=pool->busy;
	pthread_mutex_unlock(&(pool->mt_poolarg));
	return busy;
}
int getalive(void*arg)
{
	int busy;
	pool_t* pool=(pool_t*)arg;
	pthread_mutex_lock(&(pool->mt_poolarg));
	busy=pool->alive;
	pthread_mutex_unlock(&(pool->mt_poolarg));
	return busy;
}

void * manager (void* arg)
{

	sleep(5);

	pool_t* pool=(pool_t*)arg;
	int busy;
	int alive;
	while(1)
	{
	    busy=getbusy((void*)pool);
	    alive=getalive((void*)pool);
		if(alive-busy<3 && alive<pool->max)
		{
			printf("need add thread alive=%d,busy=%d\n",alive,busy);
			for(int i,j;(alive<(pool->max))&&j<20&&i<(pool->max);i++)
			{
				if((pool->tid[i])!=0)
					continue;
				else
				{
					pthread_create(&(pool->tid[i]),NULL,taskfun,(void*)pool);
					j++;
					pthread_mutex_lock(&(pool->mt_poolarg));
					pool->alive++;
					pthread_mutex_unlock(&(pool->mt_poolarg));

				}
			}
			continue;
		}
		if(alive-busy>3 && alive>pool->min)
		{
			printf("need del thread alive=%d min=%d busy=%d\n",alive,pool->min,busy);
			pthread_mutex_lock(&(pool->mt_poolarg));
			pool->wait++;
			pthread_mutex_unlock(&(pool->mt_poolarg));
				
		}
		sleep(1);
	}
}


void *mytask(void* arg)
{
	int clientfd=(((mynode*)arg)->clientfd);
	pthread_detach(pthread_self());
	char buf[BUFSIZE];
	int flags; 		//read flag
	
	fcntl(STDIN_FILENO,F_SETFL,O_NONBLOCK);
	fcntl(clientfd,F_SETFL,O_NONBLOCK);
	int n=0;
	int j=0;
	int logfd ;
	char str[PATHSIZE];
	sprintf(str,"./log_%d.log",backid);
	if(-1==(logfd = open(str,O_WRONLY|O_CREAT,0664)))
	{
		perror("open log");
	}

	while(1)
	{
		if(0>(n=read(STDIN_FILENO,buf,BUFSIZE)))
		{
			if(errno != EAGAIN)
			{
				perror("read STDIN");
			}
		}	
		else
		{
			write(clientfd,buf,n);
		}
		memset(buf,0,sizeof(buf));
		n=0;
		j=0;
		if(0<(j=n=read(clientfd,buf,BUFSIZE)))
		{

			printf("from client=%d\n ",clientfd);
			lseek(logfd,0,SEEK_SET);
			while(1)
			{				
				write(logfd,buf,j);
				j=0;
				memset(buf,0,sizeof(buf));
				if((j=read(clientfd,buf,BUFSIZE))>0)
				{
					continue;
				}
				else 
				{
					printf("getlog from client=%d success\n",clientfd);
					break;
				}
			}
		}
		else 
		{
			if(errno !=EAGAIN)
				perror("read clientfd");
		}
		if(n==0)
		{
			printf("clientfd=%d  is exit\n",clientfd);
			close(clientfd);
			close(logfd);
			break;
		}
		sleep(1);
	}
}



int main()
{
	pool_t * pool;
	struct sockaddr_in seraddr,clientaddr;
	memset(&seraddr,0,sizeof(seraddr));
	seraddr.sin_port=htons(MYPORT);
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=htonl(INADDR_ANY);
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	bind(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr));
	listen(sockfd,LISTENSIZE);

	pool=pool_create(10,20,20);
	mynode* node;
	sleep(3);
	while(1)
	{
		socklen_t clientsize=0;
		int clientfd;
		if(0<(clientfd=accept(sockfd,(struct sockaddr*)&clientaddr,&clientsize)))
		{
			printf("new client accept seccess\n");
		   	node=(mynode*)malloc(sizeof(mynode));
			node->clientfd=clientfd;
			task_add(pool,mytask,(void*)node);
		}

		//node->m=i;
		//node->n=i+1;
	} 
	while(1)
		sleep(1);
	return 0;
}

