  $ echo "5
  > 4 -1 4 1 1" | $TESTDIR/tree-height.out
  3

  $ echo "5
  > -1 0 4 0 3" | $TESTDIR/tree-height.out
  4

  $ echo "6
  > -1 0 0 0 0 0" | $TESTDIR/tree-height.out
  2

  $ echo "7
  > -1 0 0 1 2 3 4" | $TESTDIR/tree-height.out
  4

  $ echo "10
  > -1 0 1 2 3 4 5 6 7 8" | $TESTDIR/tree-height.out
  10

Bit of a stress test here...

  $ ruby -e "puts 1000000; i = -2; 1000000.times do printf('%d ' , i += 1) end" | $TESTDIR/tree-height.out
  1000000
