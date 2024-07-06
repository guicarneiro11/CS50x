#include <cs50.h>
#include <math.h>
#include <stdio.h>

bool is_valid(long number);
int get_length(long number);
bool check_luhn(long number);
void print_card_type(long number);

int main(void)
{
    long card_number = get_long("Número: ");

    if (is_valid(card_number))
    {
        print_card_type(card_number);
    }
    else
    {
        printf("INVALID\n");
    }
}
bool is_valid(long number)
{
    return check_luhn(number);
}
int get_length(long number)
{
    int length = 0;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

bool check_luhn(long number)
{
    int sum = 0;
    bool alternate = false;
    while (number > 0)
    {
        int digit = number % 10;
        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
        alternate = !alternate;
        number /= 10;
    }
    return (sum % 10 == 0);
}

void print_card_type(long number)
{
    int length = get_length(number);
    int first_digit = number / (long) pow(10, length - 1);
    int first_two_digits = number / (long) pow(10, length - 2);

    if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
