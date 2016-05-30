//
// Created by andreas on 5/9/16.
//

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0

typedef struct { //undirected graph
    int N; //nr of nodes
    int **adjacency; //edges are strictly stored with v<u (upper right matrix)
} graph;

typedef graph *graph_t;

graph_t create_graph(int);

void add_edge(graph_t, int, int);

int is_edge(graph_t, int, int);

void delete_edge(graph_t, int, int);

int get_in_degree(graph_t, int);

int get_out_degree(graph_t, int);

void print_adjacency_matrix(graph_t);

int eccentricity(graph_t, int);

int radius(graph_t);

int diameter(graph_t);