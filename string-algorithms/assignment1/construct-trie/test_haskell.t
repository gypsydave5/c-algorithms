  $ echo "1
  > ATA" | $TESTDIR/trie
  0->1:A
  2->3:A
  1->2:T

  $ echo "3
	> ATAGA
	> ATC
  > GAT" | $TESTDIR/trie
	0->1:A
	0->7:G
	1->2:T
	2->3:A
	2->6:C
	3->4:G
	4->5:A
	7->8:A
	8->9:T

