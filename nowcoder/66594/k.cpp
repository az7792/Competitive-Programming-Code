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
ll n;
vector<int> G;
ll ans = 0;
void dfs(int p)
{
    if (G.size() == n)
    {
        ll tmp = 0;
        int guai = 1, at = 1, nowat = 1, nowguai = 1;
        for (auto v : G)
        {
            if (v == 1)
            {
                nowguai -= nowat;
                nowat = at;
                if (nowguai <= 0)
                {
                    tmp++;
                    nowguai = guai * 2;
                    guai *= 2;
                }
            }
            else if (v == 2)
            {
                at *= 2;
                nowat *= 2;
            }
            else
            {
                nowat *= 8;
            }
        }
        ans = max(ans, tmp);
        return;
    }
    G.push_back(1);
    dfs(p + 1);
    G.pop_back();

    G.push_back(2);
    dfs(p + 1);
    G.pop_back();

    G.push_back(3);
    dfs(p + 1);
    G.pop_back();
}
void solve()
{
    // ans = 0;
    // G.clear();
    // cin >> n;
    // dfs(1);
    // cout << ans << endl;
    cin >> n;
    cout << (n + 1) / 2 << endl;
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