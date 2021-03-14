//
// Created by Tudor Filp on 3/14/2021.
//
#include "WDirectedGraph.h"

WDirectedGraph::WDirectedGraph() {

}

void WDirectedGraph::clearMap(std::map<std::pair<int, int>, int> map) {
    while (!map.empty()) {
        map.erase(map.begin());
    }
}

void WDirectedGraph::insertEdge(int src, int dest, int cost) {
    DirectedGraph::insertEdge(src, dest);
    std::pair<int, int> id = std::pair<int, int>(src, dest);
    this->weights[id] = cost;
}

void WDirectedGraph::removeEdge(int src, int dest) {
    DirectedGraph::removeEdge(src, dest);

    auto it = this->weights.find(std::pair<int, int>(src, dest));
    if (it != this->weights.end()) {
        this->weights.erase(it);
    }
}

void WDirectedGraph::removeVertex(int v) {
    std::vector<int> outbound = DirectedGraph::getOutboundEdges(v);
    std::vector<int> inbound = DirectedGraph::getInboundEdges(v);

    for (auto dest: outbound) {
        auto it = this->weights.find(std::pair<int, int>(v, dest));
        if (it != this->weights.end()) {
            this->weights.erase(it);
        }
    }

    for (auto src: inbound) {
        auto it = this->weights.find(std::pair<int, int>(src, v));
        if (it != this->weights.end()) {
            this->weights.erase(it);
        }
    }
    DirectedGraph::removeVertex(v);
}

int WDirectedGraph::getEdgeCost(int src, int dest) {
    auto it = this->weights.find(std::pair<int, int>(src, dest));
    if (it == this->weights.end()) {
        throw std::runtime_error("Edge does not exist");
    }

    return it->second;
}

void WDirectedGraph::updateEdgeCost(int src, int dest, int cost) {
    bool exists = this->existsEdge(src, dest);
    if (!exists) {
        throw std::runtime_error("Edge does not exist");
    }

    this->weights[std::pair<int, int>(src, dest)] = cost;
}

WDirectedGraph* WDirectedGraph::copy() {
    WDirectedGraph *newGraph = new WDirectedGraph();
    for (auto v: this->getVertices()) {
        newGraph->insertVertex(v);
    }

    for (auto v: this->getVertices()) {
        auto out = this->getOutboundEdges(v);
        for (auto o: out) {
            auto cost = this->getEdgeCost(v, o);
            newGraph->insertEdge(v, o, cost);
        }
    }

    return newGraph;
}

WDirectedGraph::~WDirectedGraph() {
    clearMap(this->weights);
}