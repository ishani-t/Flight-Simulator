# RESULT
We were able to successfully use the OpenFlights dataset to determine the shortest flight distance between two airports and display this path projected onto a world map.  Our goals included implementing the BFS and Dijkstra algorithms to accomplish this, from which we could use the outputs to map out the final graph image.  

### BFS
Starting from a given airport, the BFS algorithm we developed traverses all of the connected, or "reachable" airports.  We implemented this by first finding the index of the starting/root node, determining its respective adjacent nodes, and then visiting them.  We added the root node into a vector that stores the traversal, and used the linear structure of a queue to store the adjacent nodes.  Once we added the adjacent nodes to the queue, we popped the current node from the queue since it had just been visited.

To test the BFS class, we set up a test class to ensure that the BFS algorithm we made stored the steps of the traversal correctly. We split this up into three test cases - Linear, Nonlinear, and a case where a node isn't connected.  For each case, we set up the traversal by manually adding in each airport and path, and verifying that the traversal algorithm visited the nodes in the correct order.  

### Dijkstra