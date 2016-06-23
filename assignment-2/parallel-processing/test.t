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

  $ echo "4 9
  > 2 2 2 2 2 2 2 2 2" | $TESTDIR/parallel-processing.bin
  0 0
  1 0
  2 0
  3 0
  0 2
  1 2
  2 2
  3 2
  0 4

  $ echo "4 8
  > 1 2 3 4 1 2 3 4" | $TESTDIR/parallel-processing.bin
  0 0
  1 0
  2 0
  3 0
  0 1
  0 2
  1 2
  2 3

  $ echo "4 8
  > 4 3 2 1 4 3 2 1" | $TESTDIR/parallel-processing.bin
  0 0
  1 0
  2 0
  3 0
  3 1
  2 2
  1 3
  0 4

  $ echo "4 8
  > 4 3 2 1 1 2 3 4" | $TESTDIR/parallel-processing.bin
  0 0
  1 0
  2 0
  3 0
  3 1
  2 2
  3 2
  1 3

  $ echo "2 6
  > 1 2 0 0 2 1" | $TESTDIR/parallel-processing.bin
  0 0
  1 0
  0 1
  0 1
  0 1
  1 2

  $ echo "1 10
  > 1 2 3 4 5 6 7 8 9 10" | $TESTDIR/parallel-processing.bin
  0 0
  0 1
  0 3
  0 6
  0 10
  0 15
  0 21
  0 28
  0 36
  0 45

  $ echo "500 10
  > 1 2 3 4 5 6 7 8 9 10" | $TESTDIR/parallel-processing.bin
  0 0
  1 0
  2 0
  3 0
  4 0
  5 0
  6 0
  7 0
  8 0
  9 0

  $ echo "2 5
  > 0 2 0 4 5" | $TESTDIR/parallel-processing.bin
  0 0
  0 0
  1 0
  1 0
  0 2

