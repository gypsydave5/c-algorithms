  $ echo "5 5
  > 1 1 1 1 1
  > 3 5
  > 2 4
  > 1 4
  > 5 4
  > 5 3" | $TESTDIR/merge-tables.bin
  2
  2
  3
  5
  5

  $ echo "6 4
  > 10 0 5 0 3 3
  > 6 6
  > 6 5
  > 5 4
  > 4 3" | $TESTDIR/merge-tables.bin
  10
  10
  10
  11
