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
    long incoming=(long) arg;
    
    //Create a dynamic array
    bool *A=(bool*)malloc(incoming*sizeof(bool));
    
    //Let A be an array of Boolean values indexed by integers 2 to n intially all set to true
    for(int s=2;s<=incoming;s++)
    {
        A[s]=true;
    }
    
    //Variable to compute the square root of incoming (the value the user inputted):
    int a=sqrt(incoming);
    
    //Loop for performing Sieve of Eratosthenes algorithm
    for(int i=2; i<=a;i++)
    {
        if(A[i]==1)
        {
            for(int j=2;j*i<=incoming;j++)
            {
                A[j*i]=false;
            }
        }
        
    }
    
    
    printf("The prime values upto %ld are:\n", incoming);
    
    //Loop for printing all i such that A[i] is true:
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
    printf("Please enter a number greter than one that you would like to calculate the prime numbers upto:\n");
    
    //Variable to store the user inputted value
    long n;
    
    //Variable for pthread_create
    int rc;
    
    //Read the inputted value
    scanf("%ld", &n);
    
    //Checks if the input entered by user is greater than one, if not then requests user to try again until they input a value greater than one for the algorithm Sieve of Eratosthenes to work.
    while(n<=1)
    {
        printf("The number you entered is not greater than one please try again: ");
        scanf("%ld",&n);
        
    }
    
    //Thread identifier
    pthread_t tid;
    
    //Create the thread
    rc=pthread_create(&tid, NULL, isPrime,(void*)n);
    
    //Now wait for thread to exit
    pthread_join(tid, NULL);
    
    //Exit main thread
    pthread_exit(0);
    
}
