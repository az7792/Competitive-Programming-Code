#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> G(n + 1, vector<ll>(n + 1, 0));
    vector<bool> row(n + 1, false), col(n + 1, false);
    vector<ll> Mrow(n + 1, 1e9), Mcol(n + 1, 1e9);
    ll sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        bool f = false;
        for (int j = 1; j <= n; ++j)
        {
            cin >> G[i][j];
            Mrow[i] = min(Mrow[i], G[i][j]);
            if (G[i][j] <= 0)
            {
                sum += G[i][j];
                f = true;
            }
            row[i] = f;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        bool f = false;
        for (int j = 1; j <= n; ++j)
        {
            Mcol[i] = min(Mcol[i], G[j][i]);
            if (G[j][i] <= 0)
            {
                f = true;
            }
            col[i] = f;
        }
    }
    ll ansrow = sum, anscol = sum;
    for (int i = 1; i <= n; ++i)
    {
        if(!row[i])
            ansrow += Mrow[i];
        if(!col[i])
            anscol += Mcol[i];
    }
    cout << min(anscol, ansrow) << endl;
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