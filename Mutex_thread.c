#include <stdio.h>
#include <pthread.h>
#define NTHREADS 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;

void* mutex_func(){
    
        pthread_mutex_lock( &mutex );
        printf("Value incremented by Thread: %d is %d\n", pthread_self(),counter++);
        pthread_mutex_unlock (&mutex);

}

int main(){
    pthread_t thread_id[NTHREADS];
    for (int i=0; i<NTHREADS; i++){
        pthread_create(&thread_id[i],NULL,mutex_func,NULL);
    }
    for (int i=0; i<NTHREADS; i++){
        pthread_join(thread_id[i],NULL);
    }

    printf("Final value of counter is : %d\n",counter);
}