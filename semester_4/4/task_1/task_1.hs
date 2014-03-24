import Test.QuickCheck
import Data.Maybe

data Tree a = Empty
            | Node a (Tree a) (Tree a)
                      deriving (Show, Eq) 
-- | Given predicate and tree, returns a value wrapped in Maybe
searchInTree :: Eq a => (a -> Bool) -> Tree a -> Maybe a
searchInTree _ Empty = Nothing
searchInTree predicate (Node x left right) 
						| predicate x = Just x
						| otherwise = if leftSearch == Nothing
											then
												searchInTree predicate right 
											else
												leftSearch
										    where 
										    	leftSearch = searchInTree predicate left

-- | Sample predicate
func :: (Eq a, Num a) => a -> Bool
func a = a == 3

sampleTree = Node 1 (Node 2 (Node 3 Empty Empty) Empty) (Node 4 (Node 5 (Node 6 Empty Empty) Empty) Empty)

myTest = searchInTree func sampleTree == Just 3

main = quickCheck myTest