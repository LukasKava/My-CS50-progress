#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int amount_of_cents;

    do
    {
        amount_of_cents = get_int("Change owned: ");
    }
    while (amount_of_cents < 0);
    return (amount_of_cents);
}

int calculate_quarters(int cents)
{
    int quarters;

    quarters = 0;
    while (cents >= 25)
    {
        cents -= 25;
        quarters++;
    }
    return (quarters);
}

int calculate_dimes(int cents)
{
    // Calculate how many dimes should the cashier give
    int  dimes;

    dimes = 0;
    while (cents >= 10)
    {
        cents -= 10;
        dimes++;
    }
    return (dimes);
}

int calculate_nickels(int cents)
{
    // Calculate how many nickels should cashier give
    int nickels;

    nickels = 0;
    while (cents >= 5)
    {
        cents -= 5;
        nickels++;
    }
    return (nickels);
}

int calculate_pennies(int cents)
{
    // Calculate how many pennies should cashier give
    int pennies;

    pennies = 0;
    while (cents >= 1)
    {
        cents -= 1;
        pennies++;
    }
    return (pennies);
}
