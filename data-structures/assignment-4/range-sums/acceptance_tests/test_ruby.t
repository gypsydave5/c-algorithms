  $ cat $TESTDIR/test_one.txt | ruby $TESTDIR/../ruby/naive_set_range_sum.rb
  Not found
  Found
  3
  Found
  Not found
  1
  Not found
  10

  $ cat $TESTDIR/test_two.txt | ruby $TESTDIR/../ruby/naive_set_range_sum.rb
  Not found
  Found
  Not found

  $ cat $TESTDIR/test_three.txt | ruby $TESTDIR/../ruby/naive_set_range_sum.rb
  Found
  Not found
  491572259
