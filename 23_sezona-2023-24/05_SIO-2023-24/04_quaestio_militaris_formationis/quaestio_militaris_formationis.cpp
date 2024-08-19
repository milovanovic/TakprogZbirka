#include <bits/stdc++.h>
using namespace std;

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

vector<int> inverse(vector<int> perm){
    vector<int> perm_inv(perm.size());
    for(int i = 0; i < perm.size(); i++){
        perm_inv[perm[i] - 1] = i + 1;
    }
    return perm_inv;
}

vector<int> compose(vector<int> p, vector<int> q){
    vector<int> res;
    for(int i = 0; i < q.size(); i++){
        res.push_back(p[q[i] - 1]);
    }
    return res;
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


void Formacija(int N, int* P, int* Q, int* R, long long& Slabost){
    vector<int> p, q, r;
    for (int i = 1; i <= N; i++){
        p.push_back(P[i]);
        q.push_back(Q[i]);
    }

    vector<int> pinv = inverse(p);
    vector<int> pinv_q = compose(pinv, q);
    long long pinv_q_inversions = count_inversions(pinv_q);

    long long inv_cnt = 0;
    int i;
    long long *tree = new long long[N + 1];
    init(tree, N);
    for(i = 0; i < N; i++){
        int cur_inv_cnt = i - getSum(tree, pinv_q[i]);
        if(inv_cnt + cur_inv_cnt >= pinv_q_inversions/2){
            break;
        }
        inv_cnt += cur_inv_cnt;
        update(tree, N, pinv_q[i], 1);
    }
    delete[] tree;

    vector<int> pinv_rinv;
    pinv_rinv = pinv_q;
    sort(pinv_rinv.begin(), pinv_rinv.begin() + i);
    int operations_remaining = pinv_q_inversions/2 - inv_cnt;
    for(int j = i; j > i - operations_remaining; j--){
        swap(pinv_rinv[j], pinv_rinv[j - 1]);
    }

    vector<int> rinv = compose(p, pinv_rinv);
    r = inverse(rinv);

    for (int i = 0; i < N; i++){
        R[i+1] = r[i];
    }
    Slabost = (pinv_q_inversions + 1)/2;
}
