#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./speller dictionary text\n");
        return 1;
    }

    char *dictionary = argv[1];
    char *text = argv[2];

    if (!load(dictionary))
    {
        printf("Could not load %s\n", dictionary);
        return 1;
    }

    FILE *file = fopen(text, "r");
    if (file == NULL)
    {
        printf("Could not open %s\n", text);
        unload();
        return 1;
    }

    printf("\nMISSPELLED WORDS\n\n");

    char word[LENGTH + 1];
    int index = 0;
    int misspellings = 0;
    int words = 0;
    char c;

    while (fread(&c, sizeof(char), 1, file))
    {
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            if (index < LENGTH)
            {
                word[index++] = c;
            }
        }
        else if (index > 0)
        {
            word[index] = '\0';
            words++;

            if (!check(word))
            {
                printf("%s\n", word);
                misspellings++;
            }

            index = 0;
        }
    }

    fclose(file);

    unload();

    printf("\nWORDS MISSPELLED: %d\n", misspellings);
    printf("WORDS IN TEXT: %d\n", words);

    return 0;
}
