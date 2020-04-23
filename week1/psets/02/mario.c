/*
Mario, World 1-1

- Create pyramid of bricks using hashes (#)
- Prompt user for positive integer between 1 and 8, inclusive
- Repeat prompt if input not valid
- Right aligned
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (1 > n || n > 8);

    // increment starting at 1
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
