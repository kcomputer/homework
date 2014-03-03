import Test.QuickCheck

myReverseList :: [a] -> [a]

myReverseList [] = []

myReverseList (x:xs) = myReverseListHelper (x:xs) []
	where 
		  myReverseListHelper :: [a] -> [a] -> [a]
		  myReverseListHelper []  x = x
		  myReverseListHelper (x:xs) bufferList = myReverseListHelper xs (x:bufferList)


test_myReverseList :: [Int] -> Bool
test_myReverseList xs = myReverseList xs == reverse xs


main = quickCheck test_myReverseList