#include <stdio.h>
#include "../include/mystring.h"


int mystrlen(char s[]) {
   int len = 0;
   while (s[len] != '\0')
      len++;
   printf("Length of String is : %d\n", len);
   return 0;
 }

int mystrcpy(char s1[]) {
    char s2[100],i;
   
    for (i = 0; s1[i] != '\0'; ++i) {
        s2[i] = s1[i];
    }

    s2[i] = '\0';
    printf("Copied String is: %s\n", s2);
    return 0;
}

int mystrcat(char s1[], char s2[]) {


  int length, j;

  length = 0;
  while (s1[length] != '\0') {
    ++length;
  }

  for (j = 0; s2[j] != '\0'; ++j, ++length) {
    s1[length] = s2[j];
  }

  s1[length] = '\0';

  printf("After concatenation: ");
  puts(s1);

  return 0;
}


int mystrcmp(char s1[], char s2[])
{
 
  int result, i;
   
  for(i = 0; s1[i] == s2[i] && s1[i] == '\0'; i++);
 
  if(s1[i] < s2[i])
    {
    printf("string 1 is not equal to string 2\n");
}
else if(s1[i] > s2[i])
    {
    printf("string 1 is not equal to string 2\n");
}
else
    {
    printf("str1 is Equal to str2\n");
}
 
  return 0;
}

/*

int main()
{
char s1[100];
char s2[100];

printf("Enter 1st String : ");
gets(s1);
printf("Enter 2nd String : ");
gets(s2);
mystrlen(s1);
mystrcpy(s1);
mystrcat(s1,s2);
mystrcmp(s1,s2);
return 0;
}
*/
