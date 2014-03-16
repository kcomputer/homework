import Test.QuickCheck

nextNum :: Int -> Int
nextNum 1 = 7
nextNum 7 = 9
nextNum 9 = 11
nextNum x 
	| lastDigit == 9 = (nextNum allButLastDigit) * 10 + 1
	| otherwise = allButLastDigit * 10 + nextNum lastDigit
	where 
		lastDigit = x `mod` 10
		allButLastDigit = x `div` 10

myList = 1 : map nextNum myList


myListTest = take 10 myList == [1,7,9,11,17,19,71,77,79,91]

main = quickCheck myListTest

