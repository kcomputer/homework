import Test.QuickCheck

palindromeChecker :: (Eq a) => [a] -> Bool
palindromeChecker xs = xs == (reverse xs)

palindromeCheckerTest = 
    palindromeChecker "abccba" == True
    && palindromeChecker "11115" == False


main = quickCheck palindromeCheckerTest