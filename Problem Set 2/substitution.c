#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check(int l, string s);  // to check invalid arguments
string input(void);          // to capture user input
void cipher(string s, string key);  // to cipher the input

int main(int argc, string argv[])
{
    int error = check(argc, argv[1]);
    if (error != 0)          // handling errors
    {
        return 1;
    }
    string text = input();           // taking input
    cipher(text, argv[1]);           // passing the valid key and input to cipher function
}

int check(int l, string s)
{
    if (l < 2 || l > 2)  // checking for proper arguments
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(s) < 26)  // checking key contain 26 characters
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0 ; i < 26 ; i++)  // checking if there any invalid or duplicate chracter in key
    {
        if ((s[i] <= 90 && s[i] >= 65) || (s[i] <= 122 && s[i] >= 97))
        {
            for (int j = i + 1 ; j < 26 ; j++)
            {
                if (s[i] == s[j])
                {
                    return 1;
                }
            }
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

string input(void)
{
    string text;
    do
    {
        text = get_string("plaintext: ");           // simple input
    }
    while (strlen(text) == 0);
    return text;
}

void cipher(string s, string key)
{
    int l = strlen(s);                             // findling length of input
    string lower = "abcdefghijklmnopqrstuvwxyz";   // refrence strings
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char temp;
    for (int i = 0 ; i < l ; i++)
    {
        if (islower(s[i]) != 0)                    // checking if character is lower
        {
            for (int j = 0 ; j < 26 ; j++)
            {
                if (s[i] == lower[j])              // matching to refrence
                {
                    if (islower(key[j]) != 0)      // encrypting the character
                    {
                        s[i] = key[j];
                    }
                    else
                    {
                        s[i] = tolower(key[j]);
                    }
                    break;
                }
            }
        }
        else                                       // in case the character is upper case
        {
            for (int k = 0 ; k < 26 ; k++)
            {
                if (s[i] == upper[k])
                {
                    if (islower(key[k]) != 0)
                    {
                        s[i] = toupper(key[k]);
                    }
                    else
                    {
                        s[i] = key[k];
                    }
                    break;
                }
            }
        }
    }
    printf("ciphertext: %s\n", s);  // printing the cipher
}