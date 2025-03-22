#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    for (int i = 5; i >= 0; i -= 1) {
        printf("%d\n", i);
        sleep(1);
    }

    printf("%s\n", "Blast off");

    return 0;
}
