#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALLOWED_ATTEMPTS 7

int getRandomFallback(void) {
    int secret = (rand() % 100) + 1;
    printf("Using fallback");
    return secret;
}

int getRandom(void) {
    FILE *pointer_file = fopen("/dev/urandom", "rb");
    if (pointer_file == NULL) return getRandomFallback();

    uint8_t raw;
    size_t got = fread(&raw, sizeof(raw), 1, pointer_file);
    fclose(pointer_file);
    if (got != 1) return getRandomFallback();
    return ((raw - (raw > 200 ? raw - 200 : 0)) % 100) + 1;
}

int main() {
    srand((unsigned) time(NULL));

    while (1) {
        int random = getRandom();
        printf("%d\n", random);
        int guess;
        for (int i = 0; i < ALLOWED_ATTEMPTS; i++) {
            printf("Provide a guess for integer between 1-100 inclusive:\n");
            scanf("%d", &guess);

            if (guess > random) printf("Too high\n");
            else if (guess < random) printf("Too low\n");
            else break;
        }

        if (guess == random) printf("You win!\n");
        else printf("You lose! Correct answer was %d\n", random);

        char choice;
        printf("Play again? (y/n)\n");
        scanf(" %c", &choice); //leading space to ignore space, /t, /n...
        if (choice == 'n') break;
    }
    return 0;
}
