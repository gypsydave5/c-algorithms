  $ echo "2 5
  > 1 2 3 4 5" | $TESTDIR/parallel-processing.bin
  0 0
  1 0
  0 1
  1 2
  0 4

  $ echo "4 20
  > 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" | $TESTDIR/parallel-processing.bin
  0 0
  1 0
  2 0
  3 0
  0 1
  1 1
  2 1
  3 1
  0 2
  1 2
  2 2
  3 2
  0 3
  1 3
  2 3
  3 3
  0 4
  1 4
  2 4
  3 4
