//
// Created by andreas on 5/9/16.
//

#include "graph.h"

graph_t create_graph(int N)
{
    graph_t G = malloc(sizeof(graph));
    G->N = N;
    G->adjacency = malloc(sizeof(int)*N*N);
    for (int i = 0; i<N; ++i) {
        G->adjacency[i] = malloc(sizeof(int)*N);
    }
    for (int j = 0; j<N; ++j) {
        for (int i = 0; i<N; ++i) {
            G->adjacency[j][i] = 0;
        }
    }
    return G;
}

void add_edge(graph_t G, int v, int u)
{
    G->adjacency[v][u] = 1;
//    if (v < u) {
//        G->adjacency[v][u] = 1;
//    }
//    else if (v > u){
//        G->adjacency[u][v] = 1;
//    }
}

int is_edge(graph_t G, int v, int u)
{
    return G->adjacency[v][u];
//    if (v < u) {
//        return G->adjacency[v][u];
//    }
//    else if (v > u){
//        return G->adjacency[u][v];
//    }
//    else {
//        return 0;
//    }
}

void delete_edge(graph_t G, int v, int u)
{
    G->adjacency[v][u] = 0;
//    if (v < u) {
//        G->adjacency[v][u] = 0;
//    }
//    else if (v > u){
//        G->adjacency[u][v] = 0;
//    }
}

int get_in_degree(graph_t G, int v)
{
    int degree = 0;
    for (int i = 0; i<G->N; ++i) {
        if (G->adjacency[i][v] > 0) degree++;
    }
    return degree;
}

int get_out_degree(graph_t G, int v)
{
    int degree = 0;
    for (int i = 0; i<G->N; ++i) {
        if (G->adjacency[v][i] > 0) degree++;
    }
    return degree;
}



void print_adjacency_matrix(graph_t G)
{
    for (int i = 0; i<G->N; ++i) {
        for (int j = 0; j<G->N; ++j) {
            printf("%i ", G->adjacency[i][j]);
        }
        printf("\n");
    }
}

int eccentricity(graph_t G, int v)
{
    queue_t q = queue_init();
    char visited[G->N];
    int distances[G->N];
    int prev[G->N];
    for (int j = 0; j<G->N; ++j) {
        prev[j] = -1;
        distances[j] = 0;
        visited[j] = 0;
    }
    prev[v] = -1;

    visited[v] = 1;
    enqueue(q, v);
    while (!queue_empty(q)) {
        int node = dequeue(q);
        for (int i = 0; i < G->N; ++i) {
            if(is_edge(G, node, i)) {
                if (visited[i] == 0) {
                    enqueue(q, i);
                    visited[i] = 1;
                    distances[i] = distances[node] + 1;
                    prev[i] = node;
                }
            }
        }
    }
    int ecc = -1;
    for (int k = 0; k<G->N; ++k) {
        if (visited[k] == 1 && k != v) {
            ecc = (ecc > distances[k]) ? ecc : distances[k];
        }

    }
    return ecc;
}

int radius(graph_t G)
{
    int radius = INT_MAX;
    for (int i = 0; i<G->N; ++i) {
        int ecc = eccentricity(G, i);
        if (ecc != -1) {
            radius = radius < ecc ? radius : ecc;
        }
    }
    return radius;
}

int diameter(graph_t G)
{
    int diameter = -1;
    for (int i = 0; i<G->N; ++i) {
        int ecc = eccentricity(G, i);
        if (ecc != -1) {
            diameter = diameter>ecc ? diameter : ecc;
        }
    }
    return diameter;
}

int main()
{
    int N;
    FILE *fp;

    //fp = fopen("/home/andreas/workspace/dailyprogrammer/graph/file.txt", "r");
    fp = fopen("/home/andreas/workspace/dailyprogrammer/graph/file3.txt", "r");

    fscanf(fp, "%i", &N);
    graph_t foo = create_graph(N);
    int counter = 0;
    while (!feof(fp)) {
        int v, u;
        fscanf(fp, "%i %i", &v, &u);
        add_edge(foo, v-1, u-1);
        counter++;
    }

//    for (int i = 0; i<foo->N; ++i) {
//        printf("Node %i has a in degree of %i\n", (i+1), get_in_degree(foo, i));
//        printf("Node %i has a out degree of %i\n", (i+1), get_out_degree(foo, i));
//    }
//    print_adjacency_matrix(foo);
    fclose(fp);

    printf("%i\n", eccentricity(foo, 1));
    printf("%i\n", eccentricity(foo, 0));
    printf("%i\n", eccentricity(foo, 2));
    printf("Radius: %i\n", radius(foo));
    printf("Diameter: %i\n", diameter(foo));

    return 0;
}