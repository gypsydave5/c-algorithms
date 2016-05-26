  $ echo "5
  > 2 3 9 2 2" | $TESTDIR/a.out
  2 2 2 3 9

  $ echo "5
  > 2 3 9 2 9" | $TESTDIR/a.out
  2 2 3 9 9

  $ echo "8
  > 10 4 9 1 3 5 9 4" | $TESTDIR/a.out
  1 3 4 4 5 9 9 10


