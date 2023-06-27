#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Takes care that there are only two
    //passed in to the function.
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return (1);
    }
    int i =  0;
    //Counts how many characters there are and if its
    //a correct ammount.
    while (argv[1][i] != '\0')
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return (1);
        }
        i++;
    }
    if (i != 26)
    {
        printf("Key must contain 26 characters.\n");
        return (1);
    }
    i = 0;
    int x = 1;
    while (argv[1][i] != '\0')
    {
        while (argv[1][x] != '\0')
        {
            if (argv[1][i] == argv[1][x])
            {
                printf("Key must not contain repeated characters.\n");
                return (1);
            }
            x++;
        }
        i++;
        x = i + 1;
    }
    //Gets the string that needs to be ciphered.
    i = 0;
    int position = 0;
    char    *text = get_string("plaintext:  ");
    //While loop takes care of matching and converting
    //characters to its correct replacaments.
    while (text[i] != '\0')
    {
        if (isalpha(text[i]) != 0 && isupper(text[i]) != 0)
        {
            position = text[i] - 'A';
            //This makes sure that if the current char is upper but
            //the key letter is lowercase it will be converted to upper.
            if (isupper(argv[1][position]) == 0)
            {
                text[i] = toupper(argv[1][position]);
            }
            else
            {
                text[i] = argv[1][position];
            }
        }
        else if (isalpha(text[i]) != 0 && islower(text[i]) != 0)
        {
            position = text[i] - 'a';
            if (isupper(argv[1][position]) != 0)
            {
                text[i] = tolower(argv[1][position]);
            }
            else
            {
                text[i] = argv[1][position];
            }
        }
        i++;
    }
    //Printing out the result.
    printf("ciphertext:  %s\n", text);
    return (0);
}