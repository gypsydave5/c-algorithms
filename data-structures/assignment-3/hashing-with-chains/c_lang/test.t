  $ echo "5
  > 12
  > add world
  > add HellO
  > check 4
  > find World
  > find world
  > del world
  > check 4
  > del HellO
  > add luck
  > add GooD
  > check 2
  > del good" | $TESTDIR/hash.bin
  HellO world
  no
  yes
  HellO
  GooD luck

  $ echo "4
  > 8
  > add test
  > add test
  > find test
  > del test
  > find test
  > find Test
  > add Test
  > find Test" | $TESTDIR/hash.bin
  yes
  no
  no
  yes

  $ echo "5
  > 5
  > add world
  > add HellO
  > del world
  > del world
  > check 4" | $TESTDIR/hash.bin
  HellO

