#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int adj[MAX][MAX] = {0}, n = 0;

void insertNode() {
    if (n < MAX) n++;
}

void insertEdge(int u, int v) {
    if (u < n && v < n) {
        adj[u][v] = adj[v][u] = 1;
    }
}

void display() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void DFS(int v, int vis[]) {
    if (vis[v]) return;
    vis[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !vis[i]) {
            DFS(i, vis);
        }
    }
}

void BFS(int start) {
    int vis[MAX] = {0}, q[MAX], f = 0, r = 0;
    q[r++] = start;
    vis[start] = 1;
    while (f < r) {
        int v = q[f++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !vis[i]) {
                q[r++] = i;
                vis[i] = 1;
            }
        }
    }
}

int main() {
    int m, u, v, vis[MAX] = {0};
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        insertEdge(u - 1, v - 1);
    }

    display();

    printf("DFS: ");
    DFS(0, vis);

    printf("\nBFS: ");
    BFS(0);

    return 0;
}