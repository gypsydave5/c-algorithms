  $ echo "4 4
  > 1 2
  > 4 1
  > 2 3
  > 3 1" | $TESTDIR/strongly_connected.bin
  2

  $ echo "5 7
  > 2 1
  > 3 2
  > 3 1
  > 4 3
  > 4 1
  > 5 2
  > 5 3" | $TESTDIR/strongly_connected.bin
  5

  $ echo "9 13
  > 1 4
  > 1 5
  > 2 1
  > 3 1
  > 6 2
  > 6 7
  > 7 8
  > 5 8
  > 8 9
  > 9 8
  > 9 4
  > 5 2
  > 5 3" | $TESTDIR/strongly_connected.bin
  5
