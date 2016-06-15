#pragma once

int parent(int array[], int index);
int left_child(int array[], int index);
int right_child(int array[], int index);
void sift_down(int array[], int size, int index);
void swap(int *a, int *b);
void build_heap(int array[], int size);
