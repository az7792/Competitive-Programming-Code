#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n;
    cin >> n;
    n--;
    int p;
    for (ll i = 1; i; ++i)
    {
        if ((1ll << i) - 1 >= n)
        {
            p = i;
            break;
        }
    }
    cout << p << endl;
    cout.flush();
    vector<vector<int>> ans(p);
    for (int i = 1; i <= n; ++i)
    {
        bitset<30> tmp(i);
        for (int j = 0; j < 30; ++j)
            if (tmp[j] == 1)
                ans[j].push_back(i);
    }
    for (int i = 0; i < p; ++i)
    {
        cout << ans[i].size() << " ";
        for (auto v : ans[i])
            cout << v << " ";
        cout << endl;
        cout.flush();
    }
    string str;
    cin >> str;
    int tt = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '1')
            tt += (1 << i);
    }
    if(tt==0)
        cout << n + 1;
    else
        cout << tt;
    cout.flush();
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
