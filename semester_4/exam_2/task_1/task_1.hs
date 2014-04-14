f n = foldl (\y x-> y ++ (replicate ((n - x) `div` 2) ' ') ++ (replicate x '*') ++ "\n") "" list1
		where list1 = ([1,3..n] ++ reverse [1,3..(n-2)])

main = do 
	putStr (f 5)
