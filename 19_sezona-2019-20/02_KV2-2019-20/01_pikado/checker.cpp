#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

bool has_extra_tokens(ifstream& ifs) {
	string s;
	ifs >> s;
	return s.size() != 0;
}
int readInt(ifstream& ifs){
    string s;
    ifs >> s;
    if(s.size()==0||s.size()>8)
        exit(-1);
    int in=0;
    bool negativan=false,uneoBroj=false;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='-'){
            if(i!=0)
                exit(-1);
            negativan=true;
            continue;
        }
        uneoBroj=true;
        if('0'<=s[i]&&s[i]<='9')
            in=in*10+s[i]-'0';
        else
            exit(-1);
    }
    if(!uneoBroj)
        exit(-1);
    if(negativan)
        in*=-1;
    return in;
}
int main(int argc, char** argv) {
	ifstream ouf(argv[1]);
	ifstream sof(argv[2]);
	ifstream inf(argv[3]);
	int N;
	inf >> N;
    int n=readInt(ouf),correctN;
    sof >> correctN;
    if(n!=correctN)
        return -1;
    int br;
    vector<int> arr(2*N+1);
    for(int i=0;i<n;i++){
        br=readInt(ouf);
        if(br<-N||br>N)
            return -1;
        arr[br+N]++;
    }
    for(int i=0;i<n;i++)
        sof >> br,arr[br+N]--;
    for(int i=0;i<=2*N;i++)
        if(arr[i]!=0)
            return -1;
    if(has_extra_tokens(ouf))
        return -1;
    return 0;
}
