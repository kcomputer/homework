import Test.QuickCheck

positionOfElement :: Eq a => a -> [a] -> Int
positionOfElement a xs 
	| elem a xs = 1 + (length $ takeWhile (/= a) xs)
	| otherwise = -1

positionOfElementTest = positionOfElement 6 [1, 5, 6, 2] == 3

main = quickCheck positionOfElementTest