#include <iostream>
#include <algorithm>
#include <random>
#include <utility>
#include <vector>
#include <queue>
#include <fstream>
#define PRINT(x) cerr<<#x<<'='<<x<<endl;
using namespace std;

const string folder="";

mt19937 rng(120502);

int get_int_from_range(int l,int r){
	assert(l<=r);
	return uniform_int_distribution<int>(l, r)(rng);
}

///resenje
int solve(int N, int M, vector<int> a, vector<pair<int, int> > days) {
  sort(days.begin(), days.end());
  int pref[N+2], ends[N+2];
  fill(pref, pref+N+2, 0);
  fill(ends, ends+N+2, 0);
  for(auto x : days) {
    pref[x.first]++;
    pref[x.second+1]--;
  }
  for(int i = 1; i <= N; i++) {
    pref[i] += pref[i-1];
  }
  priority_queue<int> pq;
  int idx = 0, res = 0, active = 0;
  for(int i = 1; i <= N; i++) {
    while(idx < M && days[idx].first == i) {
      pq.push(days[idx].second);
      idx++;
    }
    while(pref[i] > a[i-1] && pref[i]-a[i-1] > active) {
      int r = pq.top(); pq.pop();
      ends[r]++;
      active++;
      res++;
    }
    active -= ends[i];
  }
  return res;
}
///
void save_test_case(int tc,int n, int m, vector<int> a, vector<pair<int, int> > days){
	ofstream out(folder+to_string(tc)+".in");
	out << n << " " << m << "\n";
	assert(a.size()==n);
	for(int i=0;i<n;i++){
		if(i != n-1) out<<a[i]<<" ";
    else out << a[i];
	}
	out << "\n";
  assert(days.size()==m);
  for(int i=0;i<m;i++) {
        out<<days[i].first << ' ' << days[i].second << '\n';
  }
	out.close();

  ofstream sol(folder+to_string(tc)+".out");
  sol << solve(n, m, a, days);
  sol.close();
	PRINT(tc);
}

vector<pair<int, int> > generate_intervals(int n, int m) {
	vector<pair<int, int> > days;
	for(int i = 0; i < m; i++) {
		int tip = get_int_from_range(1, 7);
		int len;
		if(tip <= 4) len = n/2;
		else if(tip <= 6) len = n/4;
		else len = n/8;
		int l = get_int_from_range(1, n-len+1);
		int r = l+len-1;
		days.push_back({l, r});
	}
	return days;
}

void generate_subtask_5(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(197000,200000);
		int m=get_int_from_range(197000,200000);
		vector<int> a(n);
		vector<pair<int, int> > days;
		if(tc <= r-2) {
			for(int i = 0; i < n; i++) {
				int tip = get_int_from_range(1, 50);
				if(tip == 1) {
					a[i] = get_int_from_range(1, 50);
				} else {
					a[i] = get_int_from_range(1, 1000000000);
				}
			}
			days = generate_intervals(n, m);
			save_test_case(tc,n,m,a,days);
		} else if(tc == r-1) {
			for(int i = 0; i < m; i++) {
				days.push_back({1, n});
			}
			for(int i = 0; i < n; i++) {
				a[i] = i+1;
			}
		} else if(tc == r) {
			for(int i = 0; i < m; i++) {
				days.push_back({1, n});
			}
			for(int i = 0; i < n; i++) {
				a[i] = n-i+1;
			}
		}
		save_test_case(tc,n,m,a,days);
	}
}

void generate_subtask_4(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(1970,2000);
		int m=get_int_from_range(1970,2000);
		vector<int> a(n);
		for(int i = 0; i < n; i++) {
			int tip = get_int_from_range(1, 50);
			if(tip == 1) {
				a[i] = get_int_from_range(1, 50);
			} else {
				a[i] = get_int_from_range(1, 1000000000);
			}
		}
    vector<pair<int, int> > days = generate_intervals(n, m);
		save_test_case(tc,n,m,a,days);
	}
}

void generate_subtask_3(int l,int r){
	for(int tc=l;tc<=r;tc++){
    int n=get_int_from_range(197000,200000);
		int m=get_int_from_range(197000,200000);
		vector<int> a(n);
		vector<pair<int, int> > days;
		if(tc < r) {
			for(int i = 0; i < n; i++) {
				int tip = get_int_from_range(1, 100);
				if(tip == 1 && tc != l) {
					a[i] = 0;
				} else {
					a[i] = 1000000000;
				}
			}
			days = generate_intervals(n, m);
		} else {
			for(int i = 0; i < n; i++) {
				a[i] = 0;
			}
			for(int i = 0; i < m; i++) {
				days.push_back({1, n});
			}
		}
		save_test_case(tc,n,m,a,days);
	}
}

void generate_subtask_2(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(197000,200000);
		int m=get_int_from_range(45000,n/2);
		vector<int> a(n);
    vector<pair<int, int> > days(m);
		for(int i = 0; i < n; i++) {
			a[i] = get_int_from_range(0, 1000000000);
		}
		vector<int> rem, rem1, idx;
		for(int i = 0; i < n; i++) {
			rem.push_back(i+1);
		}
		for(int i = 0; i < 2*m; i++) {
			if(i%500 == 0) {
				for(auto x : rem) {
					if(x != 0) rem1.push_back(x);
				}
				rem = rem1;
				rem1.clear();
			}
			while(1) {
				int idxx = get_int_from_range(0, rem.size()-1);
				if(rem[idxx] > 0) {
					idx.push_back(rem[idxx]);
					rem[idxx] = 0;
					break;
				}
			}
		}
		sort(idx.begin(), idx.end());
		for(int i = 0; i < 2*m; i += 2) {
			days[i/2].first = idx[i];
			days[i/2].second = idx[i+1];
			int tip = get_int_from_range(1, 3);
			if(tip == 1) {
				a[get_int_from_range(idx[i], idx[i+1])] = 0;
			}
		}
		save_test_case(tc,n,m,a,days);
	}
}

void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(197000,200000);
		int m=get_int_from_range(197000,200000);
		vector<int> a(n);
		vector<pair<int, int> > days;
		for(int i = 0; i < n; i++) {
			int tip = get_int_from_range(1, 50);
			if(tip == 1) {
				a[i] = get_int_from_range(1, 50);
			} else {
				a[i] = get_int_from_range(1, 1000000000);
			}
		}
		int rem = m;
		for(int i = 0; i < n && rem > 0; i++) {
			if(a[i] <= 50) {
				int koliko = get_int_from_range(0, min(rem, 2*a[i]));
				for(int j = 0; j < koliko; j++) {
					days.push_back({i+1, i+1});
				}
				rem -= koliko;
			}
		}
		while(rem > 0) {
			days.push_back({1, 1});
			rem--;
		}
		shuffle(days.begin(), days.end(), rng);
		save_test_case(tc,n,m,a,days);
	}
}

void generate_subtask_0(int l, int r) {
    ///1.in
    int N1 = 5, M1 = 4;
    vector<int> a1 = {3, 1, 0, 0, 3};
    vector<pair<int, int> > days1 = {{1, 3}, {1, 2}, {1, 5}, {4, 5}};
    save_test_case(1, N1, M1, a1, days1);
    ///2.in
    int N2 = 6, M2 = 9;
    vector<int> a2 = {4, 1, 2, 3, 1, 2};
    vector<pair<int, int> > days2 = {{2, 4}, {1, 3}, {4, 4}, {1, 4},
        {5, 6}, {3, 4}, {6, 6}, {3, 3}, {1, 6}};
    save_test_case(2, N2, M2, a2, days2);
}

int main(){
  generate_subtask_0(1, 2);  ///samples, 2
	generate_subtask_1(3, 6);  ///l_i = r_i, 4
	generate_subtask_2(7, 10);  ///disjunktni intervali, 4
	generate_subtask_3(11, 15);///a_i in {0, 10^9}, 4
	generate_subtask_4(16, 21);///N, M <= 2000, 6
	generate_subtask_5(22, 31);///ostalo, 8
	return 0;
}
