#include "inverted.h"

int save_database(Wlist **DB)
{
    char fname[50];
    printf("Enter the file name to save database: ");
    scanf("%s", fname);

    FILE *fp = fopen(fname, "w");
    if (!fp)
    {
        printf("ERROR : Unable to create file %s\n", fname);
        return 0;
    }

    for (int i = 0; i < 128; i++)
    {
        if (DB[i])
        {
            fprintf(fp, "#:%d\n", i);

            Wlist *word = DB[i];
            while (word)
            {
                fprintf(fp, "%s:%d:", word->word, word->file_count);

                Tlist *sub = word->table_link;
                while (sub)
                {
                    fprintf(fp, "%s:%d:", sub->fname, sub->word_count);
                    sub = sub->link;
                }
                fprintf(fp, "#\n");
                word = word->link;
            }
        }
    }

    fclose(fp);
    printf("Database saved successfully\n");
    return 1;
}
