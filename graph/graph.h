//
// Created by andreas on 5/9/16.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <stdlib.h>
#include <stdio.h>

typedef struct { //undirected graph
    int N; //nr of nodes
    int **adjacency; //edges are strictly stored with v<u (upper right matrix)
} graph;

typedef graph *graph_t;

#endif //GRAPH_GRAPH_H
