#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int choice); // for ASCII value of snake water gun
void display(int choice)
{
    switch (choice)
    {
        //  0 for snake
        // 1 for water
        // 2 for gun

    case 0:
        printf("🐍 snake\n");
        break;
    case 1:
        printf("💧 water\n");
        break;
    case 2:    
        printf("🔫 Gun\n");
        break;
    default:
        printf("Invaild Choice\n");
    }
}
int displayMenu(); // for main menu
int displayMenu()
{
    int option;
    printf("\n====== MAIN MENU ======\n");
    printf("1. Play Player vs Computer\n");
    printf("2. Play Player vs Player\n");
    printf("3. View Rules\n");
    printf("4. Exit\n");
    printf("=======================\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    return option;
}
void display_rules(); // for rules
void display_rules()
{
    printf("\nRULES:\n");
    printf("Choose 0 for Snake 🐍\n");
    printf("Choose 1 for Water 💧\n");
    printf("Choose 2 for Gun 🔫\n");
    printf("- Snake 🐍 drinks Water 💧 and wins.\n");
    printf("- Water 💧 rusts Gun 🔫 and wins.\n");
    printf("- Gun 🔫 shoots Snake 🐍 and wins.\n");
    printf("- Same choices result in a Draw.\n");
}
void determinewinner(int player1, int player2); // for getting winner
void determinewinner(int player1, int player2)
{
    if (player1 == player2)
    {
        printf("Its a Draw \n");
    }
    else if ((player1 == 0 && player2 == 1) || // Snake drinks Water
             (player1 == 1 && player2 == 2) || // Water rusts Gun
             (player1 == 2 && player2 == 0))   // Gun shoots Snake
    {
        printf("Player1 Wins!\n");
    }
    else
    {
        printf("Player2 Wins!\n");
    }
}

void playgame(int);
void playgame(int mode)
{
    int player1, player2;
    char playAgain;
    do
    {
        if (mode == 1)
        { // Player vs Computer
            int computer = rand() % 3;

            // Get player input
            printf("\nPlayer, enter your choice (0 for Snake, 1 for Water, 2 for Gun): ");
            scanf("%d", &player1);
            if (player1 < 0 || player1 > 2)
            {
                printf("Invalid choice! Please choose 0, 1, or 2.\n");
                continue;
            }

            printf("You choose/n");
            display(player1);
            printf("Computer Choose \n");
            display(computer);
            determinewinner(player1, computer);
        }
        else if (mode == 2)
        { // Player vs Player
            // Get player 1 input
            printf("\nPlayer 1, enter your choice (0 for Snake, 1 for Water, 2 for Gun): ");
            scanf("%d", &player1);
            if (player1 < 0 || player1 > 2)
            {
                printf("Invalid choice! Please choose 0, 1, or 2.\n");
                continue;
            }

            // Get player 2 input
            printf("Player 2, enter your choice (0 for Snake, 1 for Water, 2 for Gun): ");
            scanf("%d", &player2);
            if (player2 < 0 || player2 > 2)
            {
                printf("Invalid choice! Please choose 0, 1, or 2.\n");
                continue;
            }
            printf("You choose/n");
            display(player1);
            printf("Computer Choose \n");
            display(player2);
            determinewinner(player1, player2);
        } // Ask if the user wants to play again
        printf("\nDo you want to play another round? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');
}
int main()
{
    srand(time(0));
    int option;
    while (1)
    {
        option = displayMenu();
        switch (option)
        {
        case 1:
            playgame(1);
            break;
        case 2:
            playgame(2);
            break;
        case 3:
            display_rules();
            break;
        case 4:
            printf("Exiting the game. Goodbye!\n");
            return 0;
        default:
            printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}