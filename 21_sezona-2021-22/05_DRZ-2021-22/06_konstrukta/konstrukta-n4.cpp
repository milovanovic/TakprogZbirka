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

    for (int i = 1; i <= N; i++) { // eurosong final country
    	for (int j = 1; j <= N; j++) { // new line endpointA
    		for (int k = 1; k <= N; k++) { // new line endpointB
    			if (j != k && edges.find({j, k}) == edges.end()) {
    			  int biggestDistance = findBiggestDistanceFromNode(i, j, k);
                  if (biggestDistance < bestAns) {
                  	bestAns = biggestDistance;
                  	eurosongFinalNode = i;
                  	newLineEndpointA = j;
                  	newLineEndpointB = k;
                  }   
    		    }
    		}
    	}
    }
    		
    printf("%d %d\n", newLineEndpointA, newLineEndpointB);
    printf("%d\n", eurosongFinalNode);

	return 0;
}