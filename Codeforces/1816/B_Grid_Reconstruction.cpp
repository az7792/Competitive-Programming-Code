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
ll num[3][MAX];
void solve()
{
    ll n;
    cin >> n;
    num[1][1] = 2 * n;
    num[2][n] = 2 * n - 1;
    ll L = 1, R = n + 1;
    for (int i = 2; i <= n; ++i)
    {
        if (i % 2 == 0) // min
        {
            num[1][i] = L++;
            num[2][i - 1] = L++;
        }
        else // max
        {
            num[1][i] = R++;
            num[2][i - 1] = R++;
        }
    }
    for (int i = 1; i <= 2; ++i)
        for (int j = 1; j <= n; ++j)
            cout << num[i][j] << " \n"[j == n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}