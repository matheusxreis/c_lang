/// Dijkstra's Algorithm to find Shortest Paths from a Source to all

// Find the shortest path distance from source vertex to all
// other vertices in the graph

#define V 11
#define SRC 2
#define MAIN_EXIST

#include "./adjacency_matrix.c"
#include "../06tree/minheap.c"

void dijkstra(int *graph, int src, int *dist)
{

    MinHeap *minheap = minheapcreate(V);
    int* item = (int*)malloc(2 * sizeof(int));
    item[0] = src;
    item[1] = 0;
    insert(minheap, item);

    dist[src] = 0;

    while (minheap->size)
    {

        int *item = delete(minheap);
        int u = item[0];

        // u is the processing vertesx
        // v is the adjacentes vertex

        if (item[1] > dist[u])
        {
            free(item);
            continue;
        }

        for (int v = 0; v < V; v++)
        {
            // get all adjacents
            int weight = *(graph + (V * u) + v);

            if (weight > 0 &&
                dist[v] > dist[u] + weight && dist[u] != INT32_MAX)
            {
                dist[v] = dist[u] + weight;

                int* item =  (int*)malloc(2 * sizeof(int));
                item[0] = v;
                item[1]= dist[v]; // <node, distancw>
                insert(minheap, item);
            }
        }

        free(item);
    }
}

int main()
{

    // undirected weighted graph
    int *graph = create(TRUE);

    printf("\n\n========\n\nReading graph WITHOUT weights defined:\n");
    read(graph);

    // line: 2
    addEdgeAndWeight(graph, 2, 3, 2, FALSE);
    addEdgeAndWeight(graph, 2, 5, 2, FALSE);
    addEdgeAndWeight(graph, 2, 0, 40, FALSE);
    // line: 3
    addEdgeAndWeight(graph, 3, 4, 8, FALSE);
    addEdgeAndWeight(graph, 3, 6, 2, FALSE);
    // line: 5
    addEdgeAndWeight(graph, 5, 6, 1, FALSE);
    addEdgeAndWeight(graph, 5, 0, 23, FALSE);
    // line: 0
    addEdgeAndWeight(graph, 0, 1, 15, FALSE);
    // line: 4
    addEdgeAndWeight(graph, 4, 6, 12, FALSE);
    addEdgeAndWeight(graph, 4, 8, 20, FALSE);
    // line: 6
    addEdgeAndWeight(graph, 6, 7, 2, FALSE);
    addEdgeAndWeight(graph, 6, 1, 1, FALSE);
    // line: 1
    addEdgeAndWeight(graph, 1, 7, 1, FALSE);
    addEdgeAndWeight(graph, 1, 9, 10, FALSE);
    // line: 8
    addEdgeAndWeight(graph, 8, 7, 1, FALSE);
    addEdgeAndWeight(graph, 8, 9, 7, FALSE);
    // line: 7
    addEdgeAndWeight(graph, 7, 9, 5, FALSE);
    // line: 9
    addEdgeAndWeight(graph, 9, 10, 6, FALSE);

    printf("\n\n========\n\nReading graph WITH weights defined:\n");
    read(graph);

    // creating dist array
    int dist[V] = {};
    for (int i = 0; i < V; dist[i++] = INT32_MAX);
    //

    dijkstra(graph, SRC, dist);

    printf("\n\n========\n\nReading DIJKSTRA results:\n");

    for (int i = 0; i < V; printf(" %d ", dist[i++]));
    printf("\n");
    
}
