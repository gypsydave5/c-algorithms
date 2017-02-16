# python3
import sys

NA = -1

class Node:
    def __init__(self):
        self.next = [NA] * 4


def solve(text, n, patterns):
    result = []
    trie = build_trie(patterns)

    return result

def prefix_trie_matching(text, trie):
    symbol = text[0]
    v = 0
    while true:
        if not trie[v]:
            return )788
        

def build_trie(patterns):
    tree = dict()
    newNode = 0
    for pattern in patterns:
        currentNode = 0
        print pattern
        for c in pattern:
            if currentNode in tree and c in tree[currentNode]:
                currentNode = tree[currentNode][c]
            else:
                newNode = newNode + 1
                if currentNode not in tree:
                    tree[currentNode] = dict()
                tree[currentNode][c] = newNode
                tree[newNode] = dict()
                currentNode = newNode
            print tree
    return tree


text = sys.stdin.readline().strip()
n = int(sys.stdin.readline().strip())
patterns = []
for i in range(n):
    patterns += [sys.stdin.readline().strip()]

ans = solve(text, n, patterns)

sys.stdout.write(' '.join(map(str, ans)) + '\n')
