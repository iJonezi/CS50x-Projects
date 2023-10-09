#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // getting the card number from user
    long cardnumber;
    cardnumber = get_long("What is the card number?: ");
    if (cardnumber <= 40000000000 || cardnumber > 5599999999999999)
    {
        // invalid card if not within parameters
        printf("INVALID\n");
        return 0;
    }
    else
    {
        int sum1 = 0;
        int sum2 = 0;
        long x = cardnumber;
        int total = 0;
        int mod1;
        int mod2;
        int d1;
        int d2;

        do
        {
            // Remove last digit and add to sum1
            mod1 = x % 10;
            x = x / 10;
            sum1 = sum1 + mod1;
            // Remove second last digit
            mod2 = x % 10;
            x = x / 10;
            // Double second last digit and add digits to sum2
            mod2 = mod2 * 2;
            d1 = mod2 % 10;
            d2 = mod2 / 10;
            sum2 = sum2 + d1 + d2;
        } while (x > 0);
        total = sum1 + sum2;

        if (total % 10 != 0)
        {
            printf("INVALID\n");
            return 0;
        }
        else
        {
            int length = 0;
            long visa = cardnumber;
            long amex = cardnumber;
            long master = cardnumber;

            while (cardnumber > 0)
            {
                cardnumber = cardnumber / 10;
                length++;
            }
            // VISA check
            while (visa >= 10)
            {
                visa /= 10;
            }
            if (visa == 4 && (length == 13 || length == 16))
            {
                printf("Number: %li\n", visa);
                printf("VISA\n");
                return 0;
            }
            else
                // amex check
                while (amex >= 10000000000000)
                {
                    amex /= 10000000000000;
                }
            if (length == 15 && (amex == 34 || amex == 37))
            {
                printf("Number: %li\n", amex);
                printf("AMEX\n");
                return 0;
            }
            else
                // master check
                while (master >= 100000000000000)
                {
                    master /= 100000000000000;
                }
            if ((master == 51 || master == 52 || master == 53 || master == 54 || master == 55) && length == 16)
            {
                printf("Number: %li\n", master);
                printf("MASTERCARD\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
    }
}
