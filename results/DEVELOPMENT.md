# Development Log

### Week 1
This week, we researched the traversal and algorithms we will be implementing in greater detail to further our understanding of how we should approach the project. We set up our repository by organizing the directories and adding the airport and route data files we will be using. Next, we created a class to parse the CSV files into a vector of vector of strings, where each vector represents a line in the CSV and each string represents a comma separated value. We then had some trouble attempting to compile our project, but we ultimately managed to use CMake to build and make our files. With this, we accomplished our initial weekly goal of setting up our repository and downloading and parsing the dataset.

### Week 2
This week, we met to further research together and discuss what kind of approach we would take when implementing the BFS traversal, Dijkstra's algorithm, and the visual graph. We also created separate classes for Node and Edge objects to facilitate the graph formation. We then finished methods to parse our vector of vectors of strings representing airports into a Node objects, as well as our data on the different routes between airports into Edge objects. We then divided and assigned the work to attempt to implement the BFS traversal and Dijkstra's algorithm.

### Week 3
This week, we were mainly working on coding the BFS traversal and Dijkstra's algorithm, which are their own separate classes. We finished BFS along with its helper methods in the Flight class and wrote its respective test cases. We are almost done with Dijkstra's algorithm. Additionally, we added the catch files to support testing and wrote tests for the Flights and Parser classes that we wrote last week. Lastly, we started discussing we will implement our graphical output. 

### Week 4
This week we finished the Dijkstra algorithm and wrote its test cases and improved the BFS algorithm.  Additionally, we implemented the graphical output by creating a Map class that reads in a file and outputs the result to a file called Output.png.  To create a PNG, we imported the CS225 PNG class.  