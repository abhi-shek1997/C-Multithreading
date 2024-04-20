#include <stdio.h>
#include <pthread.h>

void *compute(void *);

int main()
{
    pthread_t t1;
    pthread_t t2;

    long a = 1;
    long b = 2;

    pthread_create(&t1, NULL, compute, (void *) &a);
    pthread_create(&t2, NULL, compute, (void *) &b);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    return 0;
}

void *compute (void *num){
    long sum = 0;
    long *add_num = (long*)(num);

    for(int i=1; i<1000000000; i++){
        sum = sum + *add_num;
    }
    return NULL;
}