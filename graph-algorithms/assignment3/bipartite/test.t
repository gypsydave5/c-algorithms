  $ echo "4 4
  > 1 2
  > 4 1
  > 2 3
  > 3 1" | $TESTDIR/bipartite.bin
  0

  $ echo "5 4
  > 5 2
  > 4 2
  > 3 4
  > 1 4" | $TESTDIR/bipartite.bin
  1
