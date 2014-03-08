import Test.QuickCheck

bracketsCheck :: String -> Bool

bracketsCheck xs = bracketsCheckHelper xs 0

bracketsCheckHelper :: String -> Int -> Bool

bracketsCheckHelper [] acc = acc == 0
bracketsCheckHelper (x:xs) acc = case x of
								'(' -> bracketsCheckHelper xs (acc + 1)
								')' -> bracketsCheckHelper xs (acc -1)
								otherwise -> bracketsCheckHelper xs acc 

bracketsCheckTest = bracketsCheck "()dsdsds(dd)" == True
					&& bracketsCheck "((ddw" == False

main = quickCheck bracketsCheckTest