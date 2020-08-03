//
//  main.c
//  more_or_less
//
//  Created by Mathieu Seligmann on 28/07/2020.
//  Copyright © 2020 Mathieu Seligmann. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int numberGeneration(const int MIN, const int MAX);
void level(void);
void game(const int MIN, const int MAX);
void newGame(void);
void multiplayer(int player);

int numberGeneration(const int MIN, const int MAX)
{
    srand((int)time(NULL));
    return ((rand()% (MAX + 1 - MIN)) + MIN);
}

void level(void)
{
    int level;
    
    printf("===================================\n");
    printf("                                   \n");
    printf("              GAME                 \n");
    printf("                                   \n");
    printf("Which level do you want to play ?  \n");
    printf("Press: 1 for Easy (1 to 10)        \n");
    printf("       2 for Medium (1 to 100)     \n");
    printf("       3 for Hard (1 to 1000)      \n");
    printf("                                   \n");
    printf("===================================\n");

    printf("Select your choice here --> ");
    scanf("%d", &level);
    printf("\n");
    
    switch (level)
     {
         case 1:
             game(1,10);
             break;
         case 2:
             game(1,100);
             break;
         case 3:
             game(1,1000);
             break;
         default:
             printf("Invalid key\n");
             break;
     }
}

void game(const int MIN, const int MAX)
{
    int mystery;
    bool go;
    int count = 0;
    go = true;
    mystery = numberGeneration(MIN,MAX);
  
    do
    {
        int choice;
        printf("Which is the correct number ? ");
        scanf("%d", &choice);
        ++count;
        printf("try %d", count);
       
        if(mystery>choice)
            printf("\t It is more \n\n");
        else if (mystery<choice)
            printf("\t It is less \n\n");
        else
        {
            printf("\t Congratulation ! In  %d times \n\n", count);
            go = false;
        }
    } while(go);
    newGame();
}

void newGame()
{
    bool again = true;
    int choice;
    while(again)
    {
        printf("Do you want to play a new game ? \n");
        printf("1 for yes, 0 for no \n");
        printf("Select your choice here --> ");
        scanf("%d", &choice);
        printf("\n");
        if (choice== 1)
            level();
        else
            again = false;
    }
}

void multiplayer(int player)
{
    for (int i = 0; i < player; i++)
    {
        printf("\nPlayer %d your turn ! Let's go ! \n", i + 1);
        level();
    }
}

int main(int argc, const char * argv[])
{
    
    int player = 0;
    
    printf("How many players ? Enter a number here --> ");
    scanf("%d", &player);
    multiplayer(player);
    printf("See you soon ! \n\n");
    
    return 0;
}
