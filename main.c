#include <stdio.h>

int main(){
    while(1) {



        char choice;
        printf("Play again? (y/n)\n");
        scanf(" %c",&choice); //leading space to ignore space, /t, /n...
        if (choice == 'n') break;
    }
    return 0;
}
