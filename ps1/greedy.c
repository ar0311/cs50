#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    int coins = 0;

    printf("Enter the change needed:\n");

    do
    {
        change = GetFloat();
        if(change <= 0)
        {
            printf("Change entered must be positive:\n");
        }
    }
    while (change <= 0);

    int cents = roundf((change * 100));

    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }
    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }
    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }

    printf("%d\n",coins);
    
    return 0;

}


