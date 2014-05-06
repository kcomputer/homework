import Test.QuickCheck


import Data.Maybe
import Data.List

data Tree a = EmptyTree
            | Node a (Tree a) (Tree a)
            deriving (Show,Eq)
 

foldt f acc EmptyTree = acc
foldt f acc (Node x left right) = foldt f (f x (foldt f acc left)) right


height :: (Tree a) -> Integer
height EmptyTree = 0
height (Node _ left right) = 1 + max (height left) (height right)

size :: Tree a -> Integer
size tree = foldt (\_ y -> y + 1) 0 tree 

empty :: (Ord a) => Tree a -> Bool
empty EmptyTree = True
empty  _  = False
 
contains :: (Ord a) => (Tree a) -> a -> Bool
contains EmptyTree _ = False
contains (Node value t1 t2) x 
	| x == value = True
	| x  < value = contains t1 x 
	| x  > value = contains t2 x
 
-- | Insert an element to tree
insertInTree :: (Ord a) => Tree a -> a -> Tree a
insertInTree EmptyTree x = Node x EmptyTree EmptyTree
insertInTree (Node value t1 t2) x 
	| x == value = Node value t1 t2
	| value  < x = Node value t1 (insertInTree t2 x)
	| value  > x = Node value (insertInTree t1 x) t2
 

 -- | Delete an element from tree
deleteFromTree :: (Ord a) => Tree a -> a -> Tree a
deleteFromTree EmptyTree _ = EmptyTree
deleteFromTree (Node value t1 t2) x 
	| x == value = deleteFromTreeHelper (Node value t1 t2)
	| x  < value = Node value (deleteFromTree t2 x) t2
	| x  > value = Node value t1 (deleteFromTree t2 x)
 
deleteFromTreeHelper :: (Ord a) => Tree a -> Tree a 
deleteFromTreeHelper (Node value EmptyTree t2) = t2
deleteFromTreeHelper (Node value t1 EmptyTree) = t1
deleteFromTreeHelper (Node value t1 t2) = (Node value2 t1 t2) 
	where 
		value2 = leftMostElement t2
 
leftMostElement :: (Ord a) => Tree a -> a
leftMostElement (Node value EmptyTree _) = value
leftMostElement (Node _ t1 _) = leftMostElement t1

-- | Read tree from list
treeFromList :: (Ord a) => [a] -> Tree a
treeFromList [] = EmptyTree
treeFromList (x:xs) = treeFromList' (Node x EmptyTree EmptyTree) xs
	where
		treeFromList' tr [] = tr
		treeFromList' tr (x:xs) = treeFromList' (insertInTree tr x) xs
 
-- | Print tree
inorder :: (Ord a) => Tree a -> [a]
inorder EmptyTree = []
inorder (Node value t1 t2) = inorder t1 ++ [value] ++ inorder t2
 
preorder :: (Ord a) => Tree a -> [a]
preorder EmptyTree = []
preorder (Node value t1 t2) = [value] ++ preorder t1 ++ preorder t2
 
postorder :: (Ord a) => Tree a -> [a]
postorder EmptyTree = []
postorder (Node value t1 t2) = postorder t1 ++ postorder t2 ++ [value]

-- | Tests
binarySearchTreeTest = (inorder $ insertInTree (treeFromList [1,2,3,4,5,6]) 10) == [1,2,3,4,5,6,10]
sizeTest = (size (insertInTree (treeFromList [1,2,3,4,5,6]) 10)) == 7
deleteTest = (inorder $ deleteFromTree (insertInTree (treeFromList [1,2,3,4,5,6]) 10) 2) == [1,3,4,5,6,10]
heightTest = height (treeFromList [1,2,3,4,5,6]) == 6
containsTest = (contains (treeFromList [1,2,3,4,5,6]) 5) == True
