#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    str = str + "0";
    vector<int> g;
    int ct = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (str[i] == '1')
            ct++;
        else
        {
            g.push_back(ct);
            ct = 0;
        }
    }
    g.push_back(0);
    g.push_back(0);
    sort(all(g), [](int a, int b)
         { return a > b; });
    cout << g[0] + g[1];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}