#include "inverted.h"   

int display_database(Wlist **DB)
{
    for (int i = 0; i < 128; i++)  
    {
        Wlist *word_temp = DB[i];
        while (word_temp)
        {
            printf("[%d] [%s] %d file(s) : ", i, word_temp->word, word_temp->file_count);

            Tlist *subtemp = word_temp->table_link;
            while (subtemp)
            {
                printf("file : %s : %d time(s)  ", subtemp->fname, subtemp->word_count);
                subtemp = subtemp->link;
            }
            printf("\n");

            word_temp = word_temp->link;
        }
    }
    return 1;
}
