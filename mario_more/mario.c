#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    // This do while loop takes care of getting a correct height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //This for loop takes care of the creation of the piramid
    for (int i = 0; i < height; i++)
    {
        //First part of the piramid
        for (int x = 0; x < height - (i + 1); x++)
        {
            printf(" ");
        }
        for (int x_1 = 0; x_1 < (i + 1); x_1++)
        {
            printf("#");
        }
        printf("  ");
        //Second part of the piramid
        for (int y = 0; y < (i + 1); y++)
        {
            printf("#");
        }
        printf("\n");
    }

}