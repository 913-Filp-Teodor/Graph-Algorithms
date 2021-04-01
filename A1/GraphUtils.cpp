//
// Created by Tudor Filp on 3/8/2021.
//

#include <vector>
#include <set>
#include <stack>
#include "WUndirectedGraph.h"

namespace GraphUtils {
    void removeFromList(std::vector<int>* vect, int item) {
        const auto it = std::find(vect->begin(), vect->end(), item);
        vect->erase(it);
    }

    void getConnectedComponents(WUndirectedGraph &graph, int source, std::vector<int> &component, std::set<int> &notVisited) {
        std::stack<int> stack;
        stack.push(source);

        while (!stack.empty()) {
            int s = stack.top();
            stack.pop();
            for (auto n: graph.getOutboundEdges(s)) {
                if (notVisited.find(n) != notVisited.end()) {
                    notVisited.erase(n);
                    component.push_back(n);
                    stack.push(n);
                }
            }
        }
    }
}