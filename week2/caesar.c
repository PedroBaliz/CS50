#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = 0;
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        k = k * 10 + (argv[1][i] - '0');
    }

    string text = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; text[i] != '\0'; i++)

    {

        char c = text[i];

        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            c = ((c - base + k) % 26) + base;
        }

        printf("%c", c);
    }

    printf("\n");
    return 0;
}
