import qualified Data.Map.Strict as M
import Data.Maybe (fromMaybe)

data Trie
  = Trie Int
         (M.Map Int (M.Map Char Int))
  | EmptyTrie

instance Show Trie where
  show (Trie _ m) =
    let al = M.assocs m
        da = map (\(i, m') -> (i, M.assocs m')) al :: [(Int, [(Char, Int)])]
        ls =
          foldr1 (++) $
          map
            (\(i, xs) ->
                unlines $
                map (\(c, i') -> show i ++ "->" ++ show i' ++ ":" ++ [c]) xs)
            da
    in ls

insert :: String -> Trie -> Trie
insert "" (Trie _ m) = Trie 0 m
insert xs EmptyTrie = insert xs (Trie 0 M.empty)
insert (x:xs) (Trie i m)
  | M.notMember i m =
    insert xs (Trie (next i x m) (M.insert i (M.singleton x (succ i)) m))
  | otherwise = insert xs (Trie (next i x m) (newMap i x m))
  where
    innerMap = M.findWithDefault M.empty
    next i x m = M.findWithDefault (succ i) x $ (innerMap i m)
    newMap i x m
      | M.notMember x (innerMap i m) =
        M.insert i (M.insert x (succ i) (innerMap i m)) m
      | otherwise = m

stuff =
  (Trie
     0
     (M.fromList
        [ (5, (M.fromList [('a', 5), ('c', 6)]))
        , (6, (M.fromList [('c', 7), ('z', 9)]))
        ]))