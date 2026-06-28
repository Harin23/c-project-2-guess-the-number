#include <stdio.h>

int ALLOWED_ATTEMPTS = 7;

int main(){
    while(1) {
        int random = 60;
        int guess;
        for (int i=0; i<ALLOWED_ATTEMPTS; i++) {
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
        scanf(" %c",&choice); //leading space to ignore space, /t, /n...
        if (choice == 'n') break;
    }
    return 0;
}
