#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int maxN = 2e5 + 10;

int N, dist[maxN];
vector<int> v[maxN];
map<pii, int> edges;

void bfs(int startNode) {
    dist[startNode] = 0;
    queue<int> q;
    q.push(startNode);

    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();

        for (int node: v[currentNode]) {
            if (dist[node] == -1) {
                dist[node] = dist[currentNode] + 1;
                q.push(node);
            }
        }
    }
}

int findBiggestDistanceFromNode(int startNode, int newLineEndpointA, int newLineEndpointB) {
    v[newLineEndpointA].push_back(newLineEndpointB);
    v[newLineEndpointB].push_back(newLineEndpointA);

    for (int i = 1; i <= N ;i++) {
        dist[i] = -1;
    }

    bfs(startNode);
    
    int biggestDistance = 0;
    for (int i = 1; i <= N; i++) {
        biggestDistance = max(biggestDistance, dist[i]);
    }
    
    v[newLineEndpointA].pop_back();
    v[newLineEndpointB].pop_back();

    return biggestDistance;
}

pii findPairOfNonConnectedNodes() {
    for (int node = 1; node <= N; node++) {
        int nextNode = node == N ? 1 : node + 1;
        if (edges.find({node, nextNode}) == edges.end()) {
            return {node, nextNode};
        }
    }
    
    return {-1, 1};
}

int main() {
    
    scanf("%d", &N);

    for (int i = 1; i < N; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        edges[{x, y}] = true;
        edges[{y, x}] = true;
        v[x].push_back(y);
        v[y].push_back(x);
    }
     
    int bestAns = N + 1;
    int eurosongFinalNode, newLineEndpointA, newLineEndpointB;

    for (int i = 1; i<= N; i++) { // eurosong final country + new line endpointA
        bool connectedWithAll = true;
    	for (int j = 1; j <= N; j++) { // new line endpointB
    		if (j != i && edges.find({i, j}) == edges.end()) {
                connectedWithAll = false;
                int biggestDistance = findBiggestDistanceFromNode(i, i, j);
                if (biggestDistance < bestAns) {
                    bestAns = biggestDistance;
                    eurosongFinalNode = i;
                    newLineEndpointA = i;
                    newLineEndpointB = j;
                }   
    		}
    	}

        if (connectedWithAll) { // diameter length equals with 2
            bestAns = 1;
            eurosongFinalNode = i;
            pii nonConnectedNodes = findPairOfNonConnectedNodes();
            newLineEndpointA = nonConnectedNodes.first;
            newLineEndpointB = nonConnectedNodes.second; 
        }
    }
    		
    printf("%d %d\n", newLineEndpointA, newLineEndpointB);
    printf("%d\n", eurosongFinalNode);

	return 0;
}