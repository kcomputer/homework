
data PrintedThing = Book {name :: String, autor :: String, price :: Int}
				| Magazine {name :: String, year :: String, number :: Int, price :: Int}


totalPrice :: [PrintedThing] -> Int
totalPrice xs = totalPriceHelper 0 xs

totalPriceHelper :: Int -> [PrintedThing] -> Int
totalPriceHelper acc [] = acc
totalPriceHelper acc ((Book _ _ price):xs) = totalPriceHelper (acc + price) xs
totalPriceHelper acc ((Magazine _ _ _ price):xs) = totalPriceHelper (acc + price) xs