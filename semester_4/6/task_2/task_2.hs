import Test.QuickCheck


type Polynomial = [Int]


plusMinus :: (Int -> Int -> Int) -> Polynomial -> Polynomial -> Polynomial
plusMinus f x y = zipWith f (x ++ (take (-lengthDifference) [0,0..])) (y ++ (take (lengthDifference) [0,0..]))
                  where lengthDifference = length x - length y

plus :: Polynomial -> Polynomial -> Polynomial
plus = plusMinus (+)

minus :: Polynomial -> Polynomial -> Polynomial
minus = plusMinus (-)

 

multiply :: Polynomial -> Polynomial -> Polynomial
(multiply) = multiplyHelper 0
    where
        multiplyHelper :: Int -> Polynomial -> Polynomial -> Polynomial
        multiplyHelper _ x [] = []
        multiplyHelper _ [] y = []
        multiplyHelper degree y (x:xs) = plus ((take degree [0,0..]) ++ (map (* x) y)) (multiplyHelper (degree + 1) y xs)


showPolynomial :: Polynomial -> String
showPolynomial [] = "" 
showPolynomial xs = lastElem ++ showPolynomial (init xs)
    where lastElem 
            | x == 1 = temp
            | x == 0 = ""
            | x < 0  = "-" ++ show (abs x) ++ temp
            | otherwise = "+" ++ show (abs x) ++ temp
            where x = last xs
                  temp
                     | (x == 1) && (l == 0) = "+1"
                     | (l == 0) && (x /= 1) = ""
                     | otherwise            = "x^" ++ show l
                       where l = length xs - 1



polynomialTest = (showPolynomial $ multiply [1,1,1,1,1,1] [1,1,1,1]) == "x^8+2x^7+3x^6+4x^5+4x^4+4x^3+3x^2+2x^1+1"
main = quickCheck polynomialTest



