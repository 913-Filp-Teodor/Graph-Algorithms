# Assignment 1: Graph Representation

## ` DirectedGraph ` base class of the ` WDirectedGraph ` class
##### For the representation of the `DirectedGraph` class I defined a class that has the following structure:

##### 1. ` std::map<int, std::vector<int>*> to `
- A map where the key is a vertex, named the source, and the value, a list containing all the vertices that can be reached directly coming from the source vertex
##### 2. ` std::map<int, std::vector<int>*> from `
- A map where the key is a vertex, named the destination, and the value, a list containing all the vertices from which we can go directly to the destination vertex


##### Our DirectedGraph instance has multiple methods that are used in order to change the graph associated to our instance:

##### 1. `public DirectedGraph() `
- This is the constructor of the DirectedGraph class

##### 2. `public ~DirectedGraph() `
- This is the destructor of the DirectedGraph class

##### 3. `public void insertVertex(int newVertex) `
- This method is used in order to add a new vertex to our graph instance.
- If the given vertex is already in the graph, the method throws a ` runtime_error `
- If the given vertex is not in the graph, it is added to the graph

##### 4. ` public virtual void insertEdge(int source, int destination) `
- This method is used in order to add a new edge between two existing vertices of the graph
- This method has a precondition for the 2 vertices to be in the graph and for the nonexistence of the edge. In case the edge is present or one of the given vertices is missing, the method throw a ` runtime_error `
- If the precondition is met, the new edge is added to our graph

##### 5. ` private void setup(int verticesNumber) `
- This method is used for the initial setup. It is given a number of vertices, and it creates a record in the ` to ` and ` from ` maps for each of them

##### 6. ` private void clearMap(std::map<int, std::vector<int>*> map) `
- This method is used in the destructor for map cleanup

##### 7. ` public bool existsEdge(int source, int destination) `
- Method checks if a given edge is present. If the edge is present, ` true ` is returned
- Precondition: both vertices must be in the graph

##### 8. ` public std::vector<int> getVertices()`
- Method returns a list containing all the vertices in the graph

##### 9. ` public std::vector<int>::iterator getInboundEdgesBegin(int destination)`
- Method returns an iterator to the inbound vertices of a given destination vertex. 
- Precondition: Vertex must be in the graph. If the given vertex is not present in the graph then a ` runtime_error ` is thrown by the method


##### 10. ` public std::vector<int>::iterator getInboundEdgesEnd(int destination)`
- Method returns an iterator to the end of the inbound vertices of a given destination vertex. 
- Precondition: Vertex must be in the graph. If the given vertex is not present in the graph then a ` runtime_error ` is thrown by the method

##### 11. ` public std::vector<int>::iterator geteOutboundEdgesBegin(int source)`
- Method returns an iterator to the outbound vertices of a given destination vertex.
- Precondition: Vertex must be in the graph. If the given vertex is not present in the graph then a ` runtime_error ` is thrown by the method


##### 12. ` public std::vector<int>::iterator getOutboundEdgesEnd(int source)`
- Method returns an iterator to the end of the outbound vertices of a given destination vertex.
- Precondition: Vertex must be in the graph. If the given vertex is not present in the graph then a ` runtime_error ` is thrown by the method

##### 13. `public std::vector<int> getInboundEdges(int destination)`
- Method returns the list containing all the inbound vertices of the vertex `destination`
- Precondition: Vertex must be in the graph. If the given vertex is not present in the graph then a ` runtime_error ` is thrown by the method

##### 13. `public std::vector<int> getOutboundEdges(int source)`
- Method returns the list containing all the outbound vertices of the vertex `destination`
- Precondition: Vertex must be in the graph. If the given vertex is not present in the graph then a ` runtime_error ` is thrown by the method
 

