  $ echo "4 4
  > 1 2
  > 3 2
  > 4 3
  > 1 4
  > 1 4" | $TESTDIR/reach.bin
  1

  $ echo "4 2
  > 1 2
  > 3 2
  > 1 4" | $TESTDIR/reach.bin
  0
