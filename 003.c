//
//  003.c
//  C
//
//  Created by Kevin Kiss on 22/03/2025.
//  Compares guessing systems

// binary search: splits in half the guessing range each time. max 7 guesses for 100 i think
// brute search : guesses every number max n guesses

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int compare(int input, int correct);
int rng(int max, int min);
int binarySearch(int max, int min, int correct);
int linearSearch(int max, int min, int correct);
int bogoSearch(int max, int min, int correct);
int expoSearch(int max, int min, int correct);

int main(void) {
    srand(time(NULL));
    
    // a * sizeof(int) a = length of array
    int mx = 1000000;
    int mn = 0;
    int randnum = rng(mx, mn);
    
    printf("Out of %d numbers...\n", mx);
    printf("Binary Search took %d guesses.\n", binarySearch(mx, mn, randnum));
    printf("Bogo   Search took %d guesses.\n", bogoSearch(mx, mn, randnum));
    printf("Linear Search took %d guesses.\n", linearSearch(mx, mn, randnum));
    printf("Expo   Search took %d guesses.\n", expoSearch(mx, mn, randnum));
    
    return 0;
}


int compare(int input, int correct){
   if (input > correct) {
       return -1;
   } else if (input == correct) {
       return 0;
   } else if (input < correct) {
       return 1;
   } else {
       return 2;
   }
} int rng(int max, int min) {
    return rand() % (max - min + 1) + min;
} int binarySearch(int max, int min, int correct) {
    int *guesses = malloc(1 * sizeof(int));
    int size = 1;
    int localMax = max;
    int localMin = min;
    int output = 0;
    bool guessed = false;
    
    int i = 0;
    while (!guessed) {
        guesses = realloc(guesses, (size + 1) * sizeof(int));
        guesses[i] = ((localMax - localMin) / 2) + localMin;
        size++;
        
        output = compare(guesses[i], correct);
        
        if (output == -1) {
            localMax = guesses[i];
        } else if (output == 1) {
            localMin = guesses[i];
        } else if (output == 0) {
            guessed = true;
        }
        
        i++;
    }
    free(guesses);
    return i;
} int bogoSearch(int max, int min, int correct) {
    int *guesses = malloc(1 * sizeof(int));
    int size = 1;
    int localMax = max;
    int localMin = min;
    int output = 0;
    bool guessed = false;
    
    int i = 0;
    while (!guessed) {
        guesses = realloc(guesses, (size + 1) * sizeof(int));
        guesses[i] = rng(localMax, localMin);
        size++;
        
        output = compare(guesses[i], correct);
        
        if (output == 0) {
            guessed = true;
        }
        
        i++;
    }
    free(guesses);
    return i;
} int linearSearch(int max, int min, int correct) {
    int *guesses = malloc(1 * sizeof(int));
    int size = 1;
    int localMax = max;
    int localMin = min;
    int output = 0;
    bool guessed = false;
    
    int i = 0;
    while (!guessed) {
        guesses = realloc(guesses, (size + 1) * sizeof(int));
        guesses[i] = i;
        size++;
        
        output = compare(guesses[i], correct);
        
        if (output == 0) {
            guessed = true;
        }
        
        i++;
    }
    free(guesses);
    return i;
} int expoSearch(int max, int min, int correct) {
    int *guesses = malloc(1 * sizeof(int));
    int size = 1;
    int localMax = max;
    int localMin = min;
    int output = 0;
    bool guessed = false;
    bool binarymode = false;
    
    int i = 0;
    while (!guessed) {
        guesses = realloc(guesses, (size + 1) * sizeof(int));
        //guesses[i] = i;
        if (size == 1) {
            guesses[i] = 1;
        } else if ((size != 1) && (!binarymode)) {
            guesses[i] = (1 << guesses[i - 1]);
        } else {
            guesses[i] = ((localMax - localMin) / 2) + localMin;
        }
        size++;
        
        
        
        output = compare(guesses[i], correct);
        
        if (output == -1) {
            localMax = guesses[i];
        } else if (output == 1) {
            localMin = guesses[i];
            binarymode = true;
        } else if (output == 0) {
            guessed = true;
        }
        
        i++;
    }
    free(guesses);
    return i;
}
