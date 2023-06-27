#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Checking if there are two arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    int i = 0;
    //Checking if the second argument is a digit
    while (argv[1][i] != '\0')
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return (1);
        }
        i++;
    }
    i = 0;
    //Converting the key to the number
    int key = atoi(argv[1]);
    char *text = get_string("plaintext:  ");
    //While loop takes care of shifting the letters according
    //to the Caesers cipher.
    while (text[i] != '\0')
    {
        if (isalpha(text[i]) != 0 && isupper(text[i]) != 0)
        {
            text[i] = ((text[i] + key - 'A') % 26) + 'A';
        }
        else if (isalpha(text[i]) != 0 && islower(text[i]) != 0)
        {
            text[i] = ((text[i] + key - 'a') % 26) + 'a';
        }
        i++;
    }
    //Printing out the final product
    printf("ciphertext: %s\n", text);
    return (0);
}