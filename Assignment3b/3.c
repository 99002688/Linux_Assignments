#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

int MAXSIZE = 8;       
int stack[8];     
int top = -1;  
int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}
int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Couldn't retrieve data, Stack is empty.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Couldn't insert data, Stack is full.\n");
   }
}


const int max=10;
pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
sem_t s1;

void* efun1(void* pv)		//producer - push operation
{
	int i;
	
	printf("Currently in the Push operation of 2,3,4\n");
	pthread_mutex_lock(&m1);
	
	push(2);
	push(3);
	push(4);
	
	
	
	pthread_mutex_unlock(&m1);
	sem_post(&s1);
	//pthread_exit(NULL);
}
void* efun2(void* pv)		//consumer -pop operation
{
	int i;
	printf("Currently in the Pop Operation of only 3,4 and 2 is remaining\n");
	sem_wait(&s1);			//changing sequence lead to deadlock
	pthread_mutex_lock(&m1);
	
	pop();
	pop();
	
	
	
	pthread_mutex_unlock(&m1);
	//pthread_exit(NULL);
}
int main()
{
	printf("Producer Consumer problem using Stack operations using semaphores\n");
	pthread_t pt1,pt2;	//thread handles
	sem_init(&s1,0,0);
	pthread_create(&pt1,NULL,efun1,NULL);
	pthread_create(&pt2,NULL,efun2,NULL);
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	printf("Element at top of the stack: %d\n" ,peek());
	printf("Stack full: %s\n" , isfull()?"true":"false");
   	printf("Stack empty: %s\n" , isempty()?"true":"false");
	sem_destroy(&s1);
	pthread_mutex_destroy(&m1);
	printf("main--Thank you\n");
	return 0;
}

