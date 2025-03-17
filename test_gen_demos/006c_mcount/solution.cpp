#include <bits/stdc++.h>
using namespace std;

const long long sqr = 450, MOD = 1e9 + 7, MAX = 2e5 + 5;
long long n, k;

long long add_mod (long long &a, long long b)
{
    a += b;
    if (a > MOD) a -= MOD;
    return a;
}

long long dp1[sqr + 5], dp2[sqr + 5];

void Add (long long u)
{
    //cout << u << '\n';

    long long i;
    for (i = u; i * i <= k; i ++)
        if (dp2[i]) add_mod (dp2[i / u], dp2[i]);

    //cout << i << '\n';

    for (-- i, i = min (i, k / u); i >= 1; i --)
    {
        long long t = i * u;

        //if (t > k) continue;
        if (!dp1[i]) continue;
        if (t * t <= k)
            add_mod (dp1[t], dp1[i]);
        else add_mod (dp2[k / t], dp1[i]);
    }
}

long long cal ()
{
    long long ans = 0;
    for (long long i = 1; i * i <= k; i ++)
    {
        add_mod (ans, dp1[i]);
        add_mod (ans, dp2[i]);
    }

    add_mod (ans, MOD - 1);
    return ans;
}

int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    freopen ("MCOUNT.inp", "r", stdin);
    freopen ("MCOUNT.out", "w", stdout);

    cin >> n >> k;

    dp1[1] = 1;

    while (n --)
    {
        int t;
        cin >> t;

        Add (t);
    }

    cout << cal ();
}
