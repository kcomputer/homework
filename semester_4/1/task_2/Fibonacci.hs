fibonacci :: Integer -> Integer

fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n 
		| n > 1 = fibonacci (n - 2) + fibonacci (n - 1)
		
main = do
	n <- readLn
	print(fibonacci n)