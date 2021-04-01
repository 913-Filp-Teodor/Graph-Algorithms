//
// Created by Teodor Filp on 22/02/2021.
//

#ifndef A1_DIRECTEDGRAPH_H
#define A1_DIRECTEDGRAPH_H
#include <map>
#include <vector>
#include <fstream>

class DirectedGraph {
    protected:
        std::map<int, std::vector<int>*> to;
        std::map<int, std::vector<int>*> from;

    public:
        DirectedGraph();
        ~DirectedGraph();
        void insertVertex(int);
        virtual void insertEdge(int, int);
        void setup(int);
        void clearMap(std::map<int, std::vector<int>*>);
        bool existsEdge(int, int);
        std::vector<int> getVertices();
        std::vector<int>::iterator getInboundEdgesBegin(int);
        std::vector<int>::iterator getInboundEdgesEnd(int);
        std::vector<int>::iterator getOutboundEdgesBegin(int);
        std::vector<int>::iterator getOutboundEdgesEnd(int);
        std::vector<int> getInboundEdges(int);
        std::vector<int> getOutboundEdges(int);
        virtual void removeEdge(int, int);
        virtual void removeVertex(int);
        bool isVertex(int);
        int getInDegree(int);
        int getOutDegree(int);
};


#endif //A1_DIRECTEDGRAPH_H
