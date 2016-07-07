  $ echo "10 3
  > 1 4 8" | $TESTDIR/a.out
  9

  $ echo "20 3
  > 1 4 8" | $TESTDIR/a.out
  13

  $ echo "20 4
  > 1 4 8 10" | $TESTDIR/a.out
  19

  $ echo "10 5
  > 3 5 3 3 5" | $TESTDIR/a.out
  10