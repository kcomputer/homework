import Data.List
import System.IO

interactiveList :: [Int] -> IO () 
interactiveList xs = do
              putStrLn ("0 - exit ")
              putStrLn("1 - add value to sorted list")
              putStrLn("2 - remove value from list")
              putStrLn("3 - print list")
              command <- getLine
              case command of "0" -> return ()
                              "1" -> do   
                                        putStr ("Enter an ineteger value to add: ")
                                        value <- readLn
                                        interactiveList (insert value xs)
                              "2" -> do
                                        putStrLn ("Enter an ineteger value to delete: ")
                                        value <- readLn
                                        interactiveList (delete value xs)
                              "3" -> do
                                        putStr (show xs)
                                        interactiveList xs
                              otherwise -> interactiveList xs
                              
main = do interactiveList []