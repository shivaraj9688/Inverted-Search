#include "inverted_Search.h"

int update_link_table(Wlist *head, char *filename)
{
    Ltable *new;

    new = malloc(sizeof(Ltable));

    if(new == NULL)
    {
        return FAILURE;
    }

    new->word_count = 1;

    strcpy(new->file_name, filename);

    new->table_link = NULL;

    head->Tlink = new;

    return SUCCESS;
}