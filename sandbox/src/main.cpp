#include "data_structures/graphs/undirected_graph.h"
#include "vsstl/vsstl.h"
#include <functional>

int main() {
    vsstl::Log::init();

    vsstl::Node<int> n1;
    n1.data = 1;

    vsstl::Node<int> n2;
    n2.data = 2;

    vsstl::Node<int> n3;
    n3.data = 3;

    vsstl::Node<int> n4;
    n4.data = 4;

    vsstl::Node<int> n5;
    n5.data = 5;

    vsstl::Node<int> n6;
    n6.data = 6;

    //               n3
    //             /
    // n1 --- n2 -
    //             \
    //               n4

    vsstl::UndirectedGraph<vsstl::Node<int>> graph;

    graph.add_node(n1);
    graph.add_node(n2);
    graph.add_node(n3);
    graph.add_node(n4);
    graph.add_node(n5);
    graph.add_node(n6);

    graph.add_edge(&n1, &n2);
    graph.add_edge(&n3, &n2);
    graph.add_edge(&n5, &n3);
    graph.add_edge(&n4, &n2);

    auto path = vsstl::dfs::find_path<vsstl::Node<int>>(&n1, &n5);

    int size = path.size();
    for (int i = 0; i < size; i++) {
        vsstl::Node<int> n = *path.top();
        path.pop();
        VSSTL_INFO("n{0}", n.data);
    }




    return 0;
}