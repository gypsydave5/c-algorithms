#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM_LEN 10000000
#define MAX_WORD_LEN 15 + 1

void add(char *phone_book[MAX_WORD_LEN], unsigned long long number,
         char *name) {
  strcpy(phone_book[number], name);
}

void delete (char *phone_book[MAX_WORD_LEN], unsigned long long number) {
  strcpy(phone_book[number], "not found");
}

char *find(char *phone_book[MAX_WORD_LEN], unsigned long long number) {
  return phone_book[number];
}

int main() {
  char **phone_book = malloc(MAX_NUM_LEN * sizeof(char *) +
                             (MAX_NUM_LEN * (MAX_WORD_LEN * sizeof(char))));
  unsigned long long number;
  char name[16], query[5];
  unsigned long long query_count, i;
  char *not_found = "not found";

  for (i = 0; i < MAX_NUM_LEN; i++) {
    phone_book[i] = malloc(MAX_WORD_LEN * sizeof(char));
    strcpy(phone_book[i], not_found);
  }

  scanf("%lld\n", &query_count);

  for (i = 0; i < query_count; i++) {
    scanf("%s", query);
    switch (query[0]) {
      case 'a':
        scanf("%lld %s\n", &number, name);
        add(phone_book, number, name);
        break;
      case 'd':
        scanf("%lld\n", &number);
        delete (phone_book, number);
        name[0] = '\0';
        break;
      case 'f':
        scanf("%lld\n", &number);
        printf("%s\n", find(phone_book, number));
        name[0] = '\0';
        break;
    }
  }

  for (i = 0; i < MAX_NUM_LEN; i++) {
    free(phone_book[i]);
  }
  free(phone_book);
}