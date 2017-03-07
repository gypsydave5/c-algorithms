# python3
import sys

NA = -1

class Node:
    def __init__(self):
        self.next = [NA] * 4


def solve(text, n, patterns):
    index = 0
    result = []
    trie = build_trie(patterns)
    while text[index:]:
        if prefix_trie_matching(text[index:], trie):
            result += [index]
        index += 1

    return result

def prefix_trie_matching(text, trie):
    v = 0
    while True:
        if not trie[v]:
            return True
        else:
            if not text:
                return False
            symbol = text[0]
            if symbol in trie[v]:
                # print("{}->{}:{}".format(v, trie[v][symbol], symbol))
                v = trie[v][symbol]
                text = text[1:]
            else:
                return False


def build_trie(patterns):
    tree = dict()
    newNode = 0
    for pattern in patterns:
        currentNode = 0
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
    return tree


text = sys.stdin.readline().strip()
n = int(sys.stdin.readline().strip())
patterns = []
for i in range(n):
    patterns += [sys.stdin.readline().strip()]

ans = solve(text, n, patterns)

sys.stdout.write(' '.join(map(str, ans)) + '\n')
