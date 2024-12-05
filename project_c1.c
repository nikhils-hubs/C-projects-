#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 0 and 100
    int randomNumber = rand() % 101;
    int number_of_guesses=0;
    int guessed_number;
    do
    {
        printf("guess the number\n");
        scanf("%d",&guessed_number);
        if (guessed_number>randomNumber)    
        {
            printf("Lower number please!\n");
        }else if(guessed_number>randomNumber){
            printf("Higher number please!\n");
        }else{
            printf("Congrats You Guessed A number\n");
        }
        number_of_guesses++;

    } while (guessed_number != randomNumber);
    printf("Your score is:%d\n",number_of_guesses);
    

    
    

    return 0;
}
