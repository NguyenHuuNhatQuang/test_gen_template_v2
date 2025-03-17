#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("NYGIFT.inp");
    ofstream fout("NYGIFT.out");
    long long n, m;
    fin >> n >> m;
    vector<long long> a(n);
    for (auto &x : a) {
        fin >> x;
        x %= m;
    }
    sort(a.begin(), a.end());

    long long s2 = a[n-1] + a[n-2];
    if (s2 < m) {
        fout << s2 << endl;
        return 0;
    }

    long long max_sum = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        long long current_sum = a[left] + a[right];
        if (current_sum < m) {
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
            left++;
        } else {
            right--;
        }
    }

    long long candidate2 = s2 - m;
    fout << max(max_sum, candidate2) << endl;

    return 0;
}
