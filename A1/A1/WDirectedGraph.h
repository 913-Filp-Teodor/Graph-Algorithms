//
// Created by Tudor Filp on 3/14/2021.
//

#ifndef A1_WDIRECTEDGRAPH_H
#define A1_WDIRECTEDGRAPH_H

#include <map>
#include <fstream>

#include "DirectedGraph.h"

class WDirectedGraph: public DirectedGraph {
    protected:
        std::map<std::pair<int, int>, int> weights;

    public:
        WDirectedGraph();
        ~WDirectedGraph();
        void insertEdge(int, int, int);
        virtual void removeVertex(int) override;
        virtual void removeEdge(int, int) override;
        int getEdgeCost(int, int);
        void updateEdgeCost(int, int, int);
        void clearMap(std::map<std::pair<int, int>, int>);
        virtual WDirectedGraph* copy();

};

#endif //A1_WDIRECTEDGRAPH_H
