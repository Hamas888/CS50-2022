#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include<math.h>

int main(void)
{
    string text;
    int cha = 0, wor = 1, sen = 0;      // for characters, words, and sentences
    float grade;                        // because the formula gives out floating point value
    do
    {
        text = get_string("Text: ");    // taking input
    }
    while (strlen(text) == 0);
    int l = strlen(text);
    for (int i = 0 ; i < l ; i++)
    {
        if (text[i] == ' ')             // finding number of words
        {
            wor++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')    // finding number of sentences
        {
            sen++;
        }
        else if (text[i] != '\'' && text[i] != ',' && text[i] != '"')   // finding number of characters
        {
            cha++;
        }
    }
    grade = 0.0588 * (cha / (float)wor * 100) - 0.296 * (sen / (float)wor * 100) - 15.8;   // finding grade
    if (grade < 0)    // if grade in negative
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (grade > 16)  // if grade grater then 16
    {
        printf("Grade 16+\n");
        return 0;
    }
    printf("Grade %i\n", (int)round(grade)); // rounding the grade and printing as integer
}