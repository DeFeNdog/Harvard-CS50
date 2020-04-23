/*
Credit
*/

#include <math.h>
#include <cs50.h>
#include <stdio.h>

string card_valid_check(long n);

int main(void)
{
    long input = get_long("Number: ");
    printf("%s\n", card_valid_check(input));
}

string card_valid_check(long n)
{

    int len, digit, m, first_one, first_two, sum, mod;
    int i = 0, even = 0, odd = 0;
    string card_type = "INVALID";

    // check card length
    len = log10(n) + 1;
    if (13 > len || len == 14 || len > 16)
    {
        return card_type;
    }

    // starting digits
    first_one = n / pow(10, len - 1);
    first_two = n / pow(10, len - 2);

    // loop through digits in credit card number, starting at 1
    for (i = 1; i < len + 1; i++)
    {

        digit = n % 10;
        n = n / 10;

        if (i % 2 == 0)
        {

            // even index

            m = digit * 2;

            // product is 2+ digits
            if (m >= 10)
            {
                int l = log10(m) + 1;
                int e = 0, d = 0, j = 0;

                // loop through digits of product
                for (j = 1; j < l + 1; j++)
                {
                    d = m % 10;
                    m = m / 10;
                    e += d;
                }
                even += e;
            }
            else
            {
                even += m;
            }
        }
        else
        {

            // odd index
            odd += digit;
        }
    }

    sum = even + odd;
    mod = sum % 10;
    if (mod == 0)
    {
        // valid checksum

        // AMEX
        if (len == 15 && (first_two == 34 || first_two == 37))
        {
            card_type = "AMEX";
        }
        // MASTERCARD
        if (len == 16 && (first_two == 51 || first_two == 52 || first_two == 53 || first_two == 54 || first_two == 55))
        {
            card_type = "MASTERCARD";
        }
        // VISA
        if (first_one == 4 && (len == 13 || len == 16))
        {
            card_type = "VISA";
        }
    }

    return card_type;
}