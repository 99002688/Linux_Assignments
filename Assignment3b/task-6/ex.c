/*#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>


void printFileProperties(struct stat stats);

struct msg_buffer {
   long msg_type;
   char msg[100];
   struct stat stats;
} message;

int main()
{
  
    struct stat stats;

   key_t my_key;
   int msg_id;
   int c,s,ret,i,j=0;
   char path[100];
   my_key = ftok("progfile", 65); //create unique key
   msg_id = msgget(my_key, 0666 | IPC_CREAT); //create message queue and return id
   msgrcv(msg_id, &message, sizeof(message), 1, 0);
   for(i=0;i<strlen(message.msg);i++)
   {
   if(message.msg[i]==39||message.msg[i]=='\n')
   {}
   else
   {
   path[j]=message.msg[i];
   j++;}
   }
    // stat() returns 0 on successful operation,
    // otherwise returns -1 if unable to get file properties.
    if (stat(path, &message.stats) == 0)
    {
        
        msgsnd(msg_id, &message, sizeof(message), 0);
    }
    else
    {
        printf("Unable to get file properties.\n");
        printf("Please check whether '%s' file exists.\n", path);
    }
    
    
    return 0;
}




