import Test.QuickCheck

primes :: [Integer]
primes = sieve [2..]
 	where
    	sieve (p:xs) = p : sieve [x|x <- xs, x `mod` p /= 0]

primesTest = take 6 primes == [2,3,5,7,11,13]

main = quickCheck primesTest