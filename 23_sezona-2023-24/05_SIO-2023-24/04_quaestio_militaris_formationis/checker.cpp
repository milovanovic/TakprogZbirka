#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool has_extra_tokens(ifstream& ifs) {
	string s;
	ifs >> s;
	return s.size() != 0;
}

void init(long long* tree, int N){
    for (int i = 0; i <= N; i++){
        tree[i] = 0;
    }
}

int getSum(long long* tree, int idx){
    long long sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void update(long long* tree, int N, int idx, int val){
    while (idx <= N){
       tree[idx] += val;
       idx += idx & (-idx);
    }
}

long long count_inversions(vector<int> p){
    long long *tree = new long long[p.size() + 1];
    init(tree, p.size());
    long long invcnt = 0;
    for (int i = p.size() - 1; i >= 0; i--){
        invcnt += getSum(tree, p[i] - 1);
        update(tree, p.size(), p[i], 1);
    }
    delete[] tree;
    return invcnt;
}

vector<int> compose(vector<int> p, vector<int> q){
    vector<int> res;
    for(int i = 0; i < q.size(); i++){
        res.push_back(p[q[i] - 1]);
    }
    return res;
}

int main(int argc, char** argv) {
	ifstream ouf(argv[1]);
	ifstream sof(argv[2]);
	ifstream inf(argv[3]);

    string a;
    sof >> a;
    if (a.size() == 0) {
        if (has_extra_tokens(ouf)) {
            return -1;
        } else {
            return 0;
        }
    } else {
        int N;
        inf >> N;
        vector<int> p, q;
        for (int i = 0; i < N; i++){
            int in;
            inf >> in;
            p.push_back(in);
        }
        for (int i = 0; i < N; i++){
            int in;
            inf >> in;
            q.push_back(in);
        }

        int *R = new int[N];
        long long Slabost;
        sof >> Slabost;

        int *oR = new int[N];
        long long oSlabost;
        ouf >> oSlabost;

        if(Slabost != oSlabost){
            return -1;
        }

        if(a == "1"){
            for (int i = 0; i < N; i++){
                ouf >> oR[i];
            }
            vector<int> v(N),u(N);
            for(int i = 0; i < N; i++){
                v[i] = oR[i];
                u[i] = oR[i];
            }
            sort(u.begin(), u.end());
            for(int i = 0; i < N; i++){
                if(u[i] != i + 1){
                    return -1;
                }
            }
            if(max(count_inversions(compose(v, p)), count_inversions(compose(v, q))) != Slabost){
                return -1;
            }
        }
    }
}
