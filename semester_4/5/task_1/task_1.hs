import Control.Monad
import Control.Applicative
import Data.List

helperFunc :: Int -> [Int] -> [[Int]]
helperFunc 1 xs = group xs
helperFunc n xs = (:) <$> xs <*> helperFunc (n-1) xs

helperFunc2 :: Int -> Int -> [[Int]]
helperFunc2 n 1 = helperFunc 1 [1..n]
helperFunc2 n m = (helperFunc m [1..n]) ++ (helperFunc2 n (m-1))
  
sumPartition :: Int -> [[Int]]
sumPartition  n =  filter (\x -> n == sum x) helperList
  where helperList = helperFunc2 n n




















