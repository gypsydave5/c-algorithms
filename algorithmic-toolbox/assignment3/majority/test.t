  $ echo "5
  > 2 3 9 2 2" | $TESTDIR/a.out
  1

  $ echo "4
  > 1 2 3 4" | $TESTDIR/a.out
  0

  $ echo "4
  > 1 2 3 1" | $TESTDIR/a.out
  0

