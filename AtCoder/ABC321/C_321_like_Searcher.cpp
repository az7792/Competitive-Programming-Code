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
    ll k;
    cin >> k;
    vector<ll> ans(11, 0);
    set<ll> S;
    int now = 0;
    for (int i = 1; i <= k; ++i)
    {
        int p = 0;
        while (1)
        {
            if (p == now)
            {
                if (ans[p] + 1 == 10)
                {
                    ans[p] = p;
                    ans[p + 1] = p + 1;
                    now++;
                    break;
                }
                else
                {
                    ans[p]++;
                    break;
                }
            }
            else
            {
                if (ans[p] + 1 < ans[p + 1])
                {
                    ans[p]++;
                    break;
                }
                else
                {
                    ans[p] = p;
                    p++;
                }
            }
        }
    }
    for (int i = now; i >= 0; --i)
        cout << ans[i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}