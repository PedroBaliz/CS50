#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    string text = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int phrases = 0;

    for (int i = 0; text[i] != '\0'; i++)

    {

        if (isalpha(text[i]))
        {
            letters++;
        }

        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            phrases++;
        }
    }

    float l = ((float) letters / words) * 100;
    float s = ((float) phrases / words) * 100;

    float index = 0.0588 * l - 0.296 * s - 15.8;

    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf(" Grade %d\n", grade);
    }
}
