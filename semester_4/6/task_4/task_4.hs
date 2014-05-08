import Test.QuickCheck


import Data.List
import Control.Monad
import Data.Maybe


data Graph = Graph [Int] [((Int, Int), Float)]
            deriving Show

data Path = Path Int Float Int
            deriving(Eq,Show)

instance Ord Path where
    compare (Path _ x _) (Path _ y _) = compare x y


infinity = 1.0 / 0.0

dijkstra :: Int -> Graph -> [(Int,Float)]
dijkstra vertex (Graph vs es) = unwrapResult $ goDijkstra initialPath []
        where 
              unwrapResult :: [Path] -> [(Int,Float)]
              unwrapResult [] = []
              unwrapResult ((Path i d pd):ps) = (i,d): unwrapResult ps

              initialPath :: [Path]
              initialPath = map (\v -> Path v (if v == vertex then 0.0 else infinity) v) vs

              goDijkstra :: [Path] -> [Path] -> [Path]
              goDijkstra [] visited = visited
              goDijkstra unvisited visited = 
                      let nearestVertex = minimum unvisited
                          newVisited = nearestVertex : visited
                          newUnvisited = (map (\v -> min v (getPath nearestVertex v)) . delete nearestVertex) unvisited

                          getPath :: Path -> Path -> Path
                          getPath (Path nearestId nearestD _) (Path vId _ _) = Path vId (nearestD + (distanceBetween nearestId vId)) nearestId
                      in goDijkstra newUnvisited newVisited

              distanceBetween :: Int -> Int -> Float      
              distanceBetween currentVertex anotherVertex = fromJust $ mplus (lookup (currentVertex, anotherVertex) es) (Just infinity)


-- Example of Graph from Wiki
exampleGraph :: Graph
exampleGraph = Graph [1,2,3,4,5,6] [((1,2),7.0),((2,1),7.0),((1,3),9.0),((3,1),9.0),((1,6),14.0),((6,1),14.0),((3,4),11.0),((4,3),11.0),((3,6),2.0),((6,3),2.0),((6,5),9.0),((5,6),9.0),((4,5),6.0),((5,4),6.0)]


dijkstraTest = (dijkstra 1 exampleGraph) == [(5,20.0),(4,20.0),(6,11.0),(3,9.0),(2,7.0),(1,0.0)]




main = quickCheck dijkstraTest