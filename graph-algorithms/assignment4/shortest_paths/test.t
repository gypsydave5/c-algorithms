  $ echo "6 7
  > 1 2 10
  > 2 3 5
  > 1 3 100
  > 3 5 7
  > 5 4 10
  > 4 3 -18
  > 6 1 -1
  > 1" | $TESTDIR/shortest_paths.bin
  0
  10
  -
  -
  -
  *

  $ echo "5 4
  > 1 2 1
  > 4 1 2
  > 2 3 2
  > 3 1 -5
  > 4" | $TESTDIR/shortest_paths.bin
  -
  -
  -
  0
  *
