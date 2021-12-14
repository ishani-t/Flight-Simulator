# RESULT
We were able to successfully use the OpenFlights dataset to determine the shortest flight distance between two airports and display this path projected onto a world map.  Our goals included implementing the BFS and Dijkstra algorithms to accomplish this, from which we could use the outputs to map out the final graph image. 

### BFS
Starting from a given airport, the BFS algorithm we developed traverses all of the connected, or "reachable" airports.  We implemented this by first finding the index of the starting/root node, determining its respective adjacent nodes, and then visiting them.  We added the root node into a vector that stores the traversal, and used the linear structure of a queue to store the adjacent nodes.  Once we added the adjacent nodes to the queue, we popped the current node from the queue since it had just been visited.

To test the BFS class, we set up a test class to ensure that the BFS algorithm we made stored the steps of the traversal correctly. We split this up into three test cases - Linear, Nonlinear, and a case where a node isn't connected.  For each case, we set up the traversal by manually adding in each airport and path, and verifying that the traversal algorithm visited the nodes in the correct order.  

### Dijkstra
We used Dijkstra's algorithm to accept a Flights data structure and the airport codes for given start and ending airports. We started by finding the airport nodes corresponding to the given airport codes while initializing the maps to store the tentative distances from each airport to infinity and mark all airports as unvisited. Then, from our starting airport, we found the adjacent airports, updated their tentative distances if we found a shorter path, then pushed the resulting airport code and distance to the priority queue. After checking all the neighbors, we marked the current node as visited. We found that with the priority queue, we were able to continue this process with the next closest unvisited airport until we finished. 

We then traversed the map storing the previous node from each node to get the codes representing the shortest path between our given start and ending airports. We were able to test this with a small dataset of nodes and edges and checking that between multiple situations (direct trips, trips that required multiple hops, etc), the returned shortest path was correct.

### Graphical Output
Our graphical output depicts the shortest path between two airports. We began by importing the relevant image classes from the CS 225 folder. Next, we made a Map class that reads in a blank map and draws the lines between the two nodes. The map class takes in a path of strings, and in the main method, we used the output of Dijkstra's as the path to draw. 