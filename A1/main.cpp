#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <chrono>

#include "WDirectedgraph.h"

WDirectedGraph *graph;

void printMenu() {
  std::string menu = "\n\n"
                     "1. Get number of vertices \n"
                     "2. Get print the vertices \n"
                     "3. Check if edge exists between 2 vertices \n"
                     "4. Get the in degree of a given vertex \n"
                     "5. Get the out degree of a given vertex \n"
                     "6. Parse the set of outbound edges of a specified vertex \n"
                     "7. Parse the set of inbound edges of a specified vertex \n"
                     "8. Get the cost of an edge \n"
                     "9. Update the cost of an edge \n"
                     "10. Remove vertex \n"
                     "11. Remove edge \n"
                     "12. Add vertex \n"
                     "13. Add edge \n"
                     "14. Save graph \n"
                     "15. Load graph \n"
                     "16. Generate graph \n"
                     "17. Exit \n";

  std::cout << menu;
};

void getNumberOfVertices() {
    std::cout << "Number of vertices is: " << graph->getVertices().size() << std::endl;
}

void printVertices() {
    const auto vector = graph->getVertices();
    for (auto vertex: vector) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
}

void checkEdgeExistence() {
    int src, dest;
    std::cout << "Enter the source and destination vertices: ";
    std::cin >> src >> dest;

    bool exists = graph->existsEdge(src, dest);
    std::cout << "Edge between " << src << " and " << dest << (exists ? " exists" : " does not exist") << std::endl;
}

void getVertexInDegree() {
    int src;
    std::cout << "Enter the vertex for which to compute in degree: ";
    std::cin >> src;
    int degree = graph->getInDegree(src);
    std::cout << "The in degree of the vertex " << src << " is: " << degree << std::endl;
}

void getVertexOutDegree() {
    int src;
    std::cout << "Enter the vertex for which to compute out degree: ";
    std::cin >> src;
    int degree = graph->getOutDegree(src);
    std::cout << "The out degree of the vertex " << src << " is: " << degree << std::endl;
}

void getOutboundEdges() {
    int src;
    std::cout << "Enter the vertex for which to list outbound edges: ";
    std::cin >> src;

    auto it = graph->getOutboundEdgesBegin(src);
    while(it != graph->getOutboundEdgesEnd(src)) {
        std::cout << src << " -> " << *it << std::endl;
        it ++;
    }
}

void getInboundEdges() {
    int dest;
    std::cout << "Enter the vertex for which to list inbound edges: ";
    std::cin >> dest;

    auto it = graph->getInboundEdgesBegin(dest);
    while(it != graph->getInboundEdgesEnd(dest)) {
        std::cout << *it << " -> " << dest << std::endl;
        it ++;
    }
}

void getEdgeCost() {
    int src, dest;
    std::cout << "Enter the src and dest vertices of the desired edge: ";
    std::cin >> src >> dest;

    int cost = graph->getEdgeCost(src, dest);
    std::cout << "The cost of the edge (" << src << ", " << dest << ") is " << cost << std::endl;
}

void updateEdgeCost() {
    int src, dest, cost;
    std::cout << "Enter the src and dest vertices of the desired edge, and also the new cost: ";
    std::cin >> src >> dest >> cost;
    graph->updateEdgeCost(src, dest, cost);
}

void removeVertex() {
    int v;
    std::cout << "Enter the vertex you want to remove: ";
    std::cin >> v;
    graph->removeVertex(v);
}

void removeEdge() {
    int src, dest;
    std::cout << "Enter the src and dest of the edge you want to remove: ";
    std::cin >> src >> dest;
    graph->removeEdge(src, dest);
}

void addVertex() {
    int v;
    std::cout << "Enter the vertex you want to add: ";
    std::cin >> v;
    graph->insertVertex(v);
}

void addEdge() {
    int src, dest, cost;
    std::cout << "Enter the src, dest and cost of the edge: ";
    std::cin >> src >> dest >> cost;
    graph->insertEdge(src, dest, cost);
}

