#include "inverted.h"

int get_idx(char ch)
{
    if (isalpha(ch))
        return tolower(ch) - 'a';//a-z
    else
        return (unsigned char) ch;//special characters
}

int search_database(Wlist **DB)
{
    char key[50];
    printf("Enter the word to search: ");
    scanf("%s", key);
    
    // Compute hash index
    int index = get_idx(key[0]);

    Wlist *temp = DB[index];

    while (temp)
    {
        if (strcmp(temp->word, key) == 0)
        {
            printf("Word %s is present in %d file(s)\n",
                   temp->word, temp->file_count);

            Tlist *sub = temp->table_link;
            while (sub)
            {
                printf("%s -> %d time(s)\n",
                       sub->fname, sub->word_count);
                sub = sub->link;
            }
            return 1;
        }
        temp = temp->link;
    }

    printf("Word not found !\n");
    return 0;
}
