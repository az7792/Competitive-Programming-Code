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
    int n, m;
    cin >> n >> m;
    vector<char> S(n, '*');
    string str;
    cin >> str;
    vector<int> a(n);
    vector<vector<int>> G(m + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        G[a[i]].eb(i);
    }
    for (int i = 1; i <= m; ++i)
    {
        S[G[i][0]] = str[G[i].back()];
        for (int j = 1; j < G[i].size(); ++j)
        {
            S[G[i][j]] = str[G[i][j - 1]];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (S[i] == '*')
            cout << str[i];
        else
            cout << S[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}