#include <stdio.h>
#include <stdlib.h>

unsigned long long get_root(unsigned long long node,
                            unsigned long long *table_pointers) {
  if (node != table_pointers[node]) {
    table_pointers[node] = get_root(table_pointers[node], table_pointers);
  }
  return table_pointers[node];
}

int main() {
  unsigned long long n_tables, n_merges, i, *table_pointers, *table_row_counts,
      *table_tree_heights, *max_table_row_log, max_height, dest, source;

  max_height = 0;

  scanf("%lld %lld\n", &n_tables, &n_merges);

  table_pointers = malloc(n_tables * sizeof(unsigned long long));
  table_row_counts = malloc(n_tables * sizeof(unsigned long long));
  table_tree_heights = malloc(n_tables * sizeof(unsigned long long));
  max_table_row_log = malloc(n_merges * sizeof(unsigned long long));

  for (i = 0; i < n_tables; i++) {
    scanf("%lld", &table_row_counts[i]);
    if (table_row_counts[i] > max_height) {
      max_height = table_row_counts[i];
    }
    table_pointers[i] = i;
    table_tree_heights[i] = 0;
  }

  for (i = 0; i < n_merges; i++) {
    scanf("%lld %lld\n", &dest, &source);
    dest--;
    source--;
    dest = get_root(dest, table_pointers);
    source = get_root(source, table_pointers);
    if (source != dest) {
      table_row_counts[dest] += table_row_counts[source];
      table_row_counts[source] = 0;
      max_height = max_height < table_row_counts[dest] ? table_row_counts[dest]
                                                       : max_height;
      table_pointers[source] = dest;
    }
    max_table_row_log[i] = max_height;
  }

  for (i = 0; i < n_merges; i++) {
    printf("%lld\n", max_table_row_log[i]);
  }

  free(table_pointers);
  free(table_row_counts);
  free(table_tree_heights);
  free(max_table_row_log);
}