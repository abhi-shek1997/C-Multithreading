#include <stdio.h>
#include <pthread.h>

void *func_args(void*);

int main(){
    pthread_t t1;
    pthread_t t2;

    int a = 5;
    int b = 6;

    pthread_create(&t1, NULL, func_args, (void*) &a);
    pthread_create(&t2, NULL, func_args, (void*) &b);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    return 0;
}

void *func_args(void *num){
    int *new_num = (int*)(num);

    printf("Number is : %d\n", *new_num);
    return NULL;
}