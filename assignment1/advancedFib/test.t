First test
  $ echo "1 1" | $TESTDIR/a.out
  0

  $ echo "6 3" | $TESTDIR/a.out
  2

  $ echo "7 2" | $TESTDIR/a.out
  1

  $ echo "9 12" | $TESTDIR/a.out
  10

Very difficult test
$ echo "281621358815590 30524" | $TESTDIR/a.out
11963
