import Control.Monad

richNeighbourFinder:: [Int] -> Maybe Int
richNeighbourFinder [] = Nothing

richNeighbourFinder (x:y:z:xs) = mplus (richNeighbourFinder' x y z) (richNeighbourFinder (y:z:xs))
					where richNeighbourFinder' x y z | (x < y) && (y > z) = Just y 
     						                         | otherwise          = Nothing

