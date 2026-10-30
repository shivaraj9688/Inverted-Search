#include "inverted_Search.h"

void display_database(Wlist *head[])
{
    int index;
    int flag = 0;

    printf("\n");
    printf("\t\t\t\tINVERTED SEARCH DATABASE\n");

    printf("============================================================================================================\n");

    printf("| %-3s | %-20s | %-10s | %-30s | %-10s |\n",
           "Idx",
           "Word",
           "File Count",
           "File Name",
           "Word Count");

    printf("============================================================================================================\n");

    for(index = 0; index < 27; index++)
    {
        Wlist *temp = head[index];

        while(temp != NULL)
        {
            Ltable *link;
            flag = 1;

            link = temp->Tlink;

            if(link != NULL)
            {
                printf("| %-3d | %-20s | %-10d | %-30s | %-10d |\n",
                       index,
                       temp->word,
                       temp->file_count,
                       link->file_name,
                       link->word_count);

                link = link->table_link;
            }

            while(link != NULL)
            {
                printf("| %-3s | %-20s | %-10s | %-30s | %-10d |\n",
                       "",
                       "",
                       "",
                       link->file_name,
                       link->word_count);

                link = link->table_link;
            }

            printf("------------------------------------------------------------------------------------------------------------\n");
        
            temp = temp->link;
        }
    }
    
    if(flag == 0)
    {
        printf("Database is empty\n");

        printf("============================================================================================================\n");
    }
}