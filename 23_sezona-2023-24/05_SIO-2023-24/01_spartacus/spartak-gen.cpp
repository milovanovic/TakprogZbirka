#include "testlib.h"
#include <vector>

// defaults
const int N_LOWLIMIT = 1;
const int N_HILIMIT = 200;
const int K_LOWLIMIT = 0;
const int K_HILIMIT = 500;
const int S_HILIMIT = 1000;
const int CYCLE_DEFAULT = 0;
const int CYCLE_MAX = 1000;
// arguments
int max_n; // maximal N
int max_k; // maximal K
int cycle_percent; // probability of a node being in a cycle, out of 1000

int compsize_bias; 
int treesize_bias;
int parent_bias;
int s_bias;
int k_bias;
int is_path;
//

using namespace std;

void generateTree(vector<int> nodes, vector<int> &p) {
    for (unsigned i = 1; i < nodes.size(); i++) {
        int x = nodes[i];
        if (is_path) {
            p[x-1] = nodes[i-1];
        } else {
            p[x-1] = nodes[rnd.wnext(i, parent_bias)];
        }
    }
}

void generateComponent(vector<int> comp, vector<int> &p) {
    vector<int> cycle, leaves;
    for (auto x : comp) {
        int tmp = rnd.next(1, CYCLE_MAX); 
        if (tmp <= cycle_percent && !is_path) {
            cycle.push_back(x);
        } else {
            leaves.push_back(x);
        }
    }
    if (cycle.empty()) {
        cycle.push_back(leaves.back());
        leaves.pop_back();
    } 

    if (cycle.size() > 1) {
        int last = -1;
        for (auto x : cycle) {
            if (last == -1) {
                p[x-1] = cycle.back();
            } else {
                p[x-1] = last;
            }
            last = x;
        }
    }

    while (!leaves.empty()) {
        int root = rnd.next(0, (int)cycle.size()-1);
        int tree_size = rnd.wnext(1, (int)leaves.size(), treesize_bias);
        if (is_path) {
            tree_size = leaves.size();
        }
        vector<int> nodes = {cycle[root]};
        
        while (tree_size--) {
            nodes.push_back(leaves.back());
            leaves.pop_back();
        }
        generateTree(nodes, p);
    }
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    max_n = opt<int>("max-n", N_HILIMIT);
    max_k = opt<int>("max-k", K_HILIMIT); 
    cycle_percent = opt<int>("cycle-percent", CYCLE_DEFAULT); 

    compsize_bias = opt<int>("compsize-bias", 0); 
    treesize_bias = opt<int>("treesize-bias", -1);
    parent_bias = opt<int>("parent-bias", 0);
    s_bias = opt<int>("s-bias", 0);
    k_bias = opt<int>("k-bias", -3);
    is_path = opt<int>("is-path", 0);

    int n = rnd.next(max(N_LOWLIMIT, max_n*9/10), max_n);
    int K = rnd.next(max(K_LOWLIMIT, max_k*9/10), max_k);

    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    if (!is_path) {
        shuffle(perm.begin(), perm.end());
    } else {
        reverse(perm.begin(), perm.end());
    }

    int start = 0;
    vector<int> p(n), s(n), k(n);
    while (start < n) {
        int end;
        if (is_path) {
            end = n-1;
        } else if (cycle_percent == CYCLE_MAX) {
            do {
                end = start + rnd.wnext(n-start, compsize_bias);
            } while (end == n-2 || end == start);
        } else {
            end = start + rnd.wnext(n-start, compsize_bias);
        }
        vector<int> comp;
        for (int x = start; x <= end; x++) {
            comp.push_back(perm[x]+1);
        }
        start = end+1;
        generateComponent(comp, p);
    }

    for (int i = 0; i < n; i++) {
        s[i] = rnd.wnext(0, S_HILIMIT, s_bias);
        k[i] = rnd.wnext(0, K, k_bias);
    }

    println(n, K);
    println(p);
    println(s);
    println(k);
}

