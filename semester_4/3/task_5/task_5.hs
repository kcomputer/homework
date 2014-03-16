import Test.QuickCheck

data Tree a = Empty 
            | Node a (Tree a) (Tree a)
			deriving (Show)


height :: (Tree a) -> Integer
height Empty = 0
height (Node _ leftTree rightTree) = 1 + max (height leftTree) (height rightTree) 


closestLeafLevel :: (Tree a)-> Integer
closestLeafLevel Empty = 0
closestLeafLevel (Node _ leftTree rightTree) = 1 + min (closestLeafLevel leftTree) (closestLeafLevel rightTree) 


sampleTree = Node 1 (Node 2 (Node 3 Empty Empty) Empty) (Node 4 (Node 5 (Node 6 Empty Empty) Empty) Empty)

myTest = height sampleTree == 4
	  && closestLeafLevel sampleTree == 2

main = quickCheck myTest
