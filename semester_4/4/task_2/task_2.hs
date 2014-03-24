import Test.QuickCheck

data Tree a = Empty 
            | Node a (Tree a) (Tree a)
			deriving (Show)


foldt f acc Empty = acc
foldt f acc (Node x left right) = foldt f (f x (foldt f acc left)) right


sampleTree = Node 1 (Node 2 (Node 3 Empty Empty) Empty) (Node 4 (Node 5 (Node 6 Empty Empty) Empty) Empty)

myTest = foldt (+) 0 sampleTree == 21

main = quickCheck myTest