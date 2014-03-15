import Test.QuickCheck

func1 x l = map (\y -> y*x) l 


--  Applying eta conversion to omit argument l
func2 x = map (\y -> y*x)


-- Applying eta conversion in lambda (\y -> y * x)
func3 x = map (*x)


-- Making composition
func4 x = map.(*) x


--  Applying eta conversion to omit argument x
func5 = map.(*)



funcTest = func1 2 [1,2,3,4] == func5 2 [1,2,3,4] 


main = quickCheck funcTest
