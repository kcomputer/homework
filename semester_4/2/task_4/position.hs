posOfN :: [Int] -> Int -> Int
posOfN xs n = length (takeWhile (/= n) xs) + 1