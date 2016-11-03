  $ echo "4 4
  > 1 2
  > 4 1
  > 2 3
  > 3 1
  > 2 4" | $TESTDIR/bfs.bin
  2

  $ echo "5 4
  > 5 2
  > 1 3
  > 3 4
  > 1 4
  > 3 5" | $TESTDIR/bfs.bin
  -1
