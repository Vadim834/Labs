#pragma once
#include "Message.h"

typedef struct node {
    struct Message message;
    struct node* next;
} node_t;

void print_list(node_t* head);

void add(node_t* head, Message message);

void add_to_beginning(node_t** head, Message message);

void remove_first(node_t** head);

void remove_last(node_t* head);

void remove_by_index(node_t** head, int n);

int size(node_t* head);

void search_draft(node_t* head);

node_t* sort_by_encoding(node_t* head);

node_t* read_from_file();

void write_to_file(node_t* head);

node_t* free_list(node_t* dlist);