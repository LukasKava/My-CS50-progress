#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_population_size = 0;
    int end_population_size = 0;

    while (start_population_size < 9)
    {
        printf("Enter the start size of population: ");
        scanf("%i", &start_population_size);
    }
    // TODO: Prompt for end size
    while (end_population_size < start_population_size)
    {
        printf("Enter the end size of population: ");
        scanf("%i", &end_population_size);
    }

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    int tmp_population_size = 0;
    while (start_population_size < end_population_size)
    {
        tmp_population_size = start_population_size;
        start_population_size += (tmp_population_size / 3);
        start_population_size -= (tmp_population_size / 4);
        years++;
    }
    // TODO: Print number of years
    printf("Years: %d\n", years);
    return (0);
}
