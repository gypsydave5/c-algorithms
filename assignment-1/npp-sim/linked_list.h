#pragma once
#include "packet.h"

typedef struct node {
  packet *data;
  struct node *next;
  struct node *prev;
} node;
