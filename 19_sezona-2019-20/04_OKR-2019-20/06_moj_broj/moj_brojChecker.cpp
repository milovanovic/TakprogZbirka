#include<bits/stdc++.h>

using namespace std;

const int maxE = 1e8;
const int maxN = 125;
const int modSz = 10;
long long a[maxN], b[maxN];
int n, k;
string expr[maxN];
long long mo[modSz];
long long rez[modSz];
map<int, int> mp;
mt19937 rng(time(0));
stack<long long> numbers;
stack<char> operations;

int score()
{
    if (k<=12)
        return 100;
    if (k==13)
        return 90;
    if (k<=15)
        return 80;
    if (k<=18)
        return 70;
    if (k<=20)
        return 60;
    if (k<=22)
        return 50;
    if (k<=24)
        return 40;
    if (k<=27)
        return 30;
    if (k<=29)
        return 20;
    if (k<=31)
        return 10;

}
void check_B()
{
    if (k>31)
        exit(-1);

    for (int i=1; i<=k; i++)
        if (b[i]<0 || b[i]>maxE)
            exit(-1);
}

void checkStr(int idx, string &str)
{
    if (str.size()>10)
        exit(-1);

    for (int j = 0; j <str.size(); j++)
        if (!isdigit(str[j]) && ((str[j]!='-' && str[j]!='+') || j))
            exit(-1);

    b[idx] = stoi(str);
}

void makeExpr(int idx, string &str)
{
    expr[idx] = "";

    if (str.size()> 1000)
        exit(-1);

    int lastChar = 0;
    int spaceMode = 0;

    for (auto j:str)
    {
        if (j!=' ' && !isdigit(j) && j!='-' && j!='+' && j!='*' && j!='(' && j!=')')
            exit(-1);
        if (j!=' ')
        {
            if (spaceMode)
                if (isdigit(lastChar) && isdigit(j))
                    exit(-1);

            if (lastChar == '(' && !isdigit(j) &&  j!='(')
                exit(-1);
            if (j=='(' && (lastChar==')' || isdigit((j))))
                exit(-1);
            if (j=='+' && (!isdigit(lastChar) && lastChar != ')'))
                exit(-1);
            if (j=='-' && (!isdigit(lastChar) && lastChar != ')'))
                exit(-1);

            if (j=='*' && (!isdigit(lastChar) && lastChar != ')'))
                exit(-1);

            spaceMode = 0;
            expr[idx]+=j;
            lastChar = j;
        }
        else
            spaceMode = 1;
    }
}

void gen_mod()
{
    for (int i = 0 ; i < modSz; i++)
        mo[i] = maxE + rng()%2000000000 + 1;
}

void reset_data()
{
    mp.clear();

    for (int i = 1; i<=k; i++)
        mp[b[i]]++;

    while(!numbers.empty())
        numbers.pop();
}

int rang(char x)
{
    if (x=='*')
        return 2;
    if (x=='+' || x=='-')
        return 1;
    return 0;
}

long long oper(long long x, long long y, long long op, long long mo)
{
    if (op == '(')
        exit(-1);

    if (op == '+')
        return (x+y)%mo;

    if (op == '-')
        return (x-y+mo)%mo;

    if (op == '*')
        return (x*y)%mo;
}

void stack_op (long long mo)
{
    if (numbers.size() < 2)
        exit(-1);

    long long val1 = numbers.top();
    numbers.pop();
    long long val2 = numbers.top();
    numbers.pop();
    char op = operations.top();
    operations.pop();
    numbers.push(oper(val2, val1, op, mo));
}
long long eval(long long mo, int idx)
{
    string s = expr[idx];

    reset_data();

    for (int i = 0; i<s.size(); i++)
    {
        if (s[i] == '(')
        {
            operations.push(s[i]);
            continue;
        }

        if (isdigit(s[i]))
        {
            string str = "";

            while(i<s.size() && isdigit(s[i]))
            {
                str+=s[i];
                i++;
            }

            i--;

            if (str.size()>9)
                exit(-1);

            int val = stoi(str);

            if (mp[val])
                mp[val]--;
            else
                exit(-1);

            numbers.push(val);

            continue;
        }

        if (s[i] == ')')
        {
            while(operations.size() && operations.top() != '(')
                stack_op(mo);

            if (!operations.size())
                exit(-1);

            operations.pop();
            continue;
        }

        while(operations.size() && rang(operations.top()) >= rang(s[i]))
            stack_op(mo);

        operations.push(s[i]);
    }

    while(operations.size())
        stack_op(mo);

    if (numbers.size() != 1)
        return -1;

    return numbers.top();
}

int main(int argc, char *argv[])
{

    ifstream outFile(argv[1]);
    ifstream solFile(argv[2]);
    ifstream inFile(argv[3]);

    inFile>>n;

    for (int i = 1 ; i <= n; i++)
        inFile>>a[i];

    outFile>>k;

    if (k>31) return -1;

    for (int i=1; i<=k; i++)
    {
        string str;
        outFile>>str;
        checkStr(i, str);
    }

    check_B();

    string str;
    getline(outFile, str);
    for (int i = 1; i<=n; i++)
    {
        string str;
        getline(outFile, str);
        makeExpr(i, str);
    }

    inFile.close();
    solFile.close();
    outFile.close();

    gen_mod();

    for (int i = 1; i<=n; i++)
    {
        for (int j = 0 ; j<modSz; j++)
            if (eval(mo[j], i) != a[i])
                return -1;
    }

    return score();
}
