#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int rng(int max, int min);

int main() {
    int max = 100;
    int min = 0;
    int randomnum = rng(max, min);
    int input;
    int attempts = 0;
    bool guessed = false;

    printf("Guess a number between %d and %d.\n", min, max);

    while (!guessed) {
        printf("Attempt %d: \n", attempts);
        scanf("%d", &input);


        if (input > randomnum) {
            printf("lower...\n");
            attempts++;
        } else if (input < randomnum) {
            printf("higher...\n");
            attempts++;
        } else if (input == randomnum) {
            guessed = true;
            printf("Congrats! You guessed it in %d attempts.\n", attempts);
        }
    }


    return 0;
}

int rng(int max, int min) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}
