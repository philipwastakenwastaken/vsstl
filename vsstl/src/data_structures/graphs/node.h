#pragma once
#include "vsstlpch.h"

namespace vsstl {


    template<typename T>
    struct Node {
        Node() = default;
        Node(i32 weight): weight(weight) {}

        T data;
        bool visited = false;
        i32 weight = 1;
        std::vector<Node<T>*> neighbours;
    };






}