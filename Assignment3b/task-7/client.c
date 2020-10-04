//client_chat
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h> 
#include<linux/stat.h>
#define FIFO_FILE "MYFIFO" //create MYFIFO pipe before executin mkfifo MYFIFO
int main()
{
   FILE *fp;
   char a[40];
   char readbuf[80];
   start:
      if((fp=fopen(FIFO_FILE,"r+"))==NULL)
      {
         perror("fopen");
         exit(1);
      }
      printf("Client: ");
      gets(a);
      if(a[strlen(a)-1]=='.')
      {
           fputs(a,fp);
           fclose(fp);
           return 0;
      }
      fputs(a,fp);
      fclose(fp);
      sleep(1);
      fp=fopen(FIFO_FILE,"r");
      fgets(readbuf,80,fp);
      printf("Server :%s\n",readbuf);
      fclose(fp);
      sleep(1);
      goto start;
   return 0;
}

