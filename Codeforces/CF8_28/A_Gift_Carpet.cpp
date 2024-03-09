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
string str = "akiv";
void solve() // vika
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mp(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mp[i][j];
    int ok = 0;
    for (int j = m - 1; j >= 0; --j)
    {
        for (int i = 0; i < n;++i)
        {
            if(mp[i][j]==str[ok])
            {
                ok++;
                break;
            }
        }
        if(ok==4)
            break;
    }
    cout << (ok >= 4 ? "YES" : "NO") << endl;
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