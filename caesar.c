#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool digitcheck(string s);

int main(int argc, string argv[])
{ // if the command line has more than 1 argument, return usage code
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int j = 0; j < strlen(argv[1]); j++)
        {
            if (!isdigit(argv[1][j]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        if (digitcheck(argv[1]))
        {
            // get input from user
            string msg = get_string("plaintext: ");
            printf("ciphertext: ");
            // for every letter in the plaintext, rotate the letter by the key
            for (int i = 0; i < strlen(msg); i++)
            {
                int k = atoi(argv[1]);
                if (isupper(msg[i]))
                {
                    printf("%c", (msg[i] - 65 + k) % 26 + 65);
                }
                else if (islower(msg[i]))
                {
                    printf("%c", (msg[i] - 97 + k) % 26 + 97);
                }
                else
                {
                    printf("%c", msg[i]);
                }
            }
            printf("\n");
        }
    }
}

// function to check if command line is a digit
bool digitcheck(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]))
        {
            return true; // is digit
        }
        else
        {
            return false; // is not digit
        }
    }
    return 0;
}
