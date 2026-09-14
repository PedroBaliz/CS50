#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 1. checar uso
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // 2. abrir arquivo
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    // 3. buffer de 512 bytes
    uint8_t buffer[512];

    FILE *img = NULL;
    int file_count = 0;
    char filename[8];

    // 4. ler até acabar arquivo
    while (fread(buffer, 1, 512, card) == 512)
    {
        // verificar se é início de JPEG
        int is_jpeg = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
                      (buffer[3] & 0xf0) == 0xe0;

        if (is_jpeg)
        {
            // fechar arquivo anterior
            if (img != NULL)
            {
                fclose(img);
            }

            // criar novo arquivo
            sprintf(filename, "%03i.jpg", file_count++);
            img = fopen(filename, "w");
        }

        // se já começou um JPEG, escreve
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // fechar arquivos
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
    return 0;
}
