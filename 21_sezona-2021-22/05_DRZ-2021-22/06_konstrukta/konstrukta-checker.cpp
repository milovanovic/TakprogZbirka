#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<string>
 
using namespace std;
 
const int maxN = 200010;
 
 int N;
 vector<int> v[maxN];
 map<pair<int, int> ,bool> edges;
 int dist[maxN];
 int maxDist = 0;
 
void bfs(int startNode) {
    for (int i = 1; i <= N; i++) {
        dist[i] = -1;
    }
 
    dist[startNode] = 0;
    queue<int> q; 
    q.push(startNode);
 
    while(!q.empty()) {
        int node = q.front();
        maxDist = max(maxDist, dist[node]);
        q.pop();
 
        for (int i:v[node]) {
            if (dist[i] == -1) {
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }
} 
 
int main(int argc, char *argv[])
{
    FILE* fout = fopen(argv[1], "r"); // Takmicarev output
    FILE* fans = fopen(argv[2], "r"); // Komisijski output
    FILE* fin = fopen(argv[3], "r"); // Input
 
    fscanf(fin, "%d", &N);
 
    for (int i = 1 ; i < N; i++){
        int x, y;
        fscanf(fin, "%d%d", &x, &y);
        edges[{x, y}] = true;
        edges[{y, x}] = true;
        v[x].push_back(y);
        v[y].push_back(x);
    }
  
    int newLineEndpointA, newLineEndpointB;
    fscanf(fout, "%d%d", &newLineEndpointA, &newLineEndpointB);
    int eurosong;
    fscanf(fout, "%d", &eurosong);
 
    if (newLineEndpointA > N || newLineEndpointA < 1 || newLineEndpointA == newLineEndpointB) {
        return -1;
    }
 
    if (newLineEndpointB > N || newLineEndpointB < 1) {
       return -1;    
 
    }
 
    if (edges.find({newLineEndpointA, newLineEndpointB}) != edges.end()) {
        return -1;
    }
 
    if (eurosong > N || eurosong < 1) {
       return -1;    
    }
 
    v[newLineEndpointA].push_back(newLineEndpointB);
    v[newLineEndpointB].push_back(newLineEndpointA);
    
    bfs(eurosong);
 
    v[newLineEndpointA].pop_back();
    v[newLineEndpointB].pop_back();
 
    int competitorAnswer = maxDist;
 
    fscanf(fans, "%d%d", &newLineEndpointA, &newLineEndpointB);
    fscanf(fans, "%d", &eurosong); 
    
    v[newLineEndpointA].push_back(newLineEndpointB);
    v[newLineEndpointB].push_back(newLineEndpointA);
    maxDist = 0;
    bfs(eurosong);
    
    int juryAnswer = maxDist;
 
    if (juryAnswer < competitorAnswer) {
        return -1;
    }
 
    return 0;
}
