#include<stdio.h>
#include"../include/myutils.h"
#include <stdarg.h>


int  factorial(int num){
int i,fact=1;
if(num<0)
	printf("error factorial of a negative num \n");
else
	for(i=1;i<=num;++i){
	fact*=i;
	}
	return fact;
	}

int isprime(int num){
int i,flag=0;
for(i=2;i<=num/2;++i){
if(num%i==0){
flag=1;
break;
}
}
if(num==1){
printf("1 is not prime num \n");
}
else{
	if(flag==0){
printf("%d is a prime num \n",num);
}
	else{
printf("%d is not a prime num \n",num);
}
}
return 0;
}
int  ispalindrome(int num){
int reversedn=0,reminder,originaln;
originaln=num;
while(num!=0){
reminder=num%10;
reversedn=reversedn*10+reminder;
num/=10;
}
if(originaln==reversedn)
	printf("%d is a palindrome \n",originaln);
else
	printf("%d is not a palindrome \n",originaln);
return 0;
}


/*
int sum(int arg_count,...)
{
    int i;
    int first, a;


    va_list ap;
    va_start(ap, arg_count);
  
int sum=0;
    
    for (i = 1; i <= arg_count; i++) 
        sum+=va_arg(ap,int);

    va_end(ap);
    return sum;
}



*/


int sum(int num, ...) 
{ 
    va_list valist; 
  
    int sum = 0, i; 
  
    va_start(valist, num); 
    for (i = 0; i < num; i++)  
        sum += va_arg(valist, int); 
  
    va_end(valist); 
  
    return sum; 
} 
