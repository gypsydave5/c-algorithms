  $ echo "4 4
  > 1 2 1
  > 4 1 2
  > 2 3 2
  > 1 3 5
  > 1 3" | $TESTDIR/dijkstra.bin
  3

  $ echo " 9
  > 1 2 4
  > 1 3 2
  > 2 3 2
  > 3 2 1
  > 2 4 2
  > 3 5 4
  > 5 4 1
  > 2 5 3
  > 3 4 4
  > 1 5" | $TESTDIR/dijkstra.bin
  6

  $ echo "3 3
  > 1 2 7
  > 1 3 5
  > 2 3 2
  > 3 2" | $TESTDIR/dijkstra.bin
  -1
