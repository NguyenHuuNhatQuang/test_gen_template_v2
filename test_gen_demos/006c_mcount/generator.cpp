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

        int n = Rand (1, 1e5), x = Rand (1, 2e5), a_max = 2e5, sub4 = false, sub5 = false;

        if (iTest <= 4) regis_subtask ("sub1"), n = Rand (1, 20);
        else if (iTest <= 8) regis_subtask ("sub2"), a_max = 1;
        else if (iTest <= 12) regis_subtask ("sub3"), n = Rand (1, 5000), x = Rand (1, 5000);
        else if (iTest <= 15) regis_subtask ("sub4"), sub4 = true;
        else if (iTest <= 18) regis_subtask ("sub5"), x = n, sub5 = true;
        else regis_subtask ("sub6");

        cout << n << ' ' << x << '\n';

        for (int i = 1; i <= n; i ++)
        {
            if (sub4) cout << (1 << Rand (0, (63 - __builtin_clzll (x)))) << ' ';
            else if (sub5) cout << i << ' ';
            else cout << log_rand (x) << ' ';
        }
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
