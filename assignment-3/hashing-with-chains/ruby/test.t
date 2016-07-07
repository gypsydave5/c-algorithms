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
  > del good" | ruby $TESTDIR/hashing_with_chains.rb
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
  > find Test" | ruby $TESTDIR/hashing_with_chains.rb
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
  > check 4" | ruby $TESTDIR/hashing_with_chains.rb
  HellO

  $ echo "5
  > 12
  > add world
  > add HellO
  > check 4
  > add HellO
  > check 4
  > del HellO
  > del HellO
  > check 4
  > del world
  > check 4
  > add HellO
  > check 4" | ruby $TESTDIR/hashing_with_chains.rb
  HellO world
  HellO world
  world
  
  HellO

  $ echo "5
  > 7
  > check 1
  > check 2
  > check 3
  > check 4
  > check 0
  > add HellO
  > check 4" | ruby $TESTDIR/hashing_with_chains.rb
  
  
  
  
  
  HellO

  $ echo "5
  > 7
  > add world
  > del world
  > del world
  > find world
  > del world
  > add world
  > find world
  > " | ruby $TESTDIR/hashing_with_chains.rb
  no
  yes
