#include <stdio.h>
#include <pthread.h>

void* thread_func();

int main(){
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    return 0;
}
void* thread_func(){
    printf("Hello from the thread\n");
    Sleep(5000);
    printf("Bye from the thread\n");
}