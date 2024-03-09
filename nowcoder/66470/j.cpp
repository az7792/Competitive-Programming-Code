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
    int n, m, x;
    int S = 0;
    cin >> n >> m;
    vector<int> A(n + 1, 0), B(n + 1, 0);
    vector<vector<int>> C(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    for (int i = 1; i <= m; ++i)
        cin >> B[i];
    cin >> x;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            C[i][j] = A[i] * B[j] + C[i - 1][j] + C[i][j - 1] - C[i - 1][j - 1];
    for (int ax = 1; ax <= n; ++ax)
        for (int ay = 1; ay <= m; ++ay)
            for (int bx = ax; bx <= n; ++bx)
                for (int by = ay; by <= m; ++by)
                    if (C[bx][by] - C[bx][ay - 1] - C[ax - 1][by] + C[ax - 1][ay - 1] <= x)
                        S = max(S, (bx - ax + 1) * (by - ay + 1));
    cout << S;
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