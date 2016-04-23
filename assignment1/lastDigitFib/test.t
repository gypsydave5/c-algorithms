0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987

First test
  $ echo "0" | $TESTDIR/a.out
  0

  $ echo "1" | $TESTDIR/a.out
  1

  $ echo "2" | $TESTDIR/a.out
  1

  $ echo "5" | $TESTDIR/a.out
  5

Last digits test
  $ echo "12" | $TESTDIR/a.out
  4

  $ echo "16" | $TESTDIR/a.out
  7