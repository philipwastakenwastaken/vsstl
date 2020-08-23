#pragma once
#include "vsstlpch.h"

namespace vsstl {



    template<class NodeType>
    class UndirectedGraph {
        public:

            inline void add_node(NodeType& node) {nodes.push_back(node);}

            inline void add_edge(NodeType* n1, NodeType* n2) {
                n1->neighbours.push_back(n2);
                n2->neighbours.push_back(n1);
            }

            inline auto size() const {return nodes.size();}
            inline const NodeType& root() const {return nodes.front();}
            inline       NodeType& root()       {return nodes.front();}

        private:
            std::vector<NodeType> nodes;



    };

}