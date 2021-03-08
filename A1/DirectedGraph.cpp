//
// Created by Teodor Filp on 22/02/2021.
//

#include "DirectedGraph.h"
#include <iostream>

DirectedGraph::DirectedGraph() {
}

DirectedGraph::~DirectedGraph() {
    clearMap(this->from);
    clearMap(this->to);
}

void DirectedGraph::clearMap(std::map<int, std::vector<int>*> map) {
    while (map.size() > 0) {
        auto iterator = map.begin();
        delete iterator->second;
        map.erase(iterator);
    }
}

void DirectedGraph::insertVertex(int vertex) {
    if (this->isVertex(vertex)) {
        throw std::runtime_error("Vertex already present");
    }
    this->to[vertex] = new std::vector<int>();
    this->from[vertex] = new std::vector<int>();
}

void DirectedGraph::insertEdge(int start, int destination) {
    if (this->existsEdge(start, destination)) {
        throw std::runtime_error("Edge already exists");
    }
    this->from[destination]->push_back(start);
    this->to[start]->push_back(destination);
}

void DirectedGraph::setup(int vertices) {
    for (auto vertex = 0; vertex < vertices; vertex++) {
        this->to[vertex] = new std::vector<int>();
        this->from[vertex] = new std::vector<int>();
    }
}

void DirectedGraph::loadFile(std::ifstream &read) {
    int vertices, edges;
    read >> vertices >> edges;

    this->setup(vertices);

    for (auto i = 0; i < edges; i++) {
        int to, from;
        read >> to >> from;
        this->insertEdge(to, from);
    }
}

std::vector<int> DirectedGraph::getVertices() {
    std::vector<int> vertices;

    for (auto it = this->to.begin(); it != this->to.end(); ++it) {
        vertices.push_back(it->first);
    }

    return vertices;
}

bool DirectedGraph::existsEdge(int source, int destination) {
    if (!this->to[source]) {
        return false;
    }

    auto foundIterator = std::find(this->to[source]->begin(), this->to[source]->end(), destination);

    if (foundIterator == this->to[source]->end()) {
        return false;
    }

    return true;
}

bool DirectedGraph::isVertex(int candidate) {
    return this->to[candidate] != NULL;
}

int DirectedGraph::getInDegree(int dest) {
    if (!this->isVertex(dest)) {
        return 0;
    } else {
        return this->from[dest]->size();
    }
}

int DirectedGraph::getOutDegree(int src) {
    if (!this->isVertex(src)) {
        return 0;
    } else {
        return this->to[src]->size();
    }
}

std::vector<int>::iterator DirectedGraph::getInboundEdgesBegin(int dest) {
    if (!this->isVertex(dest)) {
        throw std::runtime_error("Vertex not found");
    } else {
        return this->from[dest]->begin();
    }
}

std::vector<int>::iterator DirectedGraph::getInboundEdgesEnd(int dest) {
    if (!this->isVertex(dest)) {
        throw std::runtime_error("Vertex not found");
    } else {
        return this->from[dest]->end();
    }
}

std::vector<int>::iterator DirectedGraph::getOutboundEdgesBegin(int src) {
    if (!this->isVertex(src)) {
        throw std::runtime_error("Vertex not found");
    } else {
        return this->to[src]->begin();
    }
}

std::vector<int>::iterator DirectedGraph::getOutboundEdgesEnd(int src) {
    if (!this->isVertex(src)) {
        throw std::runtime_error("Vertex not found");
    } else {
        return this->to[src]->end();
    }
}

void DirectedGraph::removeEdge(int src, int dest) {
    if (!this->isVertex(src) || !this->isVertex(dest)) {
        throw std::runtime_error("Vertex not found");
    } else {
        std::vector<int>* to = this->to[src];
        std::vector<int>* from = this->from[dest];
        const auto srcIt = std::find(from->begin(), from->end(), src);
        const auto destIt = std::find(to->begin(), to->end(), dest);
        from->erase(srcIt);
        to->erase(destIt);
    }
}

void DirectedGraph::removeVertex(int candidate) {
    if (!this->isVertex(candidate)) {
        throw std::runtime_error("Vertex not found");
    }

    delete this->to[candidate];
    delete this->from[candidate];
    this->to.erase(candidate);
    this->from.erase(candidate);
}

DirectedGraph DirectedGraph::copy(DirectedGraph &old) {

}