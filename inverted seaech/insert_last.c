#include "inverted_Search.h"

extern char *file_name;

int insert_at_last(Wlist **head, data_t *data)
{
    Wlist *new;
    Wlist *temp;

    new = malloc(sizeof(Wlist));

    if(new == NULL)
    {
        return FAILURE;
    }

    new->file_count = 1;

    strcpy(new->word, data);

    new->Tlink = NULL;
    new->link = NULL;

    update_link_table(new, file_name);

    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    temp = *head;

    while(temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = new;

    return SUCCESS;
}