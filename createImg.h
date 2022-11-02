#include <stdio.h>

typedef struct Array2d
{
    int width, height, *data;
} array2d;

typedef struct Image
{
    char *image_name;
    int scale;
    array2d raw;
} image;

void writeImg(image img)
{
    FILE *pgmimg = fopen(img.image_name, "wb");
    array2d raw = img.raw;
    int width = raw.width, height = raw.height;

    fprintf(pgmimg, "P2\n%d %d\n%d\n", width, height, img.scale);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fprintf(pgmimg, "%d ", *((raw.data + i * height) + j));
        }
        fprintf(pgmimg, "\n");
    }

    fclose(pgmimg);
}