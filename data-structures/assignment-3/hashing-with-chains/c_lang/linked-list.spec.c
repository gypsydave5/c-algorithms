#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked-list.h"

void testLinkedListInit() {
  elt *head;
  head = ll_init();
  assert(head == NULL);
}

void testLinkedListPush() {
  elt *head;
  head = ll_init();
  char *str = "word";
  head = ll_push(head, str);
  assert(strcmp(head->string, "word") == 0);
  assert(head->next == NULL);
}

void testLinkedListFind() {
  elt *head;
  head = ll_init();
  char *str = "verbum";
  head = ll_push(head, str);
  assert(ll_find(head, "verbum"));
  assert(!ll_find(head, "logos"));
}

void testLinkedListFindEmpty() {
  elt *head;
  head = ll_init();
  assert(!ll_find(head, "logos"));
}

void testLinkedListMultiplePush() {
  elt *head;
  head = ll_init();
  char *str_1 = "cheddar";
  char *str_2 = "edam";
  char *str_3 = "brie";
  head = ll_push(head, str_1);
  head = ll_push(head, str_2);
  head = ll_push(head, str_3);

  assert(ll_find(head, "cheddar"));
  assert(ll_find(head, "edam"));
  assert(ll_find(head, "brie"));
  assert(!ll_find(head, "chalk"));
}

void testLinkedListRemove() {
  elt *head;
  head = ll_init();
  char *buffy = "buffy";
  char *angel = "angel";
  char *willow = "willow";
  head = ll_push(head, buffy);
  head = ll_push(head, angel);
  head = ll_push(head, willow);

  assert(ll_find(head, "buffy"));
  assert(ll_find(head, "willow"));
  assert(ll_find(head, "angel"));
  assert(strcmp(head->next->next->string, "buffy") == 0);
  head = ll_remove(head, angel);

  assert(ll_find(head, "buffy"));
  assert(ll_find(head, "willow"));
  assert(!ll_find(head, "angel"));
}

void testLinkedListRemoveOne() {
  elt *head;
  head = ll_init();
  char *buffy = "buffy";
  head = ll_push(head, buffy);

  assert(ll_find(head, "buffy"));

  head = ll_remove(head, buffy);
  assert(!ll_find(head, "buffy"));
}

void testLinkedListRemoveNonExistant() {
  elt *head;
  head = ll_init();
  char *buffy = "buffy";
  head = ll_push(head, buffy);

  head = ll_remove(head, "BOOFY");
  assert(ll_find(head, "buffy"));
}

void testLinkedListDestroy() {
  elt *head;
  head = ll_init();
  char *cucumber = "cucumber";
  char *rspec = "rspec";
  char *spock = "spock";

  head = ll_push(head, cucumber);
  head = ll_push(head, rspec);
  head = ll_push(head, spock);

  assert(strcmp(head->string, "spock") == 0);

  ll_destroy(&head);
  assert(head == NULL);
}

void testLinkedListSetBehaviour() {
  elt *head;
  head = ll_init();
  char *bob = "bob";

  head = ll_upsert(head, bob);
  head = ll_upsert(head, bob);
  head = ll_upsert(head, bob);

  assert(strcmp(head->string, "bob") == 0);
  assert(head->next == NULL);
}

void testLinkedListLength() {
  elt *head;
  head = ll_init();
  char *tom = "tom";
  char *dick = "dick";

  head = ll_upsert(head, tom);
  head = ll_upsert(head, dick);
  head = ll_upsert(head, "harry");

  assert(ll_len(head) == 3);
}

int main() {
  testLinkedListInit();
  testLinkedListPush();
  testLinkedListFind();
  testLinkedListFindEmpty();
  testLinkedListMultiplePush();
  testLinkedListRemove();
  testLinkedListRemoveOne();
  testLinkedListRemoveNonExistant();
  testLinkedListDestroy();
  testLinkedListSetBehaviour();
  testLinkedListLength();
  printf("[1;32m\tLinked list tests pass\n[0;m");
}
