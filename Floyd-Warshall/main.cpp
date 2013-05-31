//
//  main.cpp
//  Floyd-Warshall
//
//  Created by Dominik Plíšek on 5/31/13.
//  Copyright (c) 2013 Dominik Plíšek. All rights reserved.
//

#include <iostream>

#ifndef __PROGTEST__
#include "CGraph.h"
#endif

#define INF 9999

int** allocDistanceMatrix(int size) {
    int** distanceMatrix = new int*[size];
    for (int i = 0; i < size; i++) {
        distanceMatrix[i] = new int[size];
        for (int j = 0; j < size; j++) {
            if (i == j) {
                distanceMatrix[i][j] = 0;
            } else {
                distanceMatrix[i][j] = INF;
            }
        }
    }
    return distanceMatrix;
}

int** allocPredecessorIndexMatrix(int size) {
    int** predecessorIndexMatrix = new int*[size];
    for (int i = 0; i < size; i++) {
        predecessorIndexMatrix[i] = new int[size];
        for (int j = 0; j < size; j++) {
            predecessorIndexMatrix[i][j] = 0;
        }
    }
    return predecessorIndexMatrix;
}

void fillMatricesFromGraph(int*** distanceMatrix, int*** predecessorIndexMatrix, CGraph& g) {
    for (int i = 1; i <= g.getEdgeCounter(); i++) {
        t_edge e = g.getEdge(i);
        (*distanceMatrix)[e.sourceIndex - 1][e.destinationIndex - 1] = e.value;
        (*predecessorIndexMatrix)[e.sourceIndex - 1][e.destinationIndex - 1] = e.sourceIndex;
    }
}

bool FW(CGraph& g) {
    int** distanceMatrix = allocDistanceMatrix(g.getNodeCounter());
    int** predecessorIndexMatrix = allocPredecessorIndexMatrix(g.getNodeCounter());
    fillMatricesFromGraph(&distanceMatrix, &predecessorIndexMatrix, g);
    for (int k = 0; k < g.getNodeCounter(); k++) {
        for (int i = 0; i < g.getNodeCounter(); i++) {
            for (int j = 0; j < g.getNodeCounter(); j++) {
                if (distanceMatrix[i][k] == INF || distanceMatrix[k][j] == INF) continue;
                if (distanceMatrix[i][j] > distanceMatrix[i][k] + distanceMatrix[k][j]) {
                    distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                    predecessorIndexMatrix[i][j] = predecessorIndexMatrix[k][j];
                }
            }
        }
    }
    
    g.setMatrix(distanceMatrix, predecessorIndexMatrix);
    
    bool freeOfNegativeCycles = true;
    for (int i = 0; i < g.getNodeCounter(); i++) {
        if (distanceMatrix[i][i] < 0) {
            freeOfNegativeCycles = false;
            break;
        }
    }
    
    for (int i = 0; i < g.getNodeCounter(); i++) {
        delete [] distanceMatrix[i];
        delete [] predecessorIndexMatrix[i];
    }
    delete [] distanceMatrix;
    delete [] predecessorIndexMatrix;
    return freeOfNegativeCycles;
}

#ifndef __PROGTEST__

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
    
    t_edge edge2(1, 2, 3);
    t_edge edge3(1, 3, 6);
    t_edge edge5(2, 3, 2);
    t_edge edge6(2, 4, 6);
    t_edge edge8(3, 4, -3);
    t_edge edge9(4, 1, 1);
    t_edge edge11(4, 5, 1);
    t_edge edge12(5, 1, -2);
    t_edge edge13(5, 2, 3);
    t_edge edge14(5, 3, 4);
    
    g->addEdge(edge2);
    g->addEdge(edge3);
    g->addEdge(edge5);
    g->addEdge(edge6);
    g->addEdge(edge8);
    g->addEdge(edge9);
    g->addEdge(edge11);
    g->addEdge(edge12);
    g->addEdge(edge13);
    g->addEdge(edge14);
    
    FW(*g);
    
    cout << *g << endl;
    
    delete g;
    return 0;
}

#endif