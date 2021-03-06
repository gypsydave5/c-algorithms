#pragma once
void merge_sort(int array[], int array_length);
void merge(int array[], int l, int m, int r);
void m_sort(int array[], int l, int r);
int merge_inversions(int array[], int array_start, int middle, int array_end);
int m_sort_inversion(int array[], int l, int r);
int merge_sort_inversion(int array[], int array_length);
int merge_inversions_better(int array[], int array_start, int middle,
                            int array_end);
int m_sort_inversion_better(int array[], int l, int r);
int merge_sort_inversion_better(int array[], int array_length);
void print_array(int array[], int len);
void print_array_range(int array[], int l, int r);
