#include<stdio.h> 

#include<sys/types.h> 

#include<unistd.h> 

#include<stdlib.h> 

void main() 

{ 

int pid=fork(); 

if(pid>0) 

{ 

printf("in parent process:%d\n",getpid()); 

sleep(3); 

} 

else if(pid==0) 

{ 

printf("in child process:%d\n",getpid()); 

printf("in parent process:%d\n",getppid()); 

sleep(3); 

printf("in child process:%d\n",getpid()); 

printf("in parent process:%d\n",getppid()); 

} 
}