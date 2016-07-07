  $ echo "1 0" | $TESTDIR/packet_count.bin


  $ echo "1 1
  > 0 0" | $TESTDIR/packet_count.bin
  0

  $ echo "1 2
  > 0 1
  > 0 1" | $TESTDIR/packet_count.bin
  0
  -1


  $ echo "1 2
  > 0 1
  > 1 1" | $TESTDIR/packet_count.bin
  0
  1

  $ echo "1 3
  > 0 1
  > 1 1
  > 2 1" | $TESTDIR/packet_count.bin
  0
  1
  2

  $ echo "3 3
  > 0 1
  > 0 1
  > 0 1" | $TESTDIR/packet_count.bin
  0
  1
  2

  $ echo "1 3
  > 0 1
  > 0 1
  > 0 1" | $TESTDIR/packet_count.bin
  0
  -1
  -1

  $ echo "0 3
  > 0 1
  > 0 1
  > 0 1" | $TESTDIR/packet_count.bin
  -1
  -1
  -1

  $ echo "1 3
  > 0 5
  > 2 1
  > 10 1" | $TESTDIR/packet_count.bin
  0
  -1
  10

  $ echo "1 3
  > 0 5
  > 4 1
  > 10 1" | $TESTDIR/packet_count.bin
  0
  -1
  10

  $ echo "1 3
  > 0 5
  > 4 1
  > 10 1" | $TESTDIR/packet_count.bin
  0
  -1
  10
