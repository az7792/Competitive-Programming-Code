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
int nx[] = {0, 0, -1, 1};
int ny[] = {-1, 1, 0, 0};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> G(n + 1, vector<char>(m + 1, '?'));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> G[i][j];
    int ct = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (G[i][j] == '0')
            {
                int c1 = 0, c2 = 0;
                for (int k = 0; k < 4; ++k)
                {
                    int tx = i + nx[k];
                    int ty = j + ny[k];
                    if (G[tx][ty] == '1')
                        c1++;
                    if (G[tx][ty] == '2')
                        c2++;
                }
                if (c1 == 3 && c2 == 0)
                    ct++;
            }
    if (ct == 0)
        cout << "NO";
    else
        cout << "YES\n"
             << ct;
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