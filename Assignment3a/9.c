#include <stdio.h> 
// To use time library of C 
#include <time.h> 
  
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
  
// Driver code to test above function 
int main() 
{ 

 


    time_t s, val = 1; 
    struct tm* current_time; 
  

 

    int i; 
    for (i = 0; i < 1000; i++) { 
        // delay of one second 
        s = time(NULL); 
       current_time = localtime(&s); 
        printf("%02d:%02d:%02d\n", 
           current_time->tm_hour, 
           current_time->tm_min, 
           current_time->tm_sec); 

 

         delay(1000); 
       
    } 
    return 0; 
} 
