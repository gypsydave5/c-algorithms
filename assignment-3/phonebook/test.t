  $ echo "12
  > add 911 police
  > add 76213 Mom
  > add 17239 Bob
  > find 76213
  > find 910
  > find 911
  > del 910
  > del 911
  > find 911
  > find 76213
  > add 76213 daddy
  > find 76213" | $TESTDIR/a.out
  Mom
  not found
  police
  not found
  Mom
  daddy

  $ echo "8
  > find 3839442
  > add 123456 me
  > add 0 granny
  > find 0
  > find 123456
  > del 0
  > del 0
  > find 0" | $TESTDIR/a.out
  not found
  granny
  me
  not found
