#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<vector<vector<ll>>> mp(MAX, vector<vector<ll>>(10, vector<ll>(10, 0)));
void init()
{

    for (int i = 0; i <= 9; ++i)
        mp[0][i][i] = 1;
    for (int i = 1; i <= 2e5; ++i)
    {
        for (int j = 0; j < 9; ++j)
            for (int k = 0; k <= 9; ++k)
                mp[i][j + 1][k] = mp[i - 1][j][k];
        for (int k = 0; k <= 9; ++k)
        {
            mp[i][0][k] = mp[i - 1][9][k];
            mp[i][1][k] += mp[i - 1][9][k];
            mp[i][1][k] %= MOD;
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    string str = to_string(n);
    vector<ll> MP(10, 0);
    for (auto v : str)
        MP[v - '0']++;
    ll ans = 0;
    for (int i = 0; i <= 9; ++i)
        for (int j = 0; j <= 9; ++j)
            ans = (ans + (mp[m][i][j] * MP[j]) % MOD) % MOD;
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    init();
    while (t--)
    {
        solve();
    }
    return 0;
}