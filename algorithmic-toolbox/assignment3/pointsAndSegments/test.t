  $ echo "2 3
  > 0 5
  > 7 10
  > 1 6 11" | $TESTDIR/a.out
  1 0 0

  $ echo "1 3
  > -10 10
  > -100 100 0" | $TESTDIR/a.out
  0 0 1

  $ echo "3 2
  > 0 5
  > -3 2
  > 7 10
  > 1 6" | $TESTDIR/a.out
  2 0