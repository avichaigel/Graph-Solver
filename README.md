# Solver

This program is a server that receives from a multiple clients at a time (hence the server is called Parallel Server) a problem - in our case a matrix with costs (weights) for each entry, and start and end point - and sends back a solution - in our case the steps needed to be taken in order to get from start to end by the cheapest way possible.

At first we create a File Cache Manager that connects between a problem to a solution file in our disk using a hash map.
Every time we run the program it checks all the available solutions we already have on our disk and upload our map with these solutions.
Then we call a namespace named "boot", and run our program from there. We go to the server, which has a timeout of 2 minutes, and if a client doesn't connect within those 2 minutes, the program ends. When a client is connected, a problem, a matrix, is received by the server, which then sends it to the ClientHandler implementing class, which is called MyMatrixClientHandler  **Avichai TO COMPLETE**

Once the cache manager gets a problem,  it checks if it has a solution (that we already solved in previous runs of the program). if the solution is found, we access to the its file and return it. otherwise we send it to our algorithms to solve and we return the best solution.
The algorithms that we use are Astar, BestFirstSearch, BreadthFirstSearch, DepthFirstSearch (and the matching files are: Astar.h, BestFS.h, BFS.h, DFS.h)

# Design patterns used in code

Generics - our code can be used as a guideline to any kind of problem solving implementation.  we use generic interfaces for the server and the client side, as well as to the solver, the cache manager, the problems and the solutions.

Bridge - **Avichai TO COMPLETE**

# Code Files
**Avichai TO COMPLETE HIS PART**

*Generic side:*

**CacheManager.h** - An interface that contains insert and get virtual methods for files send and receive
**State.h** - Represent a state of each part of the problem (in our program it's used as the matrix i,j index, and implemented in the file Point.h)
**ISearchable.h** - An interface that contains virtual methods for any searching problem (in our case the matrices) .
**Searcher.h** - An interface that contains virtual methods for any searching problem solver (in our case the algorithms).



*Implementation side:*

**FileCacheManager.h** -  Read and Write solutions from/to the disk. if it's not the first run of the program it reads the old solutions and upload them to its inner hash map. 
**BestFS.h** - solves the matrix problem using an implementation of Best First Search algorithm.
**Astar.h** - solves the matrix problem using an implementation of A Star algorithm.
**BFS.h** - solves the matrix problem using an implementation of Breadth First Search algorithm.
**DFS.h** - solves the matrix problem using an implementation of Depth First Search algorithm.




# Compiling the Code

To compile from the command line:
g++ -std=c++11 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread

# Running the Program
 
For the program to run well, first we compile and then run the program. Once we see "Server is now listening...", we open and run the (in serial or in parallel) our problems to solve (matrices) , which should connect with our program, through the server we opened. Once we have a  connection between the simulator and our program, our program returns to each problem its solution.
