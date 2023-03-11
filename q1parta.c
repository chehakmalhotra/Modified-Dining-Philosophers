#include <stdio.h>

#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>


sem_t forks[5];


void dine(int i){
    printf("Philosopher % d is thinking\n", i);
    sem_wait(&forks[i]);
    sem_wait(&forks[(i + 1) % 5]);
    printf("Philosopher %d is eating\n",i);
    sleep(2);
    printf("Philosopher %d has finished eating\n",i);
    sem_post(&forks[i]);
    sem_post(&forks[(i + 1) % 5]);

}

int main() {

    for (int i = 0; i < 5; i++) {
        sem_init(&forks[i], 0, 1);
    }
    pthread_t thread_id[5];
    for (int i = 0; i < 5; i++) {
        pthread_create(&thread_id[i], NULL, (void *) dine, (int*)i);

    }

    for (int i = 0; i < 5; i++) {

        pthread_join(thread_id[i], NULL);
    }

    for (int i = 0; i < 5; i++) {
        sem_destroy(&forks[i]);


    }
}