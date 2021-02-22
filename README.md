# Graph search algorithms
This project includes a generic server, containing both a serial as well as a concurrent server. Caching functionality prevents from recomputing solutions to problem instances that were already solved. <br>
Specifically, the specific problem that the server solves is finding the shortest path in a weighted graph (specifically, in a matrix) between two nodes.
The following algorithms were implemented and their results were compared: BFS, DFS, Dijkstra and A* and Best First Search. 
A strong emphasis was put on decoupling the server functionality from the concrete problem in hand. Additionaly, the bridge design pattern was used to decouple the various 
algorithms from the search problem, regardless of the concrete representation of the problem as long as it implements the Searchable interface.
