#include <cs50.h>
#include <stdio.h>

/*
*   This function lets us know about the lenght
*   of the credit card.
*/
static int lenght_of_card(long long credit_number)
{
    int lenght;

    lenght = 0;
    while (credit_number > 0)
    {
        credit_number = credit_number / 10;
        lenght++;
    }
    return (lenght);
}

/*
*   This function checks the first digits to
*   indentify what type of card it is.
*/
char  *check_the_kind(long long credit_nbr, int nbr_lenght)
{
    char    *card_type;
    int     lenght;

    lenght = nbr_lenght - 2;
    while (lenght > 0)
    {
        credit_nbr = credit_nbr / 10;
        lenght--;
    }
    if (credit_nbr == 34 | credit_nbr == 37)
    {
        card_type = "AMEX";
    }
    else if (credit_nbr >= 40 & credit_nbr < 50)
    {
        card_type = "VISA";
    }
    else if (credit_nbr > 50 & credit_nbr < 56)
    {
        card_type = "MASTERCARD";
    }
    else
    {
        card_type = "INVALID";
    }
    return (card_type);
}

/*
*   This algorithm helps us to distingquish if the
*   card number is actually valid or invalid.
*/
char Luhn_algorithm(long long card_nbr, int nbr_lenght)
{
    int     decider;
    int     first_sum;
    int     second_sum;
    char    check;

    decider = 0;
    first_sum = 0;
    second_sum = 0;
    check = 'N';
    // Goes through all of the card number
    while (nbr_lenght > 0 && card_nbr != 0)
    {
        //  Uses the decider variable to decide which sort of
        //  actions to perform. Either for the every second number or not.
        if (decider == 0)
        {
            second_sum += (card_nbr % 10);
            decider = 1;
        }
        else
        {
            decider = (card_nbr % 10) * 2;
            if (decider > 9)
            {
                first_sum += decider % 10;
                first_sum += decider / 10;
            }
            else
            {
                first_sum += decider;
            }
            decider = 0;
        }
        card_nbr = card_nbr / 10;
        nbr_lenght--;
    }
    // Checks if the number has the 0 at the end in which case
    // The card number is actually valid.
    if ((second_sum + first_sum) % 10 == 0)
    {
        check = 'Y';
    }
    return (check);
}


//Main combines all of the functions together in order
// to give the correct answer.
int main(void)
{
    long long credit_number;
    int       nbr_lenght;
    char      *type;

    // Asks for the card number
    do
    {
        credit_number = get_long("Number: ");
    }
    while (credit_number <= 0);
    // Checking the lenght of the card number
    nbr_lenght = lenght_of_card(credit_number);
    // Checking the kind of the credit card number
    if (nbr_lenght == 13 || nbr_lenght == 16)
    {
        type = check_the_kind(credit_number, nbr_lenght);
    }
    else if (nbr_lenght == 15)
    {
        type = check_the_kind(credit_number, 15);
    }
    else
    {
        printf("INVALID\n");
        return (0);
    }
    // Checking if the actual credit card number is correct or not
    if (Luhn_algorithm(credit_number, nbr_lenght) == 'N')
    {
        printf("INVALID\n");
        return (0);
    }

    printf("card %s\n", type);
    return (0);
}