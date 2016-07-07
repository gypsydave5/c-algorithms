  $ echo "3
  > 1 2 3
  > 3
  > 2 1 3
  > 3
  > 1 3 5" | $TESTDIR/a.out
  2

  $ echo "5
  > 8 3 2 1 7
  > 7
  > 8 2 1 3 8 1 0 7
  > 6
  > 6 8 3 1 4 7" | $TESTDIR/a.out
  3