void saveGraph() {
    std::string fileName;
    std::cout << "Enter the name of the destination file: ";
    std::cin >> fileName;
    fileName = "../" + fileName;
    std::ofstream writer;
    writer.open(fileName);
    auto vertices = graph->getVertices();
    writer << vertices.size() << std::endl;

    int edges = 0;
    for (auto v: vertices) {
        writer << v << " ";
        edges += graph->getOutDegree(v);
    }

    writer << std::endl;
    writer << edges << std::endl;

    double i = 0;
    int last = 0;
    for (auto v: vertices) {
        i++;
        int p = i / (double)vertices.size() * 100;
        if (p % 10 == 0 && p != last) {
            last = p;
            std::cout << "Progress: " << p << "%...\n";
        }
        auto outbound = graph->getOutboundEdges(v);

        for (auto dest: outbound) {
            auto cost = graph->getEdgeCost(v, dest);

            writer << v << " " << dest << " " << cost << std::endl;
        }
    }

    writer.close();
}

void loadGraph() {
    delete graph;
    graph = new WDirectedGraph();

    std::string fileName;
    std::cout << "Enter the name of the file containing the desired graph: ";
    std::cin >> fileName;
    fileName = "../" + fileName;
    std::ifstream read(fileName);

    int vertices, edges;
    read >> vertices;
    std::cout << "Inserting vertices...\n";
    for (int i = 0; i < vertices; i++) {
        int v;
        read >> v;
        graph->insertVertex(v);
    }

    std::cout << "Inserting edges...\n";
    int last = 0;

    read >> edges;
    for (int i = 0; i < edges; i++) {
        int p = i / (double) edges * 100;
        if (p % 10 == 0 && p != last) {
            last = p;
            std::cout << "Progress: " << p << "...\n";
        }

        int src, dest, cost;
        read >> src >> dest >> cost;
        graph->insertEdge(src, dest, cost);
    }

    read.close();
}
void generateGraph() {
    int v, e;
    std::cout << "Enter the vertices number and edges number: ";
    std::cin >> v >> e;
    if (e > v*(v-1)) {
        throw std::runtime_error("Cannot generate required graph... the number of edges cannot be bigger than vertices*(vertices-1)\n");
    }
    delete graph;
    graph = new WDirectedGraph();

    for (int i = 0; i < v; i++) {
        graph->insertVertex(i);
    }

    std::vector<std::pair<int, int>> availableEdges;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i == j) {
                continue;
            }
            availableEdges.push_back(std::pair<int, int>(i, j));
            if (availableEdges.size() >= e) {
                break;
            }
        }
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(availableEdges.begin(), availableEdges.end(), std::default_random_engine(seed));

    srand(time(NULL));

    for (int i=0; i<e; i++) {
        std::pair<int, int> p = availableEdges[i];
        int cost = rand() % 100 + 1;
        graph->insertEdge(p.first, p.second, cost);
    }
}

void executeCommand(int option) {
    switch(option) {
        case 1: return getNumberOfVertices();
        case 2: return printVertices();
        case 3: return checkEdgeExistence();
        case 4: return getVertexInDegree();
        case 5: return getVertexOutDegree();
        case 6: return getOutboundEdges();
        case 7: return getInboundEdges();
        case 8: return getEdgeCost();
        case 9: return updateEdgeCost();
        case 10: return removeVertex();
        case 11: return removeEdge();
        case 12: return addVertex();
        case 13: return addEdge();
        case 14: return saveGraph();
        case 15: return loadGraph();
        case 16: return generateGraph();
        case 17: delete graph; exit(0);
        default: throw std::runtime_error("Invalid command :(");
    }
}

int getOption() {
    std::string optionString;
    std::cout << "Enter your option: ";
    std::cin >> optionString;
    int option = atoi(optionString.c_str());
    return option;
}

std::string getFileName() {
    std::cout << "Enter the source file with the graph:";
    std::string fileName;

    std::cin >> fileName;
    return fileName;
}

void loadInitialFile(std::ifstream &read) {
    int vertices, edges;
    read >> vertices >> edges;

    std::cout << "Inserting vertices...\n";
    graph->setup(vertices);
    std::cout << "Inserting edges...\n";

    int last = 0;
    for (auto i = 0; i < edges; i++) {
        int p = i / (double) edges * 100;
        if (p % 10 == 0 && p != last) {
            last = p;
            std::cout << "Progress: " << p << "%...\n";
        }
        int to, from, cost;
        read >> to >> from >> cost;
        graph->insertEdge(to, from, cost);
    }
}

int main() {
    graph = new WDirectedGraph();

    std::ifstream read;
    read.open("../" + getFileName());

    loadInitialFile(read);

    while (true) {
        printMenu();
        try {
            executeCommand(getOption());
        } catch (std::runtime_error &ex)  {
            std::cout << "\n\tSomething went wrong... \n\t" << ex.what() << "\n\n";
        }
    }
}
