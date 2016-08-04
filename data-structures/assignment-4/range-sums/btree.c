#include <stdlib.h>
#include "btree.h"

void joinLeft(node **parent, node **leftChild) {
  (*parent)->child[LEFT] = *leftChild;
  (*leftChild)->parent = *parent;
}
