#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// Refrence string
string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Deciding the winner
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

int compute_score(string word)
{
    int l = strlen(word), p = 0;
    for (int i = 0 ; i < l ; i++)                            // for length of the word
    {
        for (int j = 0 ; j < 26 ; j++)
        {
            if (islower(word[i]) != 0)                       // checks if the character in word lower case
            {
                if (toupper(word[i]) == letters[j])          // converts to upper then compare
                {
                    p = p + points[j];
                }
            }
            else if (isupper(word[i]) != 0)                  // checks if the character is in upper case
            {
                if (word[i] == letters[j])                   // compare as it is to refrence
                {
                    p = p + points[j];
                }
            }
        }
    }
    return p;                                               // returns the total points
}
