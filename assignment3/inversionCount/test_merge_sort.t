  $ echo "2
  > 2 1" | $TESTDIR/a.out
  1 2

  $ echo "6
  > 4 5 7 2 1 3" | $TESTDIR/a.out
  1 2 3 4 5 7
