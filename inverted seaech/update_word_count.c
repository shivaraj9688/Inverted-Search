#include "inverted_Search.h"

int update_word_count(Wlist *head, char *filename)
{
    Ltable *temp = head->Tlink;
    Ltable *new;

    while(temp != NULL)
    {
        if(strcmp(temp->file_name, filename) == 0)
        {
            temp->word_count++;
            return SUCCESS;
        }

        temp = temp->table_link;
    }

    new = malloc(sizeof(Ltable));

    if(new == NULL)
    {
        return FAILURE;
    }

    new->word_count = 1;
    strcpy(new->file_name, filename);
    new->table_link = NULL;

    head->file_count++;

    if(head->Tlink == NULL)
    {
        head->Tlink = new;
    }
    else
    {
        temp = head->Tlink;

        while(temp->table_link != NULL)
        {
            temp = temp->table_link;
        }

        temp->table_link = new;
    }

    return SUCCESS;
}