#include "testlib.h"
#include <iostream>
using namespace std;


#define MAXN 100000
#define MAXS 1000000

vector<int> v;

int main(int argc, char* argv[])
{

	registerGen(argc, argv, 1);

	int t = atoi(argv[1]);
	int p = atoi(argv[2]);
	
	if(t == 0){
	   if(p == 1){
	       printf("3\n1 2 1\n");
	   }
	   else if(p == 2){
	       printf("9\n1 1 1 1 1 1 1 1 1\n");
	   }
	   
	   return 0;
	}

    if (t == 1) {
        int max_nr = 5;
        if(p%2==0){
            max_nr = 10;
        }
        int S = 20;
        int next_nr = rnd.next(1, max_nr);
        int cur_sum = next_nr;
        while(cur_sum <= S){
            v.push_back(next_nr);
            next_nr = rnd.next(1, max_nr);
            cur_sum += next_nr;
        }
    }
    if (t == 2) {
        int max_nr = 10;
        int S = MAXS;
        int N = MAXN;
        int next_nr = rnd.next(1, max_nr);
        next_nr = next_nr <= p ? 1 : 2;
        int cur_sum = next_nr;
        int cnt = 1;
        while(cur_sum <= S && cnt <= N){
            v.push_back(next_nr);
            next_nr = rnd.next(1, max_nr);
            next_nr = next_nr <= p ? 1 : 2;
            cur_sum += next_nr;
            cnt++;
        }
    }
    if (t == 3) {
        int S = 1000;
        int N = MAXN;
        int max_nr = 100;
        if(p%3==1){
            max_nr = 10;
        }
        if(p%3==2){
            max_nr = 40;
        }
        int next_nr = rnd.next(1, max_nr);
        int cur_sum = next_nr;
        int cnt = 1;
        while(cur_sum <= S && cnt <= N){
            v.push_back(next_nr);
            next_nr = rnd.next(1, max_nr);
            cur_sum += next_nr;
            cnt++;
        }
    }
    if (t == 4) {
        int S = 100000;
        int N = MAXN;
        int max_nr = 10000;
        if(p%4==1){
            max_nr = 10;
        }
        if(p%4==2){
            max_nr = 100;
        }
        if(p%4==3){
            max_nr = 1000;
        }
        int next_nr = rnd.next(1, max_nr);
        int cur_sum = next_nr;
        int cnt = 1;
        while(cur_sum <= S && cnt <= N){
            v.push_back(next_nr);
            next_nr = rnd.next(1, max_nr);
            cur_sum += next_nr;
            cnt++;
        }
    }
    if (t == 5) {
        int S = MAXS;
        int N = MAXN;
        int max_nr = 100000;
        if(p%5==1){
            max_nr = 10;
        }
        if(p%5==2){
            max_nr = 100;
        }
        if(p%5==3){
            max_nr = 1000;
        }
        if(p%5==3){
            max_nr = 10000;
        }
        int next_nr = rnd.next(1, max_nr);
        int cur_sum = next_nr;
        int cnt = 1;
        while(cur_sum <= S && cnt <= N){
            v.push_back(next_nr);
            next_nr = rnd.next(1, max_nr);
            cur_sum += next_nr;
            cnt++;
        }
    }
    
    printf("%d\n", v.size());
    for(int i = 0; i < v.size(); i++){
        printf("%d", v[i]);
        if(i != v.size() - 1){
            printf(" ");
        }
    }
    printf("\n");
    
	return 0;
}



