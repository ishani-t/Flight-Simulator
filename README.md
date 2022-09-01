# CS225 Final Project - Open Flights Dataset
Final Project for rhuang25-itaraf2-tu11-nealt2


```
module load llvm/6.0.1
make
```

Then, you can run
```
./flight_sim
```

This will allow you to run the executable containing our main method, which will allow you to find the path between any two airports.

# Run Tests

To run our tests, navigate to nagigate to the 'rhuang25-itaraf2-tu11-nealt2' folder. Open a terminal and run:

```
module load llvm/6.0.1
make test
```

Then, you can run
```
./test
```

We mainly tested two of our algorithms. 
For BFS, we tested a linear path (each path directs immediately to the next), a regular BFS traversal, and a graph with disconnected components (to ensure it only counts designated nodes).
For Dijkstra's Algorithm, we tested a direct flight, a flight with one layover, a flight with multiple hops, and a route where there is no path.
Lastly, we tested our parsers to make sure they interpreted input files correctly.




# Navigating our CodeBase

We downloaded our dataset at the following link:  [Open Flights](https://openflights.org/data.html)
In our repository, all data files (airports and routes) can be found in the data subfolder.

All our algorithm implementation was done in the src folder. 
- Parser.h and Parser.cpp reads in a datafile and parses it into a two-dimensional vector of strings.
- Flights.h and Flights.cpp accepts the parsed 2D vectors of airports and routes to create vectors of Nodes and Edges (which are defined in Node.h and Edge.h respectively).
- BFS.h and BFS.cpp implement our BFS traversal
- Dijkstra.h and Dijkstra.cpp implement Dijkstra's algorithm to find the shortest path between two airport nodes.
- Map.h and Map.cpp reads a vector of IATA airport codes and draws their path onto a PNG file using CS225's relevant image classes (taken from our MPs).


Our tests folder runs our tess - read more about our tests in the 'Run Tests' portion of this document.


Our results are all stored in the results subfolder.
This is where you can find our final project writeup, our final presentation in video format, and our Output.PNG, which prints out the image of the most recently run flight route.


### Group
This poject was created by:
* itaraf2: Ishani Tarafdar
* rhuang25: Rachel Huang
* nealt2: Neal Tinaikar
* tu11: Sabrina Tu 
