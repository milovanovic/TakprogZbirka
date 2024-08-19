#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
long long prefix_sum[MAXN];
int solve (vector<int> &arr, int S) {
    // cout << "DEBUG: ";
    // for (int x : arr) cout << x << " ";
    // cout << " [" << S << "]" << endl;
    // how many operations do we need to 
    if (arr.size() == 1) {
        assert (arr[0] == S);
        return 0;
    }
    int left_S = S / 2, cur_sum = 0;
    int N = (int)arr.size();
    vector<int> left_part, right_part; int i_right = -1;
    int splits = 0;
    for (int i = 0; i < N; i++) {
        if (cur_sum + arr[i] < left_S) {
            left_part.push_back(arr[i]);
        } else if (cur_sum + arr[i] == left_S) {
            left_part.push_back(arr[i]);
            i_right = i + 1;
            break;
        } else {
            // needs to split i-th element
            i_right = i + 1;
            int need_left = left_S - cur_sum;
            int val = arr[i];
            // cout << i_right << " " << need_left << " " << val;
            while (true) {
                if (val == need_left) {
                    left_part.push_back(val);
                    need_left = 0;
                    break;
                }
                if (0 == need_left) {
                    right_part.push_back(val);
                    break;
                }
                splits += 1; 
                int left_half = val / 2;
                if (left_half <= need_left) {
                    need_left -= left_half;
                    left_part.push_back(left_half);
                    val -= left_half;
                } else {
                    right_part.push_back(val - left_half);
                    val = left_half;
                }
            }
            break;
        }
        cur_sum += arr[i];
    }
    reverse(right_part.begin(), right_part.end());
    for (int i = i_right; i < N; i++) {
        right_part.push_back(arr[i]);
    }
    return 1 + splits + solve(left_part, left_S) + solve(right_part, S - left_S);
}
int Resi (int N, int* A) {
    assert (1 <= N); assert (N <= 100000);
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = A[i];
    }
    int S = accumulate(arr.begin(), arr.end(), 0);
    assert (1 <= S); assert (S <= 1000000);
    return solve(arr, S);
}
