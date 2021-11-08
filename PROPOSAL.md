## Final Project Proposal (rhuang25-itaraf2-tu11-nealt2)


### Leading Question

Our group plans to utilize the open flights dataset to determine the shortest flight distance between two airports and display this path projected onto a world map for easy visualization.


### Data Acquisition and Processing
We plan to use the OpenFlights dataset (https://openflights.org/data.html). 

From the website, we will download airports.dat to give us to coordinates and names of all the airports we will be using for our project. This will be particularly useful for the visualization, which requires locations of all the airports.
We will also download routes.dat, which will provide us with source airports, destination airports, and airlines. 
We will create a graph which treats each airport as a node and the flights between them as edges, using the distance between the airports as weights.




### Graph Algorithms

#### BFS Traversal
We will use a breadth-first search to traverse the graph and search for airports. 

#### Dijkstra Shortest Path
The Dijkstra algorithm will be used to determine the shortest paths between two airports. We aim to calculate the distance of the shortest path between any two given airports, and allow users to choose any of the given airports. 

#### Graphical Output
Lastly, we will try to visualize flights in a PNG. In terms of data processing, we will have to find a way to place airports on an image of a map - this can probably be done using math to calculate how far up/down and left/right on the image the airport's dot should be. The dataset provides coordinates for the airports, so we can figure out how to process that. We might even consider making a gif or video of any given path. 


### Timeline

11/7 - 11/14:
- download dataset
- set up repository structure and organization
- any necessary preprocessing of the data files, try to get the data files parsed into a sort of graph structure
- start BST search - at least finish any helper methods, get it mostly working.
11/15 - 11/21
- implment BST search tests (if not done already)
- implement dijkstra test
- implement dijkstra algorithm to find shortest path

11/22 - 11/28 - Thanksgiving break. 
- We will use this week to catch up on any missed commits
- research and plan implementation of the graph visualization
- start developing the graph visualization portion together.
- make sure data for airport coordinates on picture is figured out.
- Basic preparations for mid project check-in.

11/29-12/5
-  Mid Project Checkin occurs this week
- finish up working on the graph visualization part
- implement some sort of way to test this

12/5 - 12/12 Last week of work
- work on user interaction - have way for user to interact with models, input their choice of airports etc
- finish up documentation
- finalize any test and algorithms that have not been finished
- Lets plan to submit by 12/12 

12/13 - Final Project Due Date


