data Trie v l = Node {
    rootLabel :: l,
    subForest :: Map v (Trie v l)
}

main = do
    total <- readLn :: IO Int
    rawPatterns <- getContents
    let patterns = lines rawPatterns
    putStr $ show patterns