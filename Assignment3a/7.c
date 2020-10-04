#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 5 

void* task_body2(void* pv)
{
	int i;
	printf("B--welcome\n");
	for(i=1;i<=10;i++)
		printf("B--%d\n",i);
	//pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	int i, policy=SCHED_RR;    
	long unsigned int pthread_t_tid[NUM_THREADS];     
	pthread_attr_t attr;
	// get the default attributes     
	pthread_attr_init(&attr); 
	// get the current scheduling policy
	if (pthread_attr_getschedpolicy(&attr, &policy) != 0)        
		fprintf(stderr, "Unable to get policy.\n");  
	if (pthread_attr_setschedpolicy(&attr, SCHED_RR) != 0)        
		 fprintf(stderr, "Unable to set policy.\n");
	// set the scheduling policy - FIFO, RR, or OTHER     
	else
	{        
		if (policy == SCHED_OTHER) 
			printf("SCHED_OTHER\n");        
		else if (policy == SCHED_RR) 
			printf("SCHED_RR\n");        
		else if (policy == SCHED_FIFO) 
			printf("SCHED_FIFO\n");
	}
	  
	if (pthread_attr_setschedpolicy(&attr, SCHED_RR) != 0)        
		 fprintf(stderr, "Unable to set policy.\n");
	//create the threads     
	for (i = 0; i < NUM_THREADS; i++)        
		pthread_create(&pthread_t_tid[i],&attr,task_body2,NULL);     
	//now join on each thread    
	for (i = 0; i < NUM_THREADS; i++)        
		pthread_join(pthread_t_tid[i], NULL);
	
	printf("main--thank you\n");
	return 0;	//exit(0);
}
