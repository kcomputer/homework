import Test.QuickCheck


mySum :: Integer -> Integer
mySum n = mySumHelper n 0

mySumHelper :: Integer -> Integer -> Integer
mySumHelper 0  acc = acc
mySumHelper n acc = mySumHelper (n `div` 10) (acc + n `mod` 10)

mySumTest = mySum 11111 == 5

main = quickCheck mySumTest