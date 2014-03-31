import Test.QuickCheck

uniquenessСhecker :: Eq a => [a] -> Bool
uniquenessСhecker xs = length xs == (length ( takeWhile (/= head xs) (tail xs)) + 1)


uniquenessСheckerTest = uniquenessСhecker [1,2,3] == True

main = quickCheck uniquenessСheckerTest