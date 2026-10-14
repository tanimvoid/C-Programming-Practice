// 11. Write a program to implement reader/writer problem using semaphore.
// Platform: Linux

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t wrt, mutex;
int data = 0, rc = 0;

void *reader(void *id) {
    sem_wait(&mutex);
    if (++rc == 1) sem_wait(&wrt);
    sem_post(&mutex);

    printf("Reader %d reads %d\n", *(int*)id, data);
    sleep(1);

    sem_wait(&mutex);
    if (--rc == 0) sem_post(&wrt);
    sem_post(&mutex);
    return NULL;
}

void *writer(void *id) {
    sem_wait(&wrt);
    data++;
    printf("Writer %d writes %d\n", *(int*)id, data);
    sleep(1);
    sem_post(&wrt);
    return NULL;
}

int main() {
    pthread_t r[3], w[2];
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);
    int id[] = {1, 2, 3};

    pthread_create(&w[0], NULL, writer, &id[0]);
    pthread_create(&r[0], NULL, reader, &id[0]);
    pthread_create(&r[1], NULL, reader, &id[1]);
    pthread_create(&w[1], NULL, writer, &id[1]);
    pthread_create(&r[2], NULL, reader, &id[2]);

    for (int i = 0; i < 3; i++) pthread_join(r[i], NULL);
    for (int i = 0; i < 2; i++) pthread_join(w[i], NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}
