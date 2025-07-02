#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Function prototypes
struct Node* createNode(int v);
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void DFS(struct Graph* graph, int vertex);
void resetVisited(struct Graph* graph);

int main() {
    int choice, vertices, src, dest, start;
    struct Graph* graph = NULL;

    do {
        printf("Menu:  1. Create Graph  2. Add Edge  3. Perform DFS  4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                printf("Enter the number of vertices: ");
                scanf("%d", &vertices);
                graph = createGraph(vertices);
                printf("Graph created with %d vertices.\n", vertices);
                break;

            case 2:
                if (graph == NULL) {
                    printf("Create a graph first.\n");
                } else {
                    printf("Enter source and destination vertices: ");
                    scanf("%d %d", &src, &dest);
                    addEdge(graph, src, dest);
                    printf("Edge added between %d and %d.\n", src, dest);
                }
                break;

            case 3:
                if (graph == NULL) {
                    printf("Create a graph first.\n");
                } else {
                    printf("Enter starting vertex for DFS: ");
                    scanf("%d", &start);
                    resetVisited(graph);
                    printf("DFS traversal starting from vertex %d: ", start);
                    DFS(graph, start);
                    printf("\n");
                }
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to create a node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**) malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*) malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to reset the visited array before traversal
void resetVisited(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
}

// DFS algorithm
void DFS(struct Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjLists[vertex];

    while (temp) {
        int adjVertex = temp->vertex;

        if (graph->visited[adjVertex] == 0) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}



