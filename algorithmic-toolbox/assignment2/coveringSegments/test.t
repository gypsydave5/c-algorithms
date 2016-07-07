
  $ echo "3
  > 1 3
  > 2 5
  > 3 6" | ruby $TESTDIR/seg_by_pt_greedy.rb
  1
  3

  $ echo "4
  > 4 7
  > 1 3
  > 2 5
  > 5 6" | ruby $TESTDIR/seg_by_pt_greedy.rb
  2
  3 6
