#include "inverted.h"

/* Checks whether file exists and is not empty */
int IsFileExist(char *fname)
{
    FILE *fp = fopen(fname, "r");
    if (!fp) return FILE_NOT_FOUND;
    
    // Move file pointer to end of file
    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0)
    {
        fclose(fp);
        return FILE_EMPTY;
    }

    fclose(fp);
    return SUCCESS;
}

/* Inserts file name into file linked list */
int insert_file(Flist **head, char *fname)
{
    Flist *temp = *head;
    // Check for duplicate file name
    while (temp)
    {
        if (!strcmp(temp->fname, fname))
            return FILE_REPEATED;
        temp = temp->link;
    }
    // Create new node for file
    Flist *new = malloc(sizeof(Flist));
    strcpy(new->fname, fname);
    // Insert node at beginning of linked list
    new->link = *head;
    *head = new;
    return SUCCESS;
}

/* Validates all file names from command line */
int validate_filenames(char **argv, Flist **fhead)
{
    int i = 1, ret;
    while (argv[i] != NULL)
    {
        // Check if file exists and is not empty
        ret = IsFileExist(argv[i]);
        if (ret == FILE_NOT_FOUND)
        {
            printf("ERROR : File %s not found\n", argv[i]);
            return 0;
        }
        if (ret == FILE_EMPTY)
        {
            printf("ERROR : File %s is empty\n", argv[i]);
            return 0;
        }
        
        // Insert valid file into linked list
        ret = insert_file(fhead, argv[i]);
        if (ret == FILE_REPEATED)
        {
            printf("ERROR : File %s is repeated\n", argv[i]);
            return 0;
        }

        printf("Successful: inserting file name : %s into file linked list\n", argv[i]);
        i++;
    }
    return 1;
}
