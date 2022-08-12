#include <cs50.h>
#include <stdio.h>

int input(void);
void make(int height);

int main(void)
{
    int height = input(); // calling input function which user input
    make(height);         // calling make function which makes the pyramid

}
int input(void)
{
    int height = -1;
    do
    {
        height = get_int("Enter the height between 1-8: "); // taking user input
    }
    while (height <= 0 || height > 8);
    return height;                                          // returning input
}
void make(int height)
{
    int space;
    space = height;

    for (int i = 0 ; i < height ; i++)             // printing spaces
    {
        space--;
        for (int j = 0 ; j < space ; j++)
        {
            printf(" ");
        }
        for (int k = 0 ; k <= i ; k++)             // printing left side bricks
        {
            printf("#");
        }
        printf("  ");                              // printing space between sides
        for (int l = 0 ; l <= i ; l++)             // printing right side bricks
        {
            printf("#");
        }
        printf("\n");
    }
}