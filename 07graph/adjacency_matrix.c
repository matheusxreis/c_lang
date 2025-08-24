// using matrix
// () -> vertex or node
// ----> edge
// () ----> () ------> ()
// yes, i could have done this using 
//   matrix as graph[V][V], but i choose
//     do as a pointer because yes

#include<stdio.h>
#include<stdlib.h>


#ifndef V
    #define V 7
#endif

#define INF -1

#define TRUE 1
#define FALSE 0

int* create(int withWeight);
// without weight
void addEdge(int* graph, int i, int j, int directed);
// with weight
void addEdgeAndWeight(int* graph, int i, int j, int weight, int directed);
//
void read(int* graph);


#ifndef MAIN_EXIST
    int main() {
        int* graph = create(FALSE); // undirected unweighted graph
        int* graphW = create(TRUE); // undirected with weight graph
        int* graph2 = create(FALSE); // directed unweighted graph
        // int* graphW2 = create(TRUE); // directed with weight graph

        // add edges in undirected unweighted graph
        addEdge(graph, 0, 1, FALSE);
        addEdge(graph, 1, 2, FALSE);
        addEdge(graph, 2, 3, FALSE);
        addEdge(graph, 3, 1, FALSE);
        
        // add edges in weight graph 
        addEdgeAndWeight(graphW, 6, 3, 2, FALSE);
        addEdgeAndWeight(graphW, 3, 4, 1, FALSE);

        // add edges in directed unweighted graph
        addEdge(graph2, 0, 1, TRUE);
        addEdge(graph2, 1, 2, TRUE);
        addEdge(graph2, 2, 3, TRUE);
        addEdge(graph2, 3, 1, TRUE);

        printf("Undirected Graph in Adjacency Matrix:\n");
        read(graph);
        printf("Graph with weight in Adjacency Matrix:\n");
        read(graphW);
        printf("Directed Graph with weight in Adjacency Matrix:\n");
        read(graph2);

    };

#endif

int* create(int withWeight) {

    int* graph = malloc (V * V * sizeof (int));

    if(!withWeight) {
        return graph;
    }

    
    for(int i = 0; i<V; i++) {
        for (int j = 0; j<V; j++) {
            *(graph+(i*V)+j) = 0;
        }    
    }

    return graph;
};

void addEdge(int* graph, int i, int j, int directed) {
    *(graph+(i*V)+j) = 1;
    if(!directed) { *(graph+(j*V)+i) = 1; } // since it is an undirected graph
};

void addEdgeAndWeight(int* graph, int i, int j, int weight, int directed) {
    *(graph+(i*V)+j) = weight;
   if(!directed) { *(graph+(j*V)+i) = weight; } // since it is an undirected graph
}

void read(int* graph) {
    //
    for(int i = 0; i<V; i++) {
        for (int j = 0; j<V; j++) {
            
            printf(" %d ", *(graph+(i*V)+j));
        }
        printf("\n");
    };
    //
};