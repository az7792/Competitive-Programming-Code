#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<char, pii> mp;
void solve()
{
    ll x, y, n;
    cin >> x >> y >> n;
    string s;
    cin >> s;
    if (x == y && x == 0)
    {
        cout << "Yes\n";
        return;
    }
    int len = s.size();
    vector<pll> f(len);
    ll sx = 0, sy = 0;
    for (int i = 0; i < len; ++i)
    {
        sx += mp[s[i]].first;
        sy += mp[s[i]].second;
        f[i] = pll(sx, sy);
    }
    n--;
    for (int i = 0; i < len; ++i)
    {
        ll tx = x - f[i].first;
        ll ty = y - f[i].second;
        ll nx = f.back().first;
        ll ny = f.back().second;
        if (nx == 0 && ny == 0)
        {
            if (tx == 0 && ty == 0)
            {
                cout << "Yes\n";
                return;
            }
        }
        else if (nx == 0)
        {
            if (ty % ny == 0 && ty / ny <= n && ty / ny >= 0 && tx == 0)
            {
                cout << "Yes\n";
                return;
            }
        }
        else if (ny == 0)
        {
            if (tx % nx == 0 && tx / nx <= n && tx / nx >= 0 && ty == 0)
            {
                cout << "Yes\n";
                return;
            }
        }
        else
        {
            if (tx % nx == 0 && ty % ny == 0 && ty / ny == tx / nx)
            {
                if (tx / nx <= n && tx / nx >= 0)
                {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    mp['U'] = {0, 1};
    mp['D'] = {0, -1};
    mp['L'] = {-1, 0};
    mp['R'] = {1, 0};
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}