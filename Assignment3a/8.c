#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 

 

#define max 16 
#define Th_max 4 

 

int a[max] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 300, 64, 110, 220 }; 

 

int max_num[Th_max] = { 0 }; 
int mins_num[Th_max]={0};
int thread_no = 0; 
int thread_no1 = 0; 

 

void maximum(void* arg) 
{ 
    int i, num = thread_no++; 
    int maxs = 0; 

 

    for (i = num * (max / 4); i < (num + 1) * (max / 4); i++) { 
        if (a[i] > maxs) 
            maxs = a[i]; 
    } 
    max_num[num] = maxs; 
} 
void minimum(void* arg) 
{ 
    int i, num = thread_no1++; 
    int mins= 300; 

 

    for (i = num * (max / 4); i < (num + 1) * (max / 4); i++) { 
        if (a[i] < mins) 
            mins = a[i];
    } 
    mins_num[num] = mins; 
} 
int main() 
{ 
    int maxs = 0; 
    int mins=300;
    int i; 
    pthread_t threads[Th_max]; 
    pthread_t threads2[Th_max]; 

 

    for (i = 0; i < Th_max; i++) 
        pthread_create(&threads[i], NULL,maximum, (void*)NULL); 

 

    for (i = 0; i < Th_max; i++) 
        pthread_join(threads[i], NULL); 

 

    for (i = 0; i < Th_max; i++) { 
        if (max_num[i] > maxs) 
            maxs = max_num[i]; 
    }
    
    for (i = 0; i < Th_max; i++) 
        pthread_create(&threads2[i], NULL, minimum, (void*)NULL); 
 
    for (i = 0; i < Th_max; i++) 
        pthread_join(threads2[i], NULL); 

 

    for (i = 0; i < Th_max; i++) { 
        if (mins_num[i] <mins) {mins = mins_num[i];}    
    }
    
    printf("Maximum Element is : %d\n", maxs); 
    printf("Minimum Element is : %d\n", mins); 
    

 

    return 0; 
} 
