#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<string.h>
using namespace std;
  
int main()
{
    // ftok to generate unique key
    key_t key = ftok("shmfile",65);
  
    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);
  
    // shmat to attach to shared memory
    char *str = (char*) shmat(shmid,(void*)0,0);
  
    cout<<endl<<endl<<"Write Data : ";
    fgets(str, 100, stdin);
    cout<<endl<<"Data written in memory: "<<str<<endl<<endl;
    
      
    //detach from shared memory 
    shmdt(str);
  
    return 0;
}