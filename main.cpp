#include <iostream>
#include <unordered_map>
#include <utility>

#include "Graph.hpp"
#include "Node.hpp"
#include "Algorithms.cpp"

int main() {
    // // Vertices_Map MyVertices {};
    // // MyVertices[2] = Node(2);
    // // MyVertices[3] = Node(3);
    // // MyVertices[4] = Node(4);

    // // Adjacency_List_Map MyGraph {};
    // // MyGraph[&MyVertices[2]].emplace_back(std::pair<Node*, int>(&MyVertices[3], 7));
    // // MyGraph[&MyVertices[3]].emplace_back(std::pair<Node*, int>(&MyVertices[4], 14));

    // // // for (const auto& pair : MyGraph) {
    // // //     std::cout << pair.first->get_value() << std::endl;
    // // // }

    // // // Testing Graph deep_copy
    // // Graph Real_Graph;
    // // Real_Graph.set_Vertices(MyVertices);
    // // Real_Graph.set_Adjacency_List(MyGraph);

    // // Graph Copy_graph {Real_Graph};

    // // Even though they are copies, the maps should not be using the same pointers as keys
    // // if (Copy_graph.get_Adjacency_List().find(&MyVertices[2]) == Copy_graph.get_Adjacency_List().end()) {
    // //     std::cout << "Not the same key" << std::endl;
    // // }

    // // testing constructing graph from csv (make sure to add CLI support!!!)
    Graph CSV_graph {Graph("./directed_weighted_graph.csv")};

    // for (const auto& Source_Vector_pair : CSV_graph.get_Adjacency_List()) {
    //     for (const auto& Target_Weight_pair : Source_Vector_pair.second) {
    //         std::cout   << "Source: " << Source_Vector_pair.first->get_value()
    //                     << " Address: " << &*Target_Weight_pair.first
    //                     << " Target: " << Target_Weight_pair.first->get_value()
    //                     << " Weight: " << Target_Weight_pair.second << std::endl; 
    //     }  
    // }



    // // std::cout << std::endl << "BFS TREE" << std::endl << std::endl;
    // Graph BFS_Tree {BFS(CSV_graph, CSV_graph.get_Vertices()[4])};
    // Graph DFS_Tree {DFS(CSV_graph)};


    // visualizeDFSTree(DFS_Tree);
    
    // std::cout << bool(CycleDetection(DFS_Tree)) << std::endl;

    // std::list<Node*> MyList {TopologicalSort(CSV_graph)};

    // while(!MyList.empty()) {
    //     std::cout << MyList.front()->get_value() << "->";
    //     MyList.pop_front();
    //     if(MyList.empty()) std::cout << "end" << std::endl;
    // }

    Graph NewGraph {Graph("./undirected_weighted_graph.csv")};
    // Graph NewerGraph {PrimMST(NewGraph)};

    for (const auto& SVP : NewGraph.get_Adjacency_List()) {
        for (const auto& TWP : SVP.second) {
            std::cout   << " Source: " << SVP.first->get_value()
                        << " Target: " << TWP.first->get_value()
                        << " Weight: " << TWP.second << std::endl;
        }
    }

    return 0;
}