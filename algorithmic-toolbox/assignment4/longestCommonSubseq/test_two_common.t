  $ echo "2
  > 1 2
  > 2
  > 1 2" | $TESTDIR/a.out
  2

  $ echo "2
  > 1 2
  > 5
  > 1 4 4 4 2" | $TESTDIR/a.out
  2

  $ echo "5
  > 1 2 8 9 10
  > 5
  > 1 5 6 9 10" | $TESTDIR/a.out
  3

  $ echo "10
  > 1 2 3 4 5 6 7 8 9 10
  > 10
  > 1 1 1 1 4 5 10 10 10 10" | $TESTDIR/a.out
  4

