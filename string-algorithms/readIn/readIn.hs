type Pair = (Int, Int)

main = do
  contents <- getContents
  let result = showPairs contents
  putStr (show (length result))
  putStr result

showPairs :: String -> String
showPairs input = unlines $ map show pairs
    where pairs = map pair (lines input)

pair :: String -> Pair
pair xs = let (a:_:b:_) = map (:[]) xs
          in (read a, read b)