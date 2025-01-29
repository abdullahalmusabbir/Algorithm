
#include <stdio.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int queue[MAX_NODES];
int front = -1, rear = -1;


void DFS(int node, int numNodes) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] && !visited[i]) {
            DFS(i, numNodes);
        }
    }
}



void enqueue(int node) {
    if (rear == MAX_NODES - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = node;
}


int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return -1;
    }
    int node = queue[front];
    front++;
    return node;
}


void BFS(int startNode, int numNodes) {
    enqueue(startNode);
    visited[startNode] = 1;

    while (front != -1) {
        int currentNode = dequeue();
        printf("%d ", currentNode);


        for (int i = 0; i < numNodes; i++) {
            if (graph[currentNode][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}





int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &numNodes, &numEdges);


    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
    }


    printf("Enter the edges (format: source destination):\n");
    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        graph[source][destination] = 1;
    }

    int startNodeD;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNodeD);

    int startNodeB;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNodeB);


    int choice;
    do
    {
        printf("What you want?\n1.DFS.\n2.BFS\n0.Exit.");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            DFS(startNodeD, numNodes);
            break;
        case 2:
            BFS(startNodeB, numNodes);
            break;
        }
    }while(choice!=0);



    printf("\n");

    return 0;
}
