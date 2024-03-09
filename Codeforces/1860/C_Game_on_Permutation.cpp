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
    int n;
    cin >> n;
    vector<int> p(n + 1, 0);
    vector<bool> f(n + 1, true);
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    f[1] = false;
    int Min = p[1];
    for (int i = 2; i <= n; ++i)
    {
        if (Min > p[i])
            f[i] = false;
        Min = min(Min, p[i]);
    }
    bool ff = false;
    set<int> S;
    for (int i = 2; i <= n; ++i)
    {
        if (f[i])
        {
            if (S.empty())
            {
                S.emplace(p[i]);
            }
            else
            {
                set<int>::iterator it = S.upper_bound(p[i]);
                if (it == S.begin())
                {
                    S.emplace(p[i]);
                }
                else
                {
                    f[i] = false;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (f[i])
            ans++;
    }
    cout << ans << endl;
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