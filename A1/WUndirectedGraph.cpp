//
// Created by Tudor Filp on 4/1/2021.
//
#include "WUndirectedGraph.h"
#include "GraphUtils.h"

#include <iostream>
#include <set>

void WUndirectedGraph::insertEdge(int src, int dest) {
    DirectedGraph::insertEdge(src, dest);
    DirectedGraph::insertEdge(dest, src);
}

void WUndirectedGraph::removeEdge(int src, int dest) {
    DirectedGraph::removeEdge(src, dest);
    DirectedGraph::removeEdge(dest, src);
}

void WUndirectedGraph::removeVertex(int vertex) {
    if (!this->isVertex(vertex)) {
        throw std::runtime_error("Vertex not found");
    }

    std::vector<int> neighs = this->getOutboundEdges(vertex);

    for (auto n: neighs) {
        this->removeEdge(vertex, n);
    }

    delete this->to[vertex];
    delete this->from[vertex];
    this->to.erase(vertex);
    this->from.erase(vertex);
}

std::vector<std::vector<int>> WUndirectedGraph::getConnectedComponents() {
    std::set<int> notVisited;
    std::vector<std::vector<int>> components;
    std::vector<int> vertices = this->getVertices();

    for (auto v: vertices) {
        notVisited.insert(v);
    }

    for (auto v: vertices) {
        if (notVisited.find(v) != notVisited.end()) {
            std::vector<int> component;
            component.push_back(v);
            notVisited.erase(v);
            GraphUtils::getConnectedComponents(*this, v, component, notVisited);
            components.push_back(component);
        }
    }

    return components;
}

void WUndirectedGraph::insertEdge(int src, int dest, int cost) {
    if (!this->existsEdge(src, dest)) {
        WDirectedGraph::insertEdge(src, dest, cost);
    }
    if (!this->existsEdge(dest, src)){
        WDirectedGraph::insertEdge(dest, src, cost);
    }
}