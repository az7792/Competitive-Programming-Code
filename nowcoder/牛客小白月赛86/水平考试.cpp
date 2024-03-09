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
    string s, t;
    cin >> s >> t;
    if (t.size() == 1)
    {
        if (s[0] == t[0] && s.size() == 1)
            cout << 10 << endl;
        else
            cout << 0 << endl;
    }
    else
    {
        set<char> S;
        set<char> aaa;
        for (auto v : t)
            S.insert(v);
        for (auto v : s)
        {
            if (S.find(v) == S.end())
            {
                cout << "0\n";
                return;
            }
            aaa.insert(v);
        }
        cout << 10 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
