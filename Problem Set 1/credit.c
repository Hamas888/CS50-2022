#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long int number;
    int underlined, underlined_sum, non_underlined_sum, total_sum, identifier, digits;
    do
    {
        number = get_long("Number: ");  // taking user input
    }
    while (number <= 0);  // breaking and adding numbers
    for (int i = 0 ; number != 0 ; i++)
    {
        if (i % 2 != 0)  // multiplying underlined number by 2 and adding them
        {
            underlined = number % 10;
            underlined = underlined * 2;
            if (underlined > 9)  // if multiplied number greater then 9 breaking and adding it to total
            {
                underlined_sum = underlined_sum + underlined % 10;
                underlined_sum = underlined_sum + underlined / 10;
            }
            else
            {
                underlined_sum = underlined_sum + underlined;
            }
        }
        else
        {
            non_underlined_sum = non_underlined_sum + number % 10;  // adding non underlined numbers

        }
        number = number / 10;
        if (number >= 34  && number <= 55)
        {
            identifier = number;     // storing identifier for company first 2 digits
        }
        digits = i;  // storring total digits in the number

    }

    total_sum = underlined_sum + non_underlined_sum;
    if (digits >= 12 && digits <= 16 && total_sum % 10 == 0)  // checking for card type
    {
        if (identifier == 34 || identifier == 37)
        {
            printf("AMEX\n");
        }
        else if (identifier / 10 == 4)
        {
            printf("VISA\n");
        }
        else if (identifier <= 55 && identifier >= 51)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}