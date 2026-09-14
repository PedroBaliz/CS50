#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int coins = 0;
    int cents;

    do
    {
        cents = get_int("cash:");
    }

    while (cents < 0);

    if (cents >= 25)

    {

        coins = coins + cents / 25;
        cents %= 25;
    }

    if (cents >= 10)

    {
        coins = coins + cents / 10;
        cents %= 10;
    }

    if (cents >= 5)

    {
        coins = coins + cents / 5;
        cents %= 5;
    }

    if (cents >= 1)

    {

        coins = coins + cents / 1;
        cents %= 1;
    }

    printf("Change owed:%d\n", coins);
}
