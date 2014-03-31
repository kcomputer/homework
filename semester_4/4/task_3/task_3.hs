import Test.QuickCheck

func1 :: (Integral a) => [a] -> Int
func1 xs = length $ filter even xs

func2 :: (Integral a) => [a] -> a
func2 xs = sum (map func2Helper xs)
				where func2Helper x | x `mod` 2 == 0 = 1
									| otherwise = 0

func3 :: (Integral a) => [a] -> Int
func3 xs = foldr (\x acc -> if (even x) then acc + 1 else acc) 0 xs



myTest = func1 [1,2,3,4] == 2
	  && func2 [1,2,3,4] == 2
	  && func3 [1,2,3,4] == 2

main = quickCheck myTest