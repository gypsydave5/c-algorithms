  $ echo "5
  > 2 3 9 2 9" | $TESTDIR/a.out
  2

  $ echo "4
  > 1 2 3 4" | $TESTDIR/a.out
  0

  $ echo "6
  > 9 8 7 3 2 1" | $TESTDIR/a.out
  15

  $ echo "10
  > 1 6 3 3 8 4 8 10 1 3" | $TESTDIR/a.out
  16

  $ echo "5
  > 1 6 3 3 8" | $TESTDIR/a.out
  2


