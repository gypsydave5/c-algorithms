import qualified Data.Map.Strict as M
import Data.Maybe (fromMaybe)

data Trie =
  Trie Int
       (M.Map Int (M.Map Char Int))

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

stuff =
  (Trie
     0
     (M.fromList
        [ (5, (M.fromList [('a', 5), ('c', 6)]))
        , (6, (M.fromList [('c', 7), ('z', 9)]))
        ]))