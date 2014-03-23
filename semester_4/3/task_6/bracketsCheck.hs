import Test.QuickCheck
import Data.Maybe

-- | Given an opening bracket, return it's closing counterpart 
expect c = fromJust $ lookup c $ zip "[{(<" "]})>"


check :: String -> Bool
check = check' ""

-- | Checks to see if a String contains only correctly nested brackets.
check' :: String -> String -> Bool
check' s []    = null s

check' s (c:r)
    | (not $ elem c "[]()<>{}")     = check' s r
    | elem c "([{<"                 = check' (expect c:s) r
    | elem c ")]}>" && (not.null) s = (c == head s) && check' (tail s) r
    | otherwise                     = False


bracketsCheckTest = check "()dsds{d}[]s(dd)" == True
					&& check "((ddw))]" == False

main = quickCheck bracketsCheckTest