#include "inverted_Search.h"

int update_database(Wlist *head[], Flist **f_head)
{
    char filename[FNAME_SIZE];
    int ret;

    printf("\nEnter the new file name: ");
    scanf("%49s", filename);

    ret = isFileEmpty(filename);

    if(ret == FILE_NOTAVAILABLE)
    {
        printf("File %s is not available\n", filename);
        return FAILURE;
    }

    if(ret == FILE_EMPTY)
    {
        printf("File %s is empty\n", filename);
        return FAILURE;
    }

    ret = to_create_list_of_files(f_head, filename);

    if(ret == REPEATATION)
    {
        printf("File %s already exists\n", filename);
        return FAILURE;
    }

    if(ret == FAILURE)
    {
        printf("Unable to add file\n");
        return FAILURE;
    }

    read_datafile(head, filename);

    printf("\nDatabase updated successfully\n");

    return SUCCESS;
}