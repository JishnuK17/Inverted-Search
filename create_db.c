#include "inverted.h"

/* Creates the inverted database from the file linked list */
int create_database(Flist *fptr, Wlist **DB)
{
    printf("Successful: Creation of DATABASE for %s\n",fptr->fname);
    while (fptr)
    {
        scan_createDB(DB, fptr->fname);
        fptr = fptr->link;
    }
    return 1;
}

/* Reads each word from file and inserts it into the hash table */
void scan_createDB(Wlist **DB, char *fname)
{
    FILE *fp = fopen(fname, "r");
    if (!fp) return;

    char word[50];

    while (fscanf(fp, "%s", word) != EOF)
    {
        int index;
        // Compute hash index based on first character of word
        if (isalpha(word[0]))
            index = tolower(word[0]) - 'a'; // a-z → 0-25
        else
            index = (unsigned char)word[0]; // non-alpha

        Wlist *temp = DB[index], *prev = NULL;

        
        while (temp && strcmp(temp->word, word) < 0)
        {
            prev = temp;
            temp = temp->link;
        }
        // Case 1: Word already exists in database
        if (temp && strcmp(temp->word, word) == 0)
        {
            // update file list
            Tlist *sub = temp->table_link;
            while (sub && strcmp(sub->fname, fname))
                sub = sub->link;

            if (!sub)
            {
                Tlist *newt = calloc(1, sizeof(Tlist));
                strcpy(newt->fname, fname);
                newt->word_count = 1;
                newt->link = temp->table_link;
                temp->table_link = newt;
                temp->file_count++;
            }
            else
            {
                sub->word_count++;
            }
        }
        // Case 2: New word 
        else
        {
            // New main node
            Wlist *neww = calloc(1, sizeof(Wlist));
            strcpy(neww->word, word);
            neww->file_count = 1;

            Tlist *sub = calloc(1, sizeof(Tlist));
            strcpy(sub->fname, fname);
            sub->word_count = 1;

            neww->table_link = sub;

            if (!prev)
            {
                neww->link = DB[index];
                DB[index] = neww;
            }
            else
            {
                neww->link = prev->link;
                prev->link = neww;
            }
        }
    }

    fclose(fp);
}
