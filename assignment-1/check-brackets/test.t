  $ echo "[]" | $TESTDIR/main
  Success

  $ echo "[]{}" | $TESTDIR/main
  Success

  $ echo "(())" | $TESTDIR/main
  Success

  $ echo "{" | $TESTDIR/main
  1

  $ echo "{[}" | $TESTDIR/main
  3

  $ echo "foo(bar[i);" | $TESTDIR/main
  10

  $ echo "}()" | $TESTDIR/main
  1

  $ echo "[](()" | $TESTDIR/main
  3

  $ echo "()[{}])" | $TESTDIR/main
  7
