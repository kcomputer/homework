import Control.Applicative
import Data.List


specialList :: Int -> [[Int]]
specialList 1 = [[1], [2], [3]]
specialList n = (:) <$> [1,2,3] <*> specialList (n-1)
