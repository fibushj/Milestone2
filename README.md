# Graph search algorithms
This project includes a generic server, containing both a serial as well as a concurrent server. Caching functionality prevents from recomputing solutions to problem instances that were already solved. <br>
Specifically, the specific problem that the server solves is finding the shortest path in a weighted graph (specifically, in a matrix) between two nodes. <br>
The following algorithms were implemented and their results were compared: BFS, DFS, Dijkstra and A* and Best First Search. <br><br>
A strong emphasis was put on decoupling the server functionality from the concrete problem in hand. Additionaly, the bridge design pattern was used to decouple the various 
algorithms from the search problem, regardless of the concrete representation of the problem as long as it implements the Searchable interface. <br><br>

The four algorithms were run on a benchmark of 10 matrices. Following are the results: <br>


![alt text](https://github.com/fibushj/graph-search-algorithms/blob/master/comparisons/num_nodes.png) <br> <br>
![alt text](https://github.com/fibushj/graph-search-algorithms/blob/master/comparisons/path_cost.png)
