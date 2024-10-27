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
int main(int argc, char** argv) {
	ifstream ouf(argv[1]);
	ifstream sof(argv[2]);
	ifstream inf(argv[3]);
	int moj;
	string takmicar;
	sof >> moj;
  ouf >> takmicar;
  if(takmicar=="Nema"){
  	string drugiDeo;
  	ouf >> drugiDeo;
  	if(drugiDeo!="spasa")
  		return -1;
  	if(moj==-1)
  		return 0;
  	return -1;
  }
  string drugiDeo,treciDeo;
  ouf >> drugiDeo >> treciDeo;
  if(takmicar!="Svet"||drugiDeo!="je"||treciDeo!="spasen")
  	return -1;
  int N;
  inf >> N;
  int K;
  ouf >> K;
 	if(moj!=K)
 		return -1;
  vector<int> perm(N+1);
  for(int i=1;i<=N;i++)
  	inf >> perm[i];
  vector<bool> done(N+1);
  for(int i=0;i<K;i++){
  	int l,r;
  	ouf >> l >> r;
  	if(l<1||l>N||r<1||r>N||l>r)
  		return -1;
  	for(int j=l;j<=r;j++){
  		if(done[j])
  			return -1;
  		done[j]=1;
  	}
  	for(int j=l;r-j+l>j;j++)
  		swap(perm[j],perm[r-j+l]);
  }
  for(int i=1;i<=N;i++)
  	if(perm[i]!=i)
  		return -1;
 	if(has_extra_tokens(ouf))
      return -1;
  return 0;
}
