//
//  main.cpp
//  Floyd-Warshall
//
//  Created by Dominik Plíšek on 5/31/13.
//  Copyright (c) 2013 Dominik Plíšek. All rights reserved.
//

#include <iostream>
#include "CGraph.h"

int** allocMatrix(int size) {
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    return matrix;
}

bool FW(CGraph& g) {
    int** distanceMatrix = allocMatrix(g.getNodeCounter());
    int** predecessorIndexMatrix = allocMatrix(g.getNodeCounter());
    
}

int main(int argc, const char * argv[])
{
    CGraph *g = new CGraph;
    
    t_node node1;
    t_node node2;
    t_node node3;
    t_node node4;
    t_node node5;
    
    g->addNode(node1);
    g->addNode(node2);
    g->addNode(node3);
    g->addNode(node4);
    g->addNode(node5);
    
    t_edge edge1(1, 1, 0);
    t_edge edge2(1, 2, 3);
    t_edge edge3(1, 3, 6);
    t_edge edge4(2, 2, 0);
    t_edge edge5(2, 3, 2);
    t_edge edge6(2, 4, 6);
    t_edge edge7(3, 3, 0);
    t_edge edge8(3, 4, -3);
    t_edge edge9(4, 1, 1);
    t_edge edge10(4, 4, 0);
    t_edge edge11(4, 5, 1);
    t_edge edge12(5, 1, -2);
    t_edge edge13(5, 2, 3);
    t_edge edge14(5, 3, 4);
    t_edge edge15(5, 5, 0);
    
    g->addEdge(edge1);
    g->addEdge(edge2);
    g->addEdge(edge3);
    g->addEdge(edge4);
    g->addEdge(edge5);
    g->addEdge(edge6);
    g->addEdge(edge7);
    g->addEdge(edge8);
    g->addEdge(edge9);
    g->addEdge(edge10);
    g->addEdge(edge11);
    g->addEdge(edge12);
    g->addEdge(edge13);
    g->addEdge(edge14);
    g->addEdge(edge15);
    
    FW(*g);
    
    cout << *g << endl;
    
    delete g;
    return 0;
}

