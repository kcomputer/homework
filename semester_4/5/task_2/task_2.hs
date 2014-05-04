import Test.QuickCheck

all1 :: (Eq a) => (a -> Bool) -> [a] -> Bool
all1 predicate xs = all predicate xs

all2 :: (Eq a) => (a -> Bool) -> [a] -> Bool
all2 predicate xs = and $ map predicate xs


allTest = all1 (\x -> x > 2) [5,6,7] == all2 (\x -> x > 2) [4,5,6,7,8,9,10] 


main = quickCheck allTest