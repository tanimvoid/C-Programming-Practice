// 12. Write a program to implement Producer-Consumer problem using semaphores.
// Platform: Linux

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#include <unistd.h>

int buf[5], in = 0, out = 0;
sem_t empty, full, mutex;

void *prod() {
    for (int i = 1; i <= 10; i++) {
        sem_wait(&empty); sem_wait(&mutex);
        buf[in] = i; printf("Produced %d\n", i);
        in = (in + 1) % 5;
        sem_post(&mutex); sem_post(&full);
        sleep(1);
    }
    return NULL;
}

void *cons() {
    int x;
    for (int i = 1; i <= 10; i++) {
        sem_wait(&full); sem_wait(&mutex);
        x = buf[out]; printf("Consumed %d\n", x);
        out = (out + 1) % 5;
        sem_post(&mutex); sem_post(&empty);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t p, c;
    sem_init(&empty, 0, 5); sem_init(&full, 0, 0); sem_init(&mutex, 0, 1);
    pthread_create(&p, NULL, prod, NULL);
    pthread_create(&c, NULL, cons, NULL);
    pthread_join(p, NULL); pthread_join(c, NULL);
    return 0;
}
