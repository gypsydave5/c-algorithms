#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked-list.h"

elt *ll_init() { return NULL; }

void ll_destroy(elt **head) {
  elt *current, *next;
  current = *head;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  *head = NULL;
}

elt *ll_push(elt *head, char str[]) {
  elt *new_el;
  new_el = malloc(sizeof(elt));
  strcpy(new_el->string, str);
  new_el->next = head;
  return new_el;
}

elt *ll_remove(elt *e, char str[]) {
  if (e->next == NULL) {
    if (strcmp(e->string, str) == 0) {
      free(e);
      return NULL;
    }
    return e;
  }

  if (strcmp(e->string, str) == 0) {
    elt *temp;
    temp = e;
    e = e->next;
    free(temp);
    return e;
  }

  if (strcmp(e->next->string, str) == 0) {
    if (e->next->next == NULL) {
      free(e->next->next);
      e->next = NULL;
      return e;
    }

    elt *temp;
    temp = e->next;
    e->next = e->next->next;
    free(temp);
    return e;
  }

  e->next = ll_remove(e->next, str);
  return e;
}

int ll_find(elt *e, char str[]) {
  if (e == NULL) {
    return 0;
  }
  if (strcmp(e->string, str) == 0) {
    return 1;
  }
  if (e->next == NULL) {
    return 0;
  }
  return ll_find(e->next, str);
}

elt *ll_upsert(elt *head, char str[]) {
  if (ll_find(head, str)) {
    return head;
  }
  return ll_push(head, str);
}

int ll_len(elt *head) {
  elt *current, *next;
  int len;
  current = head;
  len = 1;
  while (current->next != NULL) {
    next = current->next;
    free(current);
    current = next;
    len++;
  }
  return len;
}