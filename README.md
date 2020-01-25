
# Solver

This program is a server that receives from a multiple clients at a time (hence the server is called Parallel Server) a problem - in our case a matrix with costs (weights) for each entry, and start and end point - and sends back a solution - in our case the steps needed to be taken in order to get from start to end by the cheapest way possible.

At first we create a map that ---- **OFIR TO COMPLETE**
Then we call a namespace named "boot", and run our program from there. We go to the server, which has a timeout of 2 minutes, and if a client doesn't connect within those 2 minutes, the program ends. When a client is connected, a problem, a matrix, is received by the server, which then sends it to the ClientHandler implementing class, which is called MyMatrixClientHandler

# Code Files

**connectCommand** *(client)* **-** Opens a socket to connect as a client to the simulator, and sends the socket identifier to the Symbol Table class.
**openServerCommand** *(server)* **-** Opens a socket to connect to the simulator as a server. Opens a thread that runs a function that listens constantly to the simulator, updating values it receives from it.
**Lexer -** Splits the content of the file into tokens.
**Parser -** Runs through the lexer, and associates each line in the original file, to a specific command.
**Var -** Each variable is a Var object, and has the fields: name, sim (=path), direction, and value.
**symTable** *(Symbol Table)* **-** Holds two maps: uiMap- key=name of the variable, value= its Var object. siMap- key= path, value= its var object. 
**ex1** *(Interpreter)* **-** Translates a mathematical expression into a double.
**Expression.h -** Interface for ex1.
**Exp -** Takes an expression with variables, assigns them their value from the map, and uses ex1 to solve them.
**Flag.h -** Singleton that holds a flag, which is used to determine whether the file is fully parsed or not (used in the server while loop).
**Substring -** Creates a substring, with a given delimiter.
**Mutex -** Holds a singleton mutex object.


## Design patterns used in code

Bridge - 

# Downloads

We need to download and install the application "FlightGear". In addition, we need a text file with the code, which will be one of the arguments, and a xml file with all the variable names in the simulator, which we will put in the usr/share/games/flightfear/Protocol folder.

## Installing FlightGear

Instructions for downloading can be found on the website  https://www.flightgear.org/download/main-program/

# Compiling the Code
 
To compile, we need to provide a text file that lists all of the commands for the plane to be able to fly. It will be provided as a program argument.

To compile from the command line:
g++ -std=c++11 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread

# Running the Program
 
For the program to run well, first we compile and then run the program. Once we see "Server is now listening...", we open and run the FlightGear application, which should connect with our program, through the server we opened. Once we have a  connection between the simulator and our program, the plane should start to move, and shortly after, takeoff and fly. 
<!--stackedit_data:
eyJoaXN0b3J5IjpbMjExMDc4NjY0N119
-->
<!--stackedit_data:
eyJoaXN0b3J5IjpbNjU3NDA1NjkwXX0=
-->