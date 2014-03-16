import Test.QuickCheck

bracketsCheck :: String -> Bool

bracketsCheck xs = bracketsCheckHelper xs [0,0,0]

bracketsCheckHelper :: String -> [Integer] -> Bool

bracketsCheckHelper [] acc = acc == [0,0,0]
bracketsCheckHelper (x:xs) acc = case x of
								'(' -> bracketsCheckHelper xs (zipWith (+) [1,0,0] acc)
								')' -> bracketsCheckHelper xs (zipWith (-) [1,0,0] acc)
								'{' -> bracketsCheckHelper xs (zipWith (+) [0,1,0] acc)
								'}' -> bracketsCheckHelper xs (zipWith (-) [0,1,0] acc)
								'[' -> bracketsCheckHelper xs (zipWith (+) [0,0,1] acc)
								']' -> bracketsCheckHelper xs (zipWith (-) [0,0,1] acc)
								otherwise -> bracketsCheckHelper xs acc 

bracketsCheckTest = bracketsCheck "()dsds{d}[]s(dd)" == True
					&& bracketsCheck "((ddw))]" == False

main = quickCheck bracketsCheckTest