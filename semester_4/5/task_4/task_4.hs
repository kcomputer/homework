import Control.Monad

listProduct :: Int -> [Int]
listProduct n = [1..n] >>= \x -> [1..n] >>= \y -> [x * y]


main = do
		putStrLn (show $ listProduct 3)