import Test.QuickCheck
import Data.Maybe


data Tree = EmptyTree
           | Node Char Tree Tree
           deriving (Eq, Show)

showTree :: Tree -> String
showTree EmptyTree = "e"
showTree (Node x leftTree rightTree) = 'n':x:((showTree leftTree) ++ (showTree rightTree))

readTree :: String -> Maybe Tree
readTree str = parse >>= (\x -> if ((snd x) /= "" ) then Nothing else return (fst x))
    where parse = parse' str
            where 
            	parse' :: String -> Maybe (Tree, String)
            	parse' ('e':xs)   = return (EmptyTree, xs)
                parse' ('n':x:xs) = parse' xs >>= (\z -> parse' (snd z) >>= (\y -> return (Node x (fst z) (fst y), (snd y))))
                parse' _          = Nothing


treeTest = (showTree $ fromJust $ readTree "n1n1eee") == "n1n1eee"

main = quickCheck treeTest