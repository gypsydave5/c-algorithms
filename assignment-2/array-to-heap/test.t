  $ echo "5
  > 5 4 3 2 1" | $TESTDIR/array-to-heap.bin
  3
  1 4
  0 1
  1 3

  $ echo "5
  > 1 2 3 4 5" | $TESTDIR/array-to-heap.bin
  0
