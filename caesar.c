#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    //Program accepts only one command-line argument
    if (argc != 2)
    {
        printf("error: Please provide one (only) command-line argument\n");
        return 1;
    }

    //Program accepts only integers as command line arguments
    if ((only_digits(argv[1]) == false))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Converting argv[1] from string to int
    int key = atoi(argv[1]);

    //Program accepts only positive integers as key
    if (key <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Prompt user for text
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    //Cipher text
    char ciphertext;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        ciphertext = rotate(plaintext[i], key);

        //Output ciphertext
        printf("%c", ciphertext);
    }

    printf("\n");
}


//Function to check wether string is an integer
bool only_digits(string s)
{
    bool digit;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]))
        {
            digit = true;
        }
        else
        {
            digit = false;
        }
    }
    return digit;
}


//Function to rotate characters
char rotate(char c, int n)
{
    char ciphercharacter;
    if (c >= 'A' && c <= 'Z')
    {
        ciphercharacter = c + n % 26;
        if (c + n % 26 > 'Z')
        {
            ciphercharacter = (c + n % 26) - 26;
        }
    }
    else if (c >= 'a' && c <= 'z')
    {
        ciphercharacter = c + n % 26;
        if (c + n % 26 > 'z')
        {
            ciphercharacter = (c + n % 26) - 26;
        }
    }
    else
    {
        ciphercharacter = c;
    }
    return ciphercharacter;
}