/*
spartak-gen 32123 -max-n 20 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 > $
spartak-gen 65422 -max-n 20 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 > $
spartak-gen 23647 -max-n 20 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 > $
spartak-gen 56421 -max-n 20 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 > $
spartak-gen 63462 -max-n 20 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 > $
spartak-gen 53423 -max-n 20 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 > $
spartak-gen 14511 -max-n 20 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 > $
spartak-gen 67523 -max-n 20 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 > $
spartak-gen 73436 -max-n 20 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 > $
spartak-gen 64523 -max-n 20 -cycle-percent 1000 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 100 > $
spartak-gen 53521 -is-path 1 -k-bias -10 > $
spartak-gen 75292 -is-path 1 -k-bias -10 > $
spartak-gen 23492 -is-path 1 -k-bias -10 > $
spartak-gen 18412 -is-path 1 -k-bias -10 > $
spartak-gen 31499 -is-path 1 -k-bias -10 > $
spartak-gen 12345 -is-path 1 -k-bias -10 > $
spartak-gen 54239 -is-path 1 -k-bias -10 > $
spartak-gen 41389 -is-path 1 -k-bias -10 > $
spartak-gen 64231 -is-path 1 -k-bias -10 > $
spartak-gen 43921 -is-path 1 -k-bias 100 > $
spartak-gen 34523 -cycle-percent 1000 -compsize-bias -15 -k-bias -150 > $
spartak-gen 31242 -cycle-percent 1000 -compsize-bias 3 -k-bias -150 > $
spartak-gen 45332 -cycle-percent 1000 -compsize-bias 30 -k-bias -150 > $
spartak-gen 34536 -cycle-percent 1000 -compsize-bias -20 -k-bias -150 > $
spartak-gen 45232 -cycle-percent 1000 -compsize-bias -11 -k-bias -150 > $
spartak-gen 68258 -cycle-percent 1000 -compsize-bias 3 -k-bias -150 > $
spartak-gen 23482 -cycle-percent 1000 -compsize-bias 3 -k-bias -150 > $
spartak-gen 93486 -cycle-percent 1000 -compsize-bias 3 -k-bias -150 > $
spartak-gen 19413 -cycle-percent 1000 -compsize-bias 3 -k-bias -150 > $
spartak-gen 65821 -cycle-percent 1000 -compsize-bias 3 -k-bias 100 > $
spartak-gen 34523 -cycle-percent 0 -compsize-bias 3 -k-bias -10 > $
spartak-gen 31242 -cycle-percent 0 -compsize-bias 3 -k-bias -10 > $
spartak-gen 45332 -cycle-percent 0 -compsize-bias 3 -k-bias -10 > $
spartak-gen 75623 -cycle-percent 0 -compsize-bias 3 -k-bias -10 > $
spartak-gen 45232 -cycle-percent 0 -compsize-bias 3 -k-bias -10 > $
spartak-gen 68258 -cycle-percent 0 -compsize-bias 3 -k-bias -10 > $
spartak-gen 23482 -cycle-percent 0 -compsize-bias 3 -k-bias -10 > $
spartak-gen 93486 -cycle-percent 0 -compsize-bias 3 -k-bias -10 > $
spartak-gen 19413 -cycle-percent 0 -compsize-bias 3 -k-bias -10 > $
spartak-gen 65821 -cycle-percent 0 -compsize-bias 3 -k-bias 100 > $
spartak-gen 54231 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 54632 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 87436 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 74642 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias -10 > $
spartak-gen 74568 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 24621 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 63572 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 57346 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 78432 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias -10 > $
spartak-gen 47264 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 75735 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias -10 > $
spartak-gen 46372 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 76767 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 34623 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias -10 > $
spartak-gen 73563 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 68434 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 63466 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 34634 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias -10 > $
spartak-gen 24523 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 46244 -cycle-percent 200 -compsize-bias 3 -treesize-bias -1 -parent-bias 1 -k-bias 10 > $
spartak-gen 62562 -cycle-percent 0 -compsize-bias 3 -k-bias -10 > $
spartak-gen 63425 -cycle-percent 0 -compsize-bias 3 -k-bias -10 > $
spartak-gen 73455 -cycle-percent 0 -compsize-bias 3 -k-bias -10 > $
spartak-gen 76344 -cycle-percent 0 -compsize-bias 3 -k-bias -10 > $

Ručno: 1, 11, 22, 30
*/