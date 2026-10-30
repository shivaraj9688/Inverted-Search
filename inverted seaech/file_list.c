#include "inverted_Search.h"

int isFileEmpty(char *filename)
{
    FILE *fptr;
    fptr = fopen(filename, "r");

   
    if(fptr == NULL)
    {
        return FILE_NOTAVAILABLE;
    }
   
    fseek(fptr, 0, SEEK_END);
   
    if(ftell(fptr) == 0)
    {
        fclose(fptr);
        return FILE_EMPTY;
    }

    fclose(fptr);
    return SUCCESS;
}

int to_create_list_of_files(Flist **f_head,
                            char *name)
{
    Flist *new;
    Flist *temp;
   
    new = malloc(sizeof(Flist));

    if(new == NULL)
    {
        return FAILURE;
    }
  
    strcpy(new->file_name, name);

    new->link = NULL;
   
    if(*f_head == NULL)
    {
        *f_head = new;

        return SUCCESS;
    }
   
    temp = *f_head;

    while(temp != NULL)
    {
       
        if(strcmp(temp->file_name, name) == 0)
        {
            free(new);

            return REPEATATION;
        }
        if(temp->link == NULL)
        {
            break;
        }

        temp = temp->link;
    }
    
    temp->link = new;

    return SUCCESS;
}

void file_validation_n_file_list(Flist **f_head,char *argv[])
{
    int i = 1;

    while(argv[i] != NULL)
    {
        int ret;
        ret = isFileEmpty(argv[i]);
       
        if(ret == FILE_NOTAVAILABLE)
        {
            printf("File %s is not available\n",
                   argv[i]);

            printf("Hence we are not adding that file into Linked List\n");
        }
        
        else if(ret == FILE_EMPTY)
        {
            printf("File %s is empty\n",
                   argv[i]);

            printf("Hence we are not adding that file into Linked List\n");
        }
        
        else
        {
            ret = to_create_list_of_files(f_head,argv[i]);

            if(ret == SUCCESS)
            {
                printf("Successfully added %s file into Linked List\n",argv[i]);
            }

            else if(ret == REPEATATION)
            {
                printf("File %s is repeated\n",argv[i]);
            }

            else
            {
                printf("Something went wrong\n");
            }
        }
        i++;
    }
}