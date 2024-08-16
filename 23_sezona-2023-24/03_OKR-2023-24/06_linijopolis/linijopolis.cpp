#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

#define MAXN 1000000
#define MAXM 1000000

// indeksirano od nule
int M, N;
int A[MAXM];
int X[MAXN], B[MAXN];

struct autobus {
    int broj;
    long long bitovi;
} buff[MAXM];

void ulaz() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }
}

bool isprobaj_resenje(int broj) {
    if (broj == 0) {
        return true;
    }
    stack<autobus> busevi;
    for (int i = 0; i < broj; i++) {
        autobus bus;
        bus.bitovi = A[M - i - 1];
        bus.broj = 1;
        busevi.push(bus);
    }
    long long udaljenost = 0;
    for (int i = 0; i < N - 1; i++) {
        int preostalo = B[i];
        while (preostalo > 0) {
            bool spojDva = false;
            bool barDva = (busevi.size() > 1);
            autobus najmanji = busevi.top();
            busevi.pop();
            if (barDva) {
                autobus drugi = busevi.top();
                long long razlika = drugi.bitovi - najmanji.bitovi;
                spojDva = (razlika * najmanji.broj <= preostalo);
            }
            if (spojDva) {
                autobus drugi = busevi.top();
                busevi.pop();
                long long razlika = drugi.bitovi - najmanji.bitovi;
                preostalo -= razlika * najmanji.broj;
                drugi.broj += najmanji.broj;
                busevi.push(drugi);
            } else {
                int broj_dodatnih = preostalo % najmanji.broj;
                int uvecanje = preostalo / najmanji.broj;
                preostalo = 0;
                najmanji.bitovi += uvecanje;
                najmanji.broj -= broj_dodatnih;
                busevi.push(najmanji);
                if (broj_dodatnih > 0) {
                    autobus novi;
                    novi.broj = broj_dodatnih;
                    novi.bitovi = najmanji.bitovi + 1;
                    busevi.push(novi);
                }
            }
        }
        long long najmanje = busevi.top().bitovi;
        udaljenost += abs(X[i + 1] - X[i]);
        if (najmanje < udaljenost) {
            return false;
        }
    }
    return true;
}

void resi() {
    sort(A, A + M);
    int levo = 0, desno = M;
    while (levo < desno) {
        int pokusaj = (levo + desno + 1) / 2;
        if (isprobaj_resenje(pokusaj)) {
            levo = pokusaj;
        } else {
            desno = pokusaj - 1;
        }
    }
    printf("%d\n", levo);
}

int main() {
    ulaz();
    resi();
    return 0;
}