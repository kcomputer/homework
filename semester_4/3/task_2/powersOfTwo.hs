import Test.QuickCheck
powersOfTwo2 = zipWith (^) [2,2..] [0,1..]


powersOfTwo2Test = (take 6 powersOfTwo2) == [1,2,4,8,16,32]

main = quickCheck powersOfTwo2Test