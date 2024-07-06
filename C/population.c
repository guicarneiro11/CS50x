#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size;
    int end_size;
    int years = 0;

    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    int population = start_size;
    while (population < end_size)
    {
        int born = population / 3;
        int passed_away = population / 4;
        population += born - passed_away;
        years++;
    }

    printf("Years: %i\n", years);
}
