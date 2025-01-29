#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src;
    int dest;
    int weight;
};

struct Subset {
    int parent;
    int rank;
};

int find(vector<Subset> &subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(vector<Subset> &subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


bool compare(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int main() {
    int V = 4;
    int E = 5;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    sort(edges.begin(), edges.end(), compare);

    vector<Subset> subsets(V);

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    vector<Edge> result;

    int e = 0;

    while (result.size() < V - 1 && e < E) {

        Edge next_edge = edges[e++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);


        if (x != y) {
            result.push_back(next_edge);
            Union(subsets, x, y);
        }
    }

    printf("\nEdge of MST\n");
    for(const Edge& edge : result)
        printf("%d -- %d = %d\n",edge.src,edge.dest,edge.weight);

}
