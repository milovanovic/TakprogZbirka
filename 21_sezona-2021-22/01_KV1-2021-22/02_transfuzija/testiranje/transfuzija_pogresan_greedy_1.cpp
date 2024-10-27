#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

enum grupa_rh {
  O = 0, A, B, AB, ERR
};

int red(grupa_rh& x) {
  switch (x) {
    case O:
      return 0;
    case A:
      return 1;
    case B:
      return 2;
    case AB:
      return 3;
    default:
      return 4;
  }
}

struct pacijent {
  grupa_rh krv;
  int kolicina;
  int resenje[4];
  int orig_id;
} pacijenti[10000];

bool operator<(pacijent& a, pacijent& b) {
  return red(a.krv) < red(b.krv) || (a.krv == b.krv && a.kolicina < b.kolicina);
}

bool cmp(pacijent& a, pacijent& b) {
  return a.orig_id < b.orig_id;
}

grupa_rh str_u_grupu(string& s) {
  if (!s.compare("A")) { return A; }
  if (!s.compare("B")) { return B; }
  if (!s.compare("AB")) { return AB; }
  if (!s.compare("O")) { return O; }
  return ERR;
}

int zalihe[4];
int n;
string tren_grupa;
vector<grupa_rh> raspored[4] = { vector<grupa_rh>({O}),
                                 vector<grupa_rh>({A, O}),
                                 vector<grupa_rh>({B, O}),
                                 vector<grupa_rh>({AB, A, B, O}) };
bool nemoguce = false;

int main() {
  cin >> n;
  for (int i = 0; i < 4; i++) {
    cin >> zalihe[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> tren_grupa >> pacijenti[i].kolicina;
    pacijenti[i].krv = str_u_grupu(tren_grupa);
    for (int j = 0; j < 4; j++) {
      pacijenti[i].resenje[j] = 0;
    }
  }
  sort(pacijenti, pacijenti + n);
  for (int i = 0; i < n && !nemoguce; i++) {
    for (grupa_rh gr : raspored[pacijenti[i].krv]) {
      int m = min(zalihe[gr], pacijenti[i].kolicina);
      zalihe[gr] -= m;
      pacijenti[i].kolicina -= m;
      pacijenti[i].resenje[gr] += m;
    }
    if (pacijenti[i].kolicina > 0) {
      nemoguce = true;
    }
  }
  sort(pacijenti, pacijenti + n, cmp);
  if (nemoguce) {
    cout << "nemoguce" << endl;
  } else {
    cout << "moguce" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 4; j++) {
        cout << pacijenti[i].resenje[j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
