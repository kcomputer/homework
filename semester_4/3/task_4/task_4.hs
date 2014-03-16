import Test.QuickCheck
import Data.List
import Data.Ord



maxNeighboursSum :: [Int] -> Int
maxNeighboursSum (x:xs) = (maxIndex $ sumsList) + 1
	where 
		sumsList = zipWith (+) (x:xs) xs
		maxIndex ::  Ord a => [a] -> Int
		maxIndex = fst . maximumBy (comparing snd) . zip [0..]


maxNeighboursSumTest = maxNeighboursSum [1, 5, 6, 2] == 2

main = quickCheck maxNeighboursSumTest