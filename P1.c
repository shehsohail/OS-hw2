#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>


//Define mutex object
pthread_mutex_t lock;

void *isPrime(void *arg)
{
    //Cast
    int incoming=(int) arg;
    
    //Create a dynamic array
    bool *A=(bool*)malloc(incoming*sizeof(bool));
    
    //Let A be an array of Boolean values indexed by integers 2 to n intially all set to true
    for(int s=2;s<=incoming;s++)
    {
        A[s]=true;
    }
    
    for(int i=2; i<=incoming;i++)
    {
        if(A[i]==1)
        {
            for(int j=2;j*i<=incoming;j++)
            {
                A[j*i]=false;
            }
        }
        
    }
    
    for(int i=2;i<=incoming;i++)
        
    {
        if(A[i]==1)
            printf("%d\n",i);
    }
    return NULL;
    
}

int main(int argc, char *argv[])
{
    //Prompt user to enter a positive value to calculate the prime numbers upto
    printf("Please enter a positive value that you would like to calculate the prime numbers upto:\n");
    
    //Variable to store the user inputted value
    int n;
    
    //Read the inputted value
    scanf("%d", &n);
    
    //Thread identifier
    pthread_t tid;
    
    //Create the thread
    pthread_create(&tid, NULL, isPrime,(void*)n);
    
    //Now wait for thread to exit
    pthread_join(tid, NULL);
    
    
}