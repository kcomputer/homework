
mySpecialFunc :: Floating a => [a] -> a
mySpecialFunc xs = mySpecialFuncHelper 0 1 xs

mySpecialFuncHelper :: Floating a => a -> a -> [a] -> a
mySpecialFuncHelper acc cosAcc [] = acc / cosAcc
mySpecialFuncHelper acc cosAcc (x:xs) = mySpecialFuncHelper (acc + x) (cosAcc * (cos x)) xs