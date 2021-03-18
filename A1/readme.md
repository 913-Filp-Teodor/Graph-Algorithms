### Teodor Filp / Group 913
# Assignment 1: Graph Representation

## ` DirectedGraph ` base class of the ` WDirectedGraph ` class
##### For the representation of the `DirectedGraph` class I defined a class that has the following structure:

```c++ 
map<int, vector<int>*> to 
```
- A map where the key is a vertex, named the source, and the value, a list containing all the vertices that can be reached directly coming from the source vertex

```c++ 
map<int, vector<int>*> from 
```
- A map where the key is a vertex, named the destination, and the value, a list containing all the vertices from which we can go directly to the destination vertex

##### Our DirectedGraph instance has multiple methods that are used in order to change the graph associated to our instance:

```c++
public DirectedGraph() 
```
- This is the constructor of the DirectedGraph class

```c++
public ~DirectedGraph()
```
- This is the destructor of the DirectedGraph class

```c++
public void insertVertex(int newVertex) 
```
- This method is used in order to add a new vertex to our graph instance.
- Precondition: vertex must not be in the graph. If vertex is already in the graph, then the method throws a ` runtime error `

```c++
public virtual void insertEdge(int source, int destination) 
```
- This method is used in order to add a new edge between two existing vertices of the graph
- Precondition: The source and destination vertices must be in the graph and the edge (source, destination) must not exist. In case the edge is present or one of the given vertices is missing, the method throws a ` runtime error `
- If the precondition is met, the new edge is added to our graph

```c++
 private void setup(int verticesNumber) 
```
- This method is used for the initial setup. It is given a number of vertices, and it creates a record in the ` to ` and ` from ` maps for each of them

```c++
 private void clearMap(map<int, vector<int>*> map) 
```
- This method is used in the destructor for map cleanup

```c++ 
public bool existsEdge(int source, int destination) 
```
- Method checks if a given edge is present. If the edge is present, ` true ` is returned
- Precondition: both vertices must be in the graph

```c++
 public vector<int> getVertices()
```
- Method returns a list containing all the vertices in the graph

```c++ 
public vector<int>::iterator getInboundEdgesBegin(int destination)
```
- Method returns an iterator to the inbound vertices of a given destination vertex. 
- Precondition: Vertex must be in the graph. If the given vertex is not present in the graph then a ` runtime error ` is thrown by the method


```c++
 public vector<int>::iterator getInboundEdgesEnd(int destination)
 ```
- Method returns an iterator to the end of the inbound vertices of a given destination vertex. 
- Precondition: Vertex must be in the graph. If the given vertex is not present in the graph then a ` runtime error ` is thrown by the method

```c++
 public vector<int>::iterator geteOutboundEdgesBegin(int source)
```
- Method returns an iterator to the outbound vertices of a given destination vertex.
- Precondition: Vertex must be in the graph. If the given vertex is not present in the graph then a ` runtime error ` is thrown by the method


```c++
 public vector<int>::iterator getOutboundEdgesEnd(int source)
```
- Method returns an iterator to the end of the outbound vertices of a given destination vertex.
- Precondition: Vertex must be in the graph. If the given vertex is not present in the graph then a ` runtime error ` is thrown by the method

```c++
 public vector<int> getInboundEdges(int destination)
```
- Method returns the list containing all the inbound vertices of the vertex `destination`
- Precondition: Vertex must be in the graph. If the given vertex is not present in the graph then a ` runtime error ` is thrown by the method

```c++
public vector<int> getOutboundEdges(int source)
```
- Method returns the list containing all the outbound vertices of the vertex `destination`
- Precondition: Vertex must be in the graph. If the given vertex is not present in the graph then a ` runtime error ` is thrown by the method
 
```c++
 public virtual void removeEdge(int source, int destination)
```
- Method deletes the existing edge `(source, destination)`
- Precondition: Both of the vertices must be in graph, and also the edge must exist. If either one of the preconditions is not met the method will throw a `runtime error`

```c++
public bool isVertex(int vertex)
```
- Method checks if a given vertex can be found inside the graph

```c++
public int getInDegree(int vertex)
```
- Method computes the in degree of a given vertex
- Precondition: Vertex must be found in the graph. If the vertex is not found, a `runtime error` is thrown

```c++
public int getOutDegree(int vertex)
```
- Method computes the out degree of a given vertex
- Precondition: Vertex must be found in the graph. If the vertex is not found, a `runtime error` is thrown

##### For completing the task in Assignment 1 I extended the `WDirectedGraph` class from the `DirectedGraph`, (W stands for Weighted). It reuses most of the `DirectedGraph` functionality,and only extends already implemented functionality. Additionally, it adds some extra method for handling edges that have a certain cost attached

```c++
public int getEdgeCost(int source, int destination)
```
- Method returns the cost associated to a given edge
- Precondition: Edge must exist. If the edge does not exist the method throws a `runtime error`

```c++
public void updateEdgeCost(int source, int destination, int newCost)
```
- Method updates existing edge's cost
- Precondition: Edge must exist. If edge does not exist, method throws `runtime error`

```c++
public virtual WDirectedGraph* copy()
```
- Method creates an exact copy of the `this` graph instance

##### Graph copy usage:
```c++
#include "WDirectedGraph.h"

int main() {
    
    // create a new graph
    WDirectedGraph *graph = new WDirectedGraph();
    
    // add 2 new vertices
    graph->insertVertex(1);
    graph->insertVertex(2);
    
    // add 2 new edges
    graph->insertEdge(1, 2);
    graph->insertEdge(2, 1);
    
    // create a new copy
    WDirectedGraph *copy = graph->copy();
    
    // assert that the copy was created correcly
    assert(copy != graph) // 'true'
    assert(copy->isVertex(1) == true); // 'true'
    assert(copy->isVertex(2) == true); // 'true'
    assert(copy->existsEdge(1, 2) == true); // true
    assert(copy->existsEdge(2, 1) == true); // true
    
    delete graph;
    delete copy;
    
    return 0;
}
```