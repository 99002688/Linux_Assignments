/*4. Implement a simple client-server scenario using message queues
   * Client process send a string over message queue
   * Server process toggles the string and send back to client.*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// structure for message queue
struct msg_buffer {
   long msg_type;
   char msg[100];
} message;
int main() {
   key_t my_key;
   int msg_id;
   my_key = ftok("progfile", 65); //create unique key
   msg_id = msgget(my_key, 0666 | IPC_CREAT); //create message queue and return id
   message.msg_type = 1;
   printf("Enter Command: ");
   fgets(message.msg, 100, stdin);
   msgsnd(msg_id, &message, sizeof(message), 0); //send message
   msgrcv(msg_id, &message, sizeof(message), 1, 0); 
   return 0;
}
