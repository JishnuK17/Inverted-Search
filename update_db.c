#include "inverted.h"

int update_database(Flist **fhead, Wlist **DB)
{
    char fname[50];
    printf("Enter the file name to update database: ");
    scanf("%s", fname);

    if (!insert_file(fhead, fname))
    {
        printf("INFO : File already present in database\n");
        return 0;
    }

    int ret = IsFileExist(fname);
    if (ret == FILE_NOT_FOUND)
    {
        printf("ERROR : File %s not found\n", fname);
        return 0;
    }
    if (ret == FILE_EMPTY)
    {
        printf("ERROR : File %s is empty\n", fname);
        return 0;
    }

    printf("Successful: inserting file name : %s into file linked list\n", fname);
    scan_createDB(DB, fname);
    printf("Successful: creation of DATABASE for file: %s\n", fname);
    return 1;
}
