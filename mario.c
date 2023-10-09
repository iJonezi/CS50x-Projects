#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get the height of bricks with a minimum and maximum amount.
    int height;
    int min = 1;
    int max = 8;
    do
    {
        height = get_int("Positive Number Between 0 and 8: ");
    }
    // if user provides height between 1 and 8, run true
    while (height < min || height > max);
    // Print bricks section
    // for each row, create a new line
    for (int row = 0; row < height; row++)
    {
        // for each row, except the last (which is the -1 part), add a blank space
        for (int space = 0; space < (height - row) - 1; space++)
        {
            printf(" ");
        }
        // for each row, add a # until the number of rows is met
        for (int line = -1; line < row; line++)
        {
            printf("#");
        }
        // after each line on the first pyramid, add 2 spaces
        printf("  ");
        // following the 2 spaces, make another #
        for (int line = -1; line < row; line++)
        {
            printf("#");
        }
        printf("\n");
    }
}