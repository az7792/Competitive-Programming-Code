#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1, vector<int>(m + 1));
    if (n >= m - 1)
    {
        if (m == 1)
        {
            for (int i = 0; i <= n; ++i)
                cout << "0\n";
        }
        else
        {
            cout << m << endl;
            int st = m - 1;
            for (int i = 0; i < m - 1; ++i)
            {
                for (int j = 0; j < m; ++j)
                    G[i][(st + j) % m] = j;
                st--;
            }
            for (int i = m - 1; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                    G[i][j] = G[i % (m - 1)][j];
            }
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    cout << G[i][j] << " \n"[j == m - 1];
        }
    }
    else
    {
        cout << n + 1 << endl;
        int st = m - 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                G[i][(st + j) % m] = j;
            st--;
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cout << G[i][j] << " \n"[j == m - 1];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
