//
// Created by Tudor Filp on 3/8/2021.
//

#include <vector>

namespace GraphUtils {
    void removeFromList(std::vector<int>* vect, int item) {
        const auto it = std::find(vect->begin(), vect->end(), item);
        vect->erase(it);
    }
}