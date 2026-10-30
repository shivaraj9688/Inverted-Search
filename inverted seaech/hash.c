#include "inverted_Search.h"

int hash_function(const char *word)
{
    char ch;

    ch = tolower(word[0]);

    if(ch >= 'a' && ch <= 'z')
    {
        return ch - 'a';
    }

    return 26;
}