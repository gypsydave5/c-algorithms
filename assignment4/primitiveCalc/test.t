  $ echo "1" | $TESTDIR/a.out
  0
  1

  $ echo "5" | $TESTDIR/a.out
  3
  1 2 4 5

  $ echo "96234" | $TESTDIR/a.out
  14
  1 3 9 10 11 22 66 198 594 1782 5346 16038 16039 32078 96234
