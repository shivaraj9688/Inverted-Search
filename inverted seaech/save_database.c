#include "inverted_Search.h"

void write_databasefile(Wlist *head,
                        FILE **databasefile,
                        int index)
{
    Wlist *temp = head;


    while(temp != NULL)
    {
        fprintf(*databasefile,
                "#%d;%s;%d;",
                index,
                temp->word,
                temp->file_count);

        Ltable *link = temp->Tlink;

        while(link != NULL)
        {
            fprintf(*databasefile,
                    "%s;%d;",
                    link->file_name,
                    link->word_count);


            link = link->table_link;
        }


        fprintf(*databasefile, "#\n");


        temp = temp->link;
    }
}

int save_database(Wlist *head[])
{
    char filename[FNAME_SIZE];

    FILE *databasefile;

    int index;

    printf("\nEnter the backup file name: ");

    scanf("%49s", filename);

    databasefile = fopen(filename, "w");

    if(databasefile == NULL)
    {
        printf("Unable to create backup file\n");

        return FAILURE;
    }

    for(index = 0; index < 27; index++)
    {
        if(head[index] != NULL)
        {
            write_databasefile(head[index],
                               &databasefile,
                               index);
        }
    }
    
    fclose(databasefile);
    printf("\nDatabase saved successfully\n");
    printf("Backup file : %s\n",
           filename);
    return SUCCESS;
}