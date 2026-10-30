#include "inverted_Search.h"

int main(int argc, char *argv[])
{
    int option;
    char choice;

    Wlist *head[27] = {NULL};

    if(argc < 2)
    {
        printf("Enter the valid number of arguments\n");
        printf("Usage: ./invsearch file1.txt file2.txt\n");

        return FAILURE;
    }

    Flist *f_head = NULL;

    file_validation_n_file_list(&f_head, argv);

    if(f_head == NULL)
    {
        printf("\nNo files are added to the list\n");
        printf("Process terminated\n");

        return FAILURE;
    }

    do
    {
        printf("\n");
        printf("====================================\n");
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Search Database\n");
        printf("4. Update Database\n");
        printf("5. Save Database\n");
        printf("6. Exit\n");
        printf("====================================\n");

        printf("Enter a choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                create_database(f_head, head);
                break;

            case 2:
                display_database(head);
                break;

            case 3:
            {
                char word[WORD_SIZE];

                printf("Enter the word to search: ");
                scanf("%49s", word);

                int index = hash_function(word);

                search(head[index], word);

                break;
            }

            case 4:
                update_database(head, &f_head);
                break;

            case 5:
                save_database(head);
                break;

            case 6:
                printf("\nExiting...\n");
                return SUCCESS;

            default:
                printf("Invalid choice\n");
        }

        if(option != 6)
        {
            printf("\nDo you want to continue? (Y/N): ");
            scanf(" %c", &choice);

            if(choice != 'Y' && choice != 'y')
            {
                printf("\nExiting...\n");
                break;
            }
        }

    } while(1);

    return SUCCESS;
}