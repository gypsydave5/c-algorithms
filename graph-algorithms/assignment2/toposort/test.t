  $ echo "4 3
  > 1 2
  > 4 1
  > 3 1" | $TESTDIR/toposort.bin
  4 3 1 2 

  $ echo "5 7
  > 2 1
  > 3 2
  > 3 1
  > 4 3
  > 4 1
  > 5 2
  > 5 3" | $TESTDIR/toposort.bin
  5 4 3 2 1 
