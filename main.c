#include "inverted.h"

int main(int argc, char *argv[])
{
    Flist *f_head = NULL;
    Wlist *DB[128] = {0}; 

    if (argc < 2)
    {
        printf("Error: No file names passed through CL\n");
        return 0;
    }

    if (!validate_filenames(argv, &f_head))
        return 0;

    int choice;
    char option;

    do
    {
        printf("\nSelect your choice:\n");
        printf("1. Create Database\n2. Display Database\n3. Update Database\n");
        printf("4. Search Database\n5. Save Database\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: create_database(f_head, DB); break;
            case 2: display_database(DB); break;
            case 3: update_database(&f_head, DB); break;
            case 4: search_database(DB); break;
            case 5: save_database(DB); break;
            default: printf("Invalid choice\n");
        }
        printf("\nDo you want to continue ?");
        printf("\n(y/Y to continue, n/N to exit): ");
        scanf(" %c", &option);

    } while (option == 'y' || option == 'Y');

    return 0;
}
