#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void *thread_func(){
    printf("Hello from the thread \n");
    sleep(5);

    printf("Bye from the thread \n");
    return NULL;
}

int main(){
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1,NULL,&thread_func,NULL);
    pthread_create(&t2,NULL,&thread_func,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Bye from the main thread \n");

    return 0;

}
