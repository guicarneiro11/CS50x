#include <stdio.h>

void printPyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main()
{
    int height = 8;
    printPyramid(height);
    return 0;
}
