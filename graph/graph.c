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
    if (v < u) {
        G->adjacency[v][u] = 1;
    }
    else if (v > u){
        G->adjacency[u][v] = 1;
    }
}

void delete_edge(graph_t G, int v, int u)
{
    if (v < u) {
        G->adjacency[v][u] = 0;
    }
    else if (v > u){
        G->adjacency[u][v] = 0;
    }
}

int get_degree(graph_t G, int v)
{
    int degree = 0;
    for (int i = 0; i<v; ++i) {
        if (G->adjacency[i][v] > 0) degree++;
    }
    for (int i = v+1; i<G->N; ++i) {
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

int main()
{
    int N;
    FILE *fp;

    fp = fopen("/home/andreas/workspace/dailyprogrammer/graph/file.txt", "r");

    fscanf(fp, "%i", &N);
    graph_t foo = create_graph(N);
    int counter = 0;
    while (!feof(fp)) {
        int v, u;
        fscanf(fp, "%i %i", &v, &u);
        add_edge(foo, v-1, u-1);
        counter++;
    }

    for (int i = 0; i<foo->N; ++i) {
        printf("Node %i has a degree of %i\n", (i+1), get_degree(foo, i));
    }
    print_adjacency_matrix(foo);
    fclose(fp);

    return 0;
}