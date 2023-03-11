#include <stdio.h>

#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>


int forks[5] = {1,1,1,1,1};


void dine(int i){
    printf("Philosopher % d is thinking\n", i);
    forks[i] = 0;
    forks[(i+1)%5] = 0;
    printf("Philosopher %d is eating\n",i);
    sleep(2);
    printf("Philosopher %d has finished eating\n",i);
    forks[i] = 1;
    forks[(i+1)%5] = 1;
}

int main() {


    pthread_t thread_id[5];

    pthread_create(&thread_id[1], NULL, (void *) dine, (int*)1);
    pthread_join(thread_id[1], NULL);
    pthread_create(&thread_id[3], NULL, (void *) dine, (int*)3);
    pthread_join(thread_id[3], NULL);
    pthread_create(&thread_id[2], NULL, (void *) dine, (int*)2);
    pthread_join(thread_id[2], NULL);
    pthread_create(&thread_id[4], NULL, (void *) dine, (int*)4);
    pthread_join(thread_id[4], NULL);
    pthread_create(&thread_id[5], NULL, (void *) dine, (int*)5);
    pthread_join(thread_id[5], NULL);







}

