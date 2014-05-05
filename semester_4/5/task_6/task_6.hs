import Test.QuickCheck

data Expression = Variable
                | Constant Int
                | Addition Expression Expression
                | Mulltiply Expression Expression
		        | Power Expression Int


derivative :: Expression -> Expression	  
derivative (Constant _) = Constant 0
derivative Variable = Constant 1
derivative (Addition a b) = Addition (derivative a) (derivative b)
derivative (Mulltiply a b) = Addition (Mulltiply (derivative a) b) (Mulltiply a (derivative b))
derivative (Power a 0) = (Constant 0)
derivative (Power a 1) = (Constant 1)
derivative (Power a b) = Mulltiply (Constant b) (Power a (b - 1))


simplify :: Expression -> Expression
simplify (Addition (Constant a) (Constant b)) =  (Constant (a + b))
simplify (Addition (Constant 0) b) =  simplify b
simplify (Addition a (Constant 0)) = simplify a
simplify (Addition a b) = Addition (simplify a) (simplify b)
simplify (Mulltiply (Constant a) (Constant b)) =  (Constant (a * b))
simplify (Mulltiply (Constant 0) b) = (Constant 0)
simplify (Mulltiply a (Constant 0)) = (Constant 0)
simplify (Mulltiply (Constant 1) b) = simplify b
simplify (Mulltiply a (Constant 1)) = simplify a
simplify (Mulltiply a b) = Mulltiply (simplify a) (simplify b)
simplify (Power a 1) = simplify a
simplify (Power a 0) = (Constant 1)
simplify (Power (Constant a) b) = (Constant (a^b))
simplify (Power a b) = Power (simplify a) b
simplify Variable = Variable
simplify (Constant a) = (Constant a)


showExpression :: Expression -> String
showExpression (Constant a) = show a
showExpression (Variable) = "x"
showExpression (Addition a b) = "(" ++ (showExpression a) ++ " + " ++ (showExpression b) ++ ")"
showExpression (Mulltiply a b) = (showExpression a) ++ " * " ++ (showExpression b)
showExpression (Power a b) = (showExpression a) ++ "^" ++ (show b)


derivativeTest = (showExpression $ simplify $ derivative $ simplify (Addition (Power (Addition (Variable) (Constant 5)) 2) (Power (Constant 2) 2))) == "2 * (x + 5)"

main = quickCheck derivativeTest