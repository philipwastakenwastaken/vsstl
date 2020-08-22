#pragma once
#include "vsstlpch.h"


namespace vsstl {



    template<class NodeType>
    class UndirectedGraph {
        public:

            inline auto size() const {return nodes;}

        private:
            std::size_t nodes = 0;
            NodeType root;



    };

}