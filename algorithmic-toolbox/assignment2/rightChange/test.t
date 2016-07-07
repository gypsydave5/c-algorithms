making change tests

  $ echo "2" | $TESTDIR/a.out
  2

  $ echo "5" | $TESTDIR/a.out
  1

  $ echo "6" | $TESTDIR/a.out
  2

  $ echo "28" | $TESTDIR/a.out
  6
