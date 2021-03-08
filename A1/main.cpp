#include <iostream>
#include <fstream>
#include "DirectedGraph.h"

int main() {
    DirectedGraph graph;
    std::ifstream read;
    read.open("data.txt");
    graph.loadFile(read);
//    graph.insertEdge(0, 2);
    graph.insertVertex(4);
    auto vertices = graph.getVertices();
    for (auto vertex: vertices) {
        std::cout << vertex << " ";
    }
    graph.removeVertex(1);
    std::cout << graph.getInDegree(2);

    return 0;
}
