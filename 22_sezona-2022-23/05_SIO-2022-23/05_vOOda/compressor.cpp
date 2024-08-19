#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// Parametri
const string folderPath = "sols\\"; // Putanja do foldera sa resenjima
const string testcaseExtension = ".out"; // Eksternzija fajla sa resenjima
int m[8] = {10, 600, 20, 700, 100, 300, 1000, 3000}; // Broj kolona svakog primera

//Funkcija za kompresiju koju mozete prekopirati u svoj kod

vector<int> compress(int m,vector<pair<int,int>> &ans){
    sort(ans.begin(),ans.end());
    vector<int> compressed;

    int last = 0;

    for(int i=0;i<ans.size();i++){
        compressed.push_back(m*(ans[i].first-1)+ans[i].second-last);
        last = m*(ans[i].first-1)+ans[i].second;
    }

    return compressed;
}

int main() {

    for(int t=1;t<=8;t++){
        string st;

        if(t<10) st='0'+to_string(t);
        else st=to_string(t);

        ifstream in(folderPath+st+testcaseExtension);

        if(!in.good()) {
            cout<<"Ne postoji fajl: "<<folderPath+st+testcaseExtension<<endl;
            continue; // Ukoliko ne postoji fajl za odgovarajuci primer preskoci ga
        }

        ofstream out(folderPath+st+"c"+testcaseExtension);

        int total,x,y;
        vector<pair<int,int>> ans;
        vector<int> compressed;

        in>>total;
        for(int i=0;i<total;i++) {
            in>>x>>y;
            ans.push_back({x,y});
        }

        compressed = compress(m[t-1],ans);

        out<<compressed.size()<<endl;
        for(int i=0;i<compressed.size();i++){
            out<<compressed[i]<<" ";
        }
    }

	return 0;
}
