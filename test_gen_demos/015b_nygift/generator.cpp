#include <bits/stdc++.h>
using namespace std;

#ifndef GENERATOR
int regis_subtask (string subtask)
{
    return 0;
}
#endif // GENERATOR

#include "template.h"
using namespace Templates;

namespace Gen
{
    // define outer functions here

    void gen (int iTest)
    {
        // your code goes here
        // complete this function - print your testcase into stdout

        long long n = Rand (1, 2e5), x = log_rand (1e18);

        if (iTest <= 8) regis_subtask ("n_le_2000"), n = Rand (1, 2000);
        else regis_subtask ("no_add_const");

        cout << n << ' ' << x << '\n';
        for (int i = 1; i <= n; i ++) cout << Rand (1, 1e18) << ' ';
    }
}

#ifndef GENERATOR
int main ()
{
    int iTest;
    cout << "Nhap thu tu test: ";
    cin >> iTest;

    while (iTest <= 0)
    {
        cout << "Nhap lai: ";
        cin >> iTest;
    }

    cout << "In test mau ra file [sample.txt] (y/n): ";
    string _ok;
    cin >> _ok;

    while (_ok != "y" and _ok != "n")
    {
        cout << "Nhap lai (y/n): ";
        cin >> _ok;
    }

    if (_ok == "y") freopen ("sample.txt", "w", stdout);
    else cout << "In test mau ra stdout.\nTest mau:\n";
    Gen::gen (iTest);
}
#endif // GENERATOR
