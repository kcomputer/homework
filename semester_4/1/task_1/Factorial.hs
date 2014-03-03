factorial :: Integer -> Integer

factorial 0 = 1
factorial n 
		| n > 0 = n * factorial (n - 1)
		| otherwise error "You've entered a wrong number!"
		
main = do
	n <- readLn
	print(factorial n)