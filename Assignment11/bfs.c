 #include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Node {
    int vertex;
    struct Node* next;
};
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};
struct Queue {
    int items[MAX];
    int front, rear;
};
struct Node* createNode(int v);
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void BFS(struct Graph* graph, int startVertex);
void resetVisited(struct Graph* graph);
struct Queue* createQueue();
void enqueue(struct Queue* q, int);
int dequeue(struct Queue* q);
int isEmpty(struct Queue* q);

int main() {
    int choice, vertices, src, dest, start;
    struct Graph* graph = NULL;

    do {
        printf("MENU: 1. Create Graph  2. Add Edge  3. Perform BFS  4. Exit\nEnter your choice: ");
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
                    printf("Enter starting vertex for BFS: ");
                    scanf("%d", &start);
                    resetVisited(graph);
                    printf("BFS traversal starting from vertex %d: ", start);
                    BFS(graph, start);
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

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

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


void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void resetVisited(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
}
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}
int isEmpty(struct Queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("\nQueue is full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("\nQueue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}
