#include <cstdio>
#include <cstring>
#include <cstdlib>

#define OK 0
#define WA -1

bool read_possible(FILE *f) {
    char s[100];
    if(!fgets(s, 99, f))
        exit(WA);

    if(strcmp(s, "moguce") == 0 || strcmp(s, "moguce\n") == 0) 
        return true;
    else if(strcmp(s, "nemoguce") == 0 || strcmp(s, "nemoguce\n") == 0) 
        return false;
    else exit(WA);
}

enum GROUP { O, A, B, AB } ;

GROUP parse_group(const char *s) {
    if(s[0] == 'O') return O;
    else if(s[0] == 'A') return s[1] == 'B' ? AB : A;
    else return B;
}

int main(int argc, char *argv[]) {
    FILE *out = fopen(argv[1], "r");
    FILE *sol = fopen(argv[2], "r");
    FILE *in = fopen(argv[3], "r");

    if(in == NULL || sol == NULL || out == NULL) return WA;

    bool possible = read_possible(sol);
    bool out_possible = read_possible(out);

    if(possible != out_possible) return WA;
    if(!possible) return OK;

    int n, o, a, b, ab;
    fscanf(in, "%d", &n);
    fscanf(in, "%d %d %d %d", &o, &a, &b, &ab);

    for(int i = 0; i < n; i++) {
        char group_s[20];
        int need;
        fscanf(in, " %s %d", &group_s, &need);
        GROUP group = parse_group(group_s);

        int uo, ua, ub, uab;
        if(fscanf(out, "%d %d %d %d", &uo, &ua, &ub, &uab) != 4) return WA;
        
        // impossible or out-of-resources transfer
        if(uo < 0 || ua < 0 || ub < 0 || uab < 0) return WA;
        if(uo > o || ua > a || ub > b || uab > ab) return WA;

        // invalid group transfer
        if(group == O && (ua || ub || uab)) return WA;
        if(group == A && (ub || uab)) return WA;
        if(group == B && (ua || uab)) return WA;

        // didn't satisfy request
        if(uo + ua + ub + uab != need) return WA;
    }

    return OK;
}
