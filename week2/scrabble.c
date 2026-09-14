#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int score(char word[])

{
    int points[128] = {0};

    points['A'] = 1;
    points['B'] = 3;
    points['C'] = 3;
    points['D'] = 2;
    points['E'] = 1;
    points['F'] = 4;
    points['G'] = 2;
    points['H'] = 4;
    points['I'] = 1;
    points['J'] = 8;
    points['K'] = 5;
    points['L'] = 1;
    points['M'] = 3;
    points['N'] = 1;
    points['O'] = 1;
    points['P'] = 3;
    points['Q'] = 10;
    points['R'] = 1;
    points['S'] = 1;
    points['T'] = 1;
    points['U'] = 1;
    points['V'] = 4;
    points['W'] = 4;
    points['X'] = 8;
    points['Y'] = 4;
    points['Z'] = 10;

    int total = 0;

    for (int i = 0; i < strlen(word); i++)

    {

        char letra = toupper(word[i]);

        if (letra >= 'A' && letra <= 'Z')
            total += points[(int) letra];
    }

    return total;
}

int main(void)
{
    char word1[105];
    char word2[105];

    printf("Player 1: ");
    scanf("%s", word1);

    printf("Player 2: ");
    scanf("%s", word2);

    int score1 = score(word1);
    int score2 = score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}
