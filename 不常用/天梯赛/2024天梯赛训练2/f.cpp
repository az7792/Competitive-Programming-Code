#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    string cmp = "chi1 huo3 guo1";
    string str;
    int F = 0, ct = 0;
    for (int i = 1; 1; ++i)
    {
        getline(cin, str);
        if (str == ".")
        {
            cout << i - 1 << endl;
            if(F==0)
                cout << "-_-#";
            else
            {
                cout << F << " " << ct;
            }
            return;
        }
        if (str.find(cmp) != str.npos)
        {
            F += (F == 0 ? i : 0);
            ct++;
        }
    }
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
