#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    char    message[1000];
    printf("Message: ");
    fgets(message, sizeof(message), stdin);
    for (int i = 0; message[i] != '\n'; i++)
    {
        for (int c = 7; c >= 0; c--)
        {
            print_bulb((message[i] >> c) % 2);
        }
        printf("\n");
    }
    return (0);
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
