
#include <stdio.h>
#include <pthread.h>

void *calculate_square(void *arg) {
    int number = *(int *)arg;

    printf("Square of %d is %d\n", number, number * number);

    return NULL;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, calculate_square, &numbers[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All calculations completed.\n");

    return 0;
}

