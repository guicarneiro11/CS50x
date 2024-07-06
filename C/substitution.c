#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_valid_key(string key);
char substitute(char c, string key);

int main(int argc, string argv[])
{
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Uso: ./substitution chave\n");
        return 1;
    }

    string key = argv[1];

    string plaintext = get_string("texto simples: ");

    printf("texto cifrado: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", substitute(plaintext[i], key));
    }

    printf("\n");

    return 0;
}

bool is_valid_key(string key)
{
    if (strlen(key) != 26)
    {
        printf("A chave deve conter 26 caracteres.\n");
        return false;
    }

    bool char_seen[26] = {false};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("A chave deve conter apenas caracteres alfabéticos.\n");
            return false;
        }
        int index = toupper(key[i]) - 'A';
        if (char_seen[index])
        {
            printf("A chave não deve conter caracteres repetidos.\n");
            return false;
        }
        char_seen[index] = true;
    }

    return true;
}

char substitute(char c, string key)
{
    if (isupper(c))
    {
        return toupper(key[c - 'A']);
    }
    else if (islower(c))
    {
        return tolower(key[c - 'a']);
    }
    else
    {
        return c;
    }
}
