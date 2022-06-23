#include<stdio.h> 

#include<sys/types.h> 

#include<sys/shm.h> 

#include<sys/ipc.h> 

#include<unistd.h> 

#include<stdlib.h> 

int writer() 

{ 

key_t key=ftok("shmfile",65); 

int shmid=shmget(key,1024,0666|IPC_CREAT); 

char *str=(char*)shmat(shmid,(void*)0,0); 

printf("Data to write:"); 

gets(str); 

shmdt(str); 

return 0; 

} 

int reader() 

{ 

 

key_t key=ftok("shmfile",65); 

int shmid=shmget(key,1024,0666|IPC_CREAT); 

char *str=(char*)shmat(shmid,(void*)0,0); 

printf("Data read from memory:%s\n",str); 

shmdt(str);//detach 

 

shmctl(shmid,IPC_RMID,NULL);//destroy 

return 0; 

} 

void main() 

{ 

pid_t child=fork(); 

if(child==0) 

{ 

writer(); 

} 

else if(child>0) 

{ 

sleep(10); 

reader(); 

exit(0); 

} 

} 