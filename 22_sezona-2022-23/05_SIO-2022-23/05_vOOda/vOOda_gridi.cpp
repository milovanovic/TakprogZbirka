#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>
#include <fstream>

#define maxN 5000
#define maxM 5000

using namespace std;

int n, m, cnt[maxN][maxN], deg[maxN][maxM];
string s[maxN],input[maxN];

vector<pair<int, int>> ans, all;
set<pair<int, int>> candidates;

bool checkAndUpdate(int x, int y) {
	if (cnt[x][y] == 2) return false;
	cnt[x][y]++;
	if (cnt[x][y] == 2) return true;
	candidates.insert({ x,y });

	return false;
}

void add(int x, int y) {
	cnt[x][y] = 2;
	if (x > 0 && s[x - 1][y] == '.') {
		if (checkAndUpdate(x - 1, y)) add(x - 1, y);
	}
	if (x < n - 1 && s[x + 1][y] == '.') {
		if (checkAndUpdate(x + 1, y)) add(x + 1, y);
	}
	if (y > 0 && s[x][y - 1] == '.') {
		if (checkAndUpdate(x, y - 1)) add(x, y - 1);
	}
	if (y < m - 1 && s[x][y + 1] == '.') {
		if (checkAndUpdate(x, y + 1)) add(x, y + 1);
	}
}

vector<pair<int, int>> simulation;
int cntSim[maxN][maxN];

void addSimulation(int x, int y, int& count) {
	cntSim[x][y] = 2 - cnt[x][y];
	count++;
	if (x > 0 && s[x - 1][y] == '.') {
		cntSim[x - 1][y]++;
		simulation.push_back({ x - 1,y });
		if ((cntSim[x - 1][y] + cnt[x - 1][y]) == 2) addSimulation(x - 1, y, count);
	}
	if (x < n - 1 && s[x + 1][y] == '.') {
		cntSim[x + 1][y]++;
		simulation.push_back({ x + 1,y });
		if ((cntSim[x + 1][y] + cnt[x + 1][y]) == 2) addSimulation(x + 1, y, count);
	}
	if (y > 0 && s[x][y - 1] == '.') {
		cntSim[x][y - 1]++;
		simulation.push_back({ x,y - 1 });
		if ((cntSim[x][y - 1] + cnt[x][y - 1]) == 2) addSimulation(x, y - 1, count);
	}
	if (y < m - 1 && s[x][y + 1] == '.') {
		cntSim[x][y + 1]++;
		simulation.push_back({ x,y + 1 });
		if ((cntSim[x][y + 1] + cnt[x][y + 1]) == 2) addSimulation(x, y + 1, count);
	}
}

int iter[maxN][maxN], cur_iter = 0;

int simulate(int x, int y) {
	int result = 0;
	simulation.push_back({ x ,y });
	addSimulation(x, y, result);
	for (int i = 0; i < simulation.size(); i++) {
		cntSim[simulation[i].first][simulation[i].second] = 0;
	}
	simulation.clear();
	return result;
}

