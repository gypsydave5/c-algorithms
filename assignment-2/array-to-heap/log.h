#pragma once

typedef struct entry {
    int i;
    int j;
} entry;

typedef struct log {
    entry *logs;
    int size;
    int capacity;
} log;

void log_init(log *l, int capacity);

