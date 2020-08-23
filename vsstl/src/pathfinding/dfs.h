#pragma once
#include "vsstlpch.h"

#include "data_structures/graphs/node.h"


namespace vsstl::dfs {

namespace {

    template<class NodeType>
    bool search(NodeType* from, NodeType* to, std::stack<NodeType*>& path) {

        if (from == to) {
            return true;
        }

        bool found = false;
        for (NodeType* neighbour : from->neighbours) {
            if (!neighbour->visited) {
                neighbour->visited = true;
                found = search<NodeType>(neighbour, to, path);

                if (found) {
                    path.push(neighbour);
                    break;
                }
            }


        }

        return found;
    }

}

    template<class NodeType>
    std::stack<NodeType*> find_path(NodeType* from, NodeType* to) {

        std::stack<NodeType*> path;
        bool found = search<NodeType>(from, to, path);

        if (found)
            path.push(from);

        return path;
    }




}