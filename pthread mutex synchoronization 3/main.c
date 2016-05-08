//
//  main.c
//  pthread mutex synchoronization 3
//
//  Created by Ahmed masoud on 4/27/16.
//  Copyright © 2016 Ahmed masoud. All rights reserved.
//

//
//  main.c
//  Threads Synchronization using Mutex
//
//  Created by Ahmed masoud on 4/25/16.
//  Copyright © 2016 Ahmed masoud. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[3];

pthread_mutex_t* locks;

void* doSomeThing(void *arg)
{
    char index = ((char*)(arg))[1];
    int i = 0;
    for (i=0; i<10; i++) {
        pthread_mutex_lock(locks+index);
        
        
        char toBePrinted =  ((char*)(arg))[0];
        
        
        sleep(rand()/RAND_MAX);
        printf("\n Letter %c started\n", toBePrinted);
        
        
        pthread_mutex_unlock(locks + (index + 1)%3);
        

    }
    
    
   
    
    return NULL;
}

int main(void)
{
    int err;
    locks = malloc(sizeof(pthread_mutex_t)*3);
    pthread_mutex_init(&locks[0], NULL);
    pthread_mutex_init(&locks[1], NULL);
    pthread_mutex_init(&locks[2], NULL);
    
    char *A;
    A = malloc(sizeof(char)*2);
    A[0]='A';
    A[1]=0;
    pthread_create(&(tid[0]), NULL, &doSomeThing, A);
    pthread_mutex_lock(&locks[1]);
    char *B;
    B = malloc(sizeof(char)*2);
    B[0]='B';
    B[1]=1;
    pthread_create(&(tid[1]), NULL, &doSomeThing, B);
    pthread_mutex_lock(&locks[2]);
    char *C;
    C = malloc(sizeof(char)*2);
    C[0]='C';
    C[1]=2;
    pthread_create(&(tid[2]), NULL, &doSomeThing, C);
    
    
    
    
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_mutex_destroy(locks);
    
    return 0;
}
/********************************/