void solve(){
    all.clear();
    ans.clear();
    simulation.clear();
    candidates.clear();
    cur_iter=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            deg[i][j]=cnt[i][j]=iter[i][j]=cntSim[i][j]=0;
        }
    }

    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') continue;
			all.push_back({ i,j });
			if (i > 0 && s[i - 1][j] == '.') deg[i][j]++;
			if (i < n - 1 && s[i + 1][j] == '.') deg[i][j]++;
			if (j > 0 && s[i][j - 1] == '.') deg[i][j]++;
			if (j < m - 1 && s[i][j + 1] == '.') deg[i][j]++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (deg[i][j] == 1) {
				ans.push_back({ i,j });
				add(i, j);
			}
		}
	}

	while (all.size()) {
		if (candidates.empty()) {
			pair<int, int> last = all.back();
			all.pop_back();
			int x = last.first, y = last.second;
			if (cnt[x][y] != 0) continue;
			ans.push_back({ x,y });
			add(x, y);
			continue;
		}

		int curMax = 0, bestX, bestY;
		cur_iter++;

		for (auto it = candidates.begin(); it != candidates.end();) {
			int x = (*it).first, y = (*it).second;
			if (cnt[x][y] != 1) {
				candidates.erase(it++);
				continue;
			}

			if (x > 0 && s[x - 1][y] == '.' && cnt[x - 1][y] != 2 && iter[x - 1][y] != cur_iter) {
				int tmp = simulate(x - 1, y);
				iter[x - 1][y] = cur_iter;
				if (tmp > curMax) {
					curMax = tmp; bestX = x - 1; bestY = y;
				}
			}
			if (x < n - 1 && s[x + 1][y] == '.' && cnt[x + 1][y] != 2 && iter[x + 1][y] != cur_iter) {
				int tmp = simulate(x + 1, y);
				iter[x + 1][y] = cur_iter;
				if (tmp > curMax) {
					curMax = tmp; bestX = x + 1; bestY = y;
				}
			}
			if (y > 0 && s[x][y - 1] == '.' && cnt[x][y - 1] != 2 && iter[x][y - 1] != cur_iter) {
				int tmp = simulate(x, y - 1);
				iter[x][y - 1] = cur_iter;
				if (tmp > curMax) {
					curMax = tmp; bestX = x; bestY = y - 1;
				}
			}
			if (y < m - 1 && s[x][y + 1] == '.' && cnt[x][y + 1] != 2 && iter[x][y + 1] != cur_iter) {
				int tmp = simulate(x, y + 1);
				iter[x][y + 1] = cur_iter;
				if (tmp > curMax) {
					curMax = tmp; bestX = x; bestY = y + 1;
				}
			}

			it++;
		}

		if (curMax != 0) {
			ans.push_back({ bestX,bestY });
			add(bestX, bestY);
		}
	}
}

pair<int,int>  pos[maxN][maxN];
vector<pair<int,int>> bestAns;

void flip() {
    for(int i=0;i<n;i++){
        reverse(s[i].begin(),s[i].end());
        reverse(pos[i],pos[i]+m);
    }
}

void transpose(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            swap(s[i][j],s[j][i]);
            swap(pos[i][j],pos[j][i]);
        }
    }
}

void rotate90(){
    transpose();
    flip();
}

void updateAns(){
    if(!bestAns.empty() && bestAns.size()<ans.size()) return;
    bestAns.clear();
    for(int i=0;i<ans.size();i++){
        bestAns.push_back(pos[ans[i].first][ans[i].second]);
    }
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int t,threshold;
    cin>>t;
    string st;
    if(t<10) st='0'+to_string(t);
    else st=to_string(t);
    ifstream in("testcases\\"+st+".in");
    ofstream out("sols-gridi\\"+st+".out");

	in >> n >> m;

	for (int i = 0; i < n; i++) {
		in >> input[i];
	}

    if(t<=6){
        // Pokreni algoritam nad svim izometrijskim transformacijama ulaza i uzmi najbolji
        for (int i = 0; i < n; i++) {
            s[i]=input[i];
            for(int j=0;j<m;j++){
                pos[i][j] = {i,j};
            }
        }

        for(int i=0;i<4;i++){
            solve();
            cout<<ans.size()<<endl;
            updateAns();
            rotate90();
        }

        flip();

        for(int i=0;i<4;i++){
            solve();
            cout<<ans.size()<<endl;
            updateAns();
            rotate90();
        }
    }

    if(t==7){
        for (int i = 0; i < n; i++) {
            s[i]=input[i];
            for(int j=0;j<m;j++){
                pos[i][j] = {i,j};
            }
        }

        solve();
        updateAns();
    }

    if(t==8){
        int l=10,k=300;
        n=m=k;

        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                for(int ii=i*k;ii<i*k+k;ii++){
                    s[ii%k]="";
                    for(int jj=j*k;jj<j*k+k;jj++) {
                        s[ii%k]+=input[ii][jj];
                        pos[ii%k][jj%k]={ii,jj};
                    }
                }

                solve();
                for(int ii=0;ii<ans.size();ii++){
                    bestAns.push_back(pos[ans[ii].first][ans[ii].second]);
                }
                cout<<i*l+j<<endl;
            }
        }
    }

    cout<<bestAns.size()<<endl;

	out << bestAns.size() << endl;
	sort(bestAns.begin(), bestAns.end());

	for (int i = 0; i < bestAns.size(); i++) {
		input[bestAns[i].first][bestAns[i].second] = 'V';
		out << bestAns[i].first + 1 << " " << bestAns[i].second + 1 << endl;
	}
	/*
	for (int i = 0; i < n; i++) {
		fout << s[i] << endl;
	}*/
	return 0;
}
