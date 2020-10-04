#include<stdio.h>
#include "include/mystring.h"
#include "include/myutils.h"
#include "include/bitmask.h"
int main(){
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


int a,b,c,d,x,y;
  int count = 3;
printf("Enter a no to calculate factorial: ");
scanf("%d",&a);
printf("Enter a no to check whether the no is prime or not: ");
scanf("%d",&b); 
printf("Enter a no to check whether the no is palindrome or not: "); 
scanf("%d",&c); 
/* 
a=4;
b=5;
c=1000;*/
 d=factorial(a);
 isprime(b);
 ispalindrome(c);
 printf("factorial is %d \n",d); 
  x=sum(count, a,b,c);
  printf("sum is %d \n",x);

int n=5; 
int k=2;

setBit(n,k);
resetBit(n,k);
flip(n);
query(n,k);

return 0;
}
