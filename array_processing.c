
#include <stdio.h>
#include <pthread.h>

int arr[] = {10, 20, 30, 40, 50, 60};

typedef struct {
    int start;
    int end;
    int id;
} ThreadData;

void *calculate_sum(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int sum = 0;

    for (int i = data->start; i < data->end; i++) {
        sum += arr[i];
    }

    printf("Thread %d: Partial sum = %d\n", data->id, sum);

    return NULL;
}

int main() {
    pthread_t threads[2];

    ThreadData data[2] = {
        {0, 3, 1},
        {3, 6, 2}
    };

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, calculate_sum, &data[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
