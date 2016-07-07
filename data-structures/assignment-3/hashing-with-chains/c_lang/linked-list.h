#pragma once

typedef struct elt {
  struct elt* next;
  char string[16];
} elt;

elt* ll_push(elt* head, char str[]);
elt* ll_upsert(elt* head, char str[]);
int ll_find(elt* head, char str[]);
elt* ll_init();
elt* ll_remove(elt* head, char str[]);
void ll_destroy(elt** head);
int ll_len(elt* head);
void ll_fetch_values(elt** head, char **array);
