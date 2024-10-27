#include <cstdio>

const int MAX_LEN = 10 << 10;
const int WA = -1, OK = 0;

// Lazy checker for multiple-string inputs: treats arbitrary amounts
// of whitespace as a single ' '. Assumes inputs are reasonably short
// (up to 10 kB); longer inputs are truncated.

bool space(char c) {
    return c == ' ' || c == '\n' || c == '\t' || c == '\r';
}
char normalised(char c) {
    return space(c) ? ' ' : c;
}

int main(int argc, char **argv) {
    FILE *fout = fopen(argv[1], "r");
    FILE *fsol = fopen(argv[2], "r");

    if(!fout || !fsol) {
        return WA;
    }

    char *out = new char[MAX_LEN + 1];
    char *sol = new char[MAX_LEN + 1];

    int nout = fread(out, sizeof(char), MAX_LEN, fout);
    int nsol = fread(sol, sizeof(char), MAX_LEN, fsol);

    if(!nout || !nsol) {
        return WA;
    }
    
    // Trim trailing whitespace and terminate
    while(nout && space(out[nout - 1])) nout--;
    while(nsol && space(sol[nsol - 1])) nsol--;
    out[nout] = sol[nsol] = '\0';

    char *i = out, *j = sol;
    while(*i != '\0' && *j != '\0') {
        if(normalised(*i) != normalised(*j))
            return WA;

        // Treat consecutive whitespace chars as a single space
        while(space(*i) && space(*(i+1))) i++;
        while(space(*j) && space(*(j+1))) j++;

        i++; j++;
    }

    if(*i != '\0' || *j != '\0') {
        // Mismatched number of tokens
        return WA;
    } else {
        return OK;
    }
}
