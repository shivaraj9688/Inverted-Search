#include "inverted_Search.h"

char *file_name;

void create_database(Flist *f_head, Wlist *head[])
{
    while(f_head != NULL)
    {
        printf("\nReading file : %s\n", f_head->file_name);

        read_datafile(head, f_head->file_name);

        f_head = f_head->link;
    }

    printf("\nDatabase created successfully\n");
}


int read_datafile(Wlist *head[], char *filename)
{
    FILE *fptr;
    char word[WORD_SIZE];

    fptr = fopen(filename, "r");

    if(fptr == NULL)
    {
        printf("Unable to open file %s\n", filename);
        return FAILURE;
    }

    file_name = filename;

    while(fscanf(fptr, "%49s", word) == 1)
    {
        int index;
        int flag = 1;

        Wlist *temp;

        index = hash_function(word);

        temp = head[index];

        while(temp != NULL)
        {
            if(strcmp(temp->word, word) == 0)
            {
                update_word_count(temp, filename);

                flag = 0;
                break;
            }

            temp = temp->link;
        }

        if(flag == 1)
        {
            insert_at_last(&head[index], word);
        }
    }

    fclose(fptr);

    return SUCCESS;
}