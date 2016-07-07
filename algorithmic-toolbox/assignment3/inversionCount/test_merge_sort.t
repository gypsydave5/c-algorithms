  $ echo "2
  > 2 1" | $TESTDIR/a.out
  1 2

  $ echo "6
  > 4 5 7 2 1 3" | $TESTDIR/a.out
  1 2 3 4 5 7

  $ echo "8
  > 10 4 9 1 3 5 9 1" | $TESTDIR/a.out
  1 3 4 4 5 9 9 10
