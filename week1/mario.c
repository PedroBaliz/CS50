mario
#include <stdio.h>
int main(void)
{

    int height;
    // ask the height
    do
    {
        printf("Write the height (>=1 <=8):");
        scanf("%d", &height);
    }
    while (height < 1 || height > 8);

    // rows
    for (int i = 0; i < height; i++)

    {
        // space
        for (int s = 0; s < height - i - 1; s++)

        {

            printf(" ");
        }

        // columns
        for (int c = 0; c <= i; c++)

        {

            printf("#");
        }
        printf("\n");
    }
}
