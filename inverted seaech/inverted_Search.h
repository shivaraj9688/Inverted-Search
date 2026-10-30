#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define SUCCESS 0
#define FAILURE -1

#define FILE_EMPTY -2
#define FILE_NOTAVAILABLE -3
#define REPEATATION -4

#define FNAME_SIZE 50
#define WORD_SIZE 50

typedef char data_t;

typedef struct file_node
{
    data_t file_name[FNAME_SIZE];
    struct file_node *link;
} Flist;

typedef struct linkTable_node
{
    int word_count;
    data_t file_name[FNAME_SIZE];
    struct linkTable_node *table_link;
} Ltable;

typedef struct word_node
{
    int file_count;
    data_t word[WORD_SIZE];
    Ltable *Tlink;
    struct word_node *link;
} Wlist;

int isFileEmpty(char *filename);

void file_validation_n_file_list(Flist **f_head, char *argv[]);

int to_create_list_of_files(Flist **f_head, char *name);

int hash_function(const char *word);

void create_database(Flist *f_head, Wlist *head[]);

int read_datafile(Wlist *head[], char *filename);

int insert_at_last(Wlist **head, data_t *data);

int update_link_table(Wlist *head, char *filename);

int update_word_count(Wlist *head, char *filename);

void display_database(Wlist *head[]);

int search(Wlist *head, char *word);

int update_database(Wlist *head[], Flist **f_head);

int save_database(Wlist *head[]);

void write_databasefile(Wlist *head, FILE **databasefile, int index);

#endif