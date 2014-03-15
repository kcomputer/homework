import Test.QuickCheck
powersOfTwo2 = 1: map (*2) powersOfTwo2


powersOfTwo2Test = (take 6 powersOfTwo2) == [1,2,4,8,16,32]

main = quickCheck powersOfTwo2Test