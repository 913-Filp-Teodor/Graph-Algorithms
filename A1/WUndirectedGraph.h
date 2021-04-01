//
// Created by Tudor Filp on 4/1/2021.
//

#ifndef A1_WUNDIRECTEDGRAPH_H
#define A1_WUNDIRECTEDGRAPH_H

#include "WDirectedGraph.h"

class WUndirectedGraph: public WDirectedGraph {
    public:
        virtual void removeEdge(int, int);
        virtual void insertEdge(int, int);
        virtual void removeVertex(int);
        virtual void insertEdge(int src, int dest, int cost) override;
        std::vector<std::vector<int>> getConnectedComponents();
};

#endif //A1_WUNDIRECTEDGRAPH_H
