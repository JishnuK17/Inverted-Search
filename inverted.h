#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Constants */
#define FILE_NOT_FOUND  -1
#define FILE_EMPTY      -2
#define FILE_REPEATED   -3
#define SUCCESS          1

/* File linked list */
typedef struct file_node
{
    char fname[50];
    struct file_node *link;
} Flist;

/* Sub-node for word in each file */
typedef struct sub_node
{
    char fname[50];
    int word_count;
    struct sub_node *link;
} Tlist;

/* Main word node */
typedef struct main_node
{
    char word[50];
    int file_count;
    Tlist *table_link;
    struct main_node *link;
} Wlist;

/* Function declarations */
int insert_file(Flist **, char *);
int validate_filenames(char **, Flist **);
int IsFileExist(char *);

int create_database(Flist *, Wlist **DB);
void scan_createDB(Wlist **DB, char *fname);
int update_database(Flist **, Wlist **DB);
int display_database(Wlist **DB);
int search_database(Wlist **DB);
int save_database(Wlist **DB);

#endif
