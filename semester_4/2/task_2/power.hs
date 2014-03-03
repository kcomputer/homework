powerOfTwo1 :: Int -> [Int]
powerOfTwo1 n = map (\x -> 2^x) [0..n]

powerOfTwo2 :: Int -> [Int]
powerOfTwo2 n = take (n + 1) (zipWith (^) [2,2..] [0,1..])
