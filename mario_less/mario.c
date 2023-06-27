#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int  height;

    //do while loop takes care of passing only the
    //arguments that are >= 1 && <=8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //First for loop takes care of printinf the height
    //Second for loop takes care that there would be
    //  the correct amount of spaces
    //The third for loop takes care of printing the hashes
    for (int i = 0; i < height; i++)
    {
        for (int x = 0; x < height - (i + 1); x++)
        {
            printf(" ");
        }
        for (int y = 0; y < (i + 1); y++)
        {
            printf("#");
        }
        printf("\n");
    }

}