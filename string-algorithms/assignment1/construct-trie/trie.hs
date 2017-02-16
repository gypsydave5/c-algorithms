import qualified Data.Map.Strict as M
import Data.Maybe (fromMaybe)

main = do
  contents <- getContents
  let t = EmptyTrie
  let xs = tail $ lines contents
  let result = foldl (flip insert) t xs
  putStr (show result)

data Trie
  = Trie Int
         (M.Map Int (M.Map Char Int))
  | EmptyTrie

instance Show Trie where
  show EmptyTrie = ""
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
insert "" (Trie i m) = Trie i m
insert xs EmptyTrie = insert' n xs EmptyTrie
insert (x:xs) (Trie i m) = insert' 0 (x:xs) (Trie i m)

insert' :: Int -> String -> Trie -> Trie
insert' n "" t = t
insert' n xs EmptyTrie = insert' n xs (Trie 0 M.empty)
insert' n (x:xs) (Trie i m)
  | M.notMember n m =
    insert' (succ n) xs (Trie (succ i) (M.insert i (M.singleton x (succ i)) m))
  | otherwise = insert' (next n x m) xs (Trie i (newMap n x m))
  where
    innerMap = M.findWithDefault M.empty
    next n x m = M.findWithDefault (succ n) x $ (innerMap n m)
    newMap n x m
      | M.notMember x (innerMap n m) =
        M.insert n (M.insert x (succ n) (innerMap n m)) m
      | otherwise = m



stuff =
  (Trie
     0
     (M.fromList
        [ (5, (M.fromList [('a', 5), ('c', 6)]))
        , (6, (M.fromList [('c', 7), ('z', 9)]))
        ]))