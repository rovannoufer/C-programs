#include <stdio.h> 

#include <sys/types.h> 

#include <unistd.h> 

#include <stdlib.h> 

void main() 

{ 

pid_t child_pid = fork(); 

if(child_pid > 0) 

{ 

} 

else 

sleep(5); 

system("ps -eo pid,ppid,stat,cmd"); 

exit(0); 

} 

 