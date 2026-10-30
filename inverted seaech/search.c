#include "inverted_Search.h"
int search(Wlist *head,
           char *word)
{
    Wlist *temp;
    temp = head;
  
    while(temp != NULL)
    {
        if(strcmp(temp->word, word) == 0)
        {
            Ltable *link;
           
            printf("\nWord %s is present in %d files\n",
                   temp->word,
                   temp->file_count);

            printf("\n");
        
            link = temp->Tlink;
            while(link != NULL)
            {
                printf("File Name : %-30s Word Count : %d\n",
                       link->file_name,
                       link->word_count);

                link = link->table_link;
            }

            printf("\nSearch completed successfully.\n");
            return SUCCESS;
        }
        temp = temp->link;
    }

    printf("\nWord %s is not present in database\n",
           word);
    return FAILURE;
}