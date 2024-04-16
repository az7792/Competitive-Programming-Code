#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    ll L, R;
    cin >> L >> R;
    vector<pair<ll, ll>> ans;
    while (L < R)
    {
        ll len = 1;
        for (int i = 0; i <= 60; ++i)
        {
            ll tmp = (1ll << i);
            if ((L == 0 ? 1 : tmp <= L) && L + tmp <= R)
            {
                if (L % tmp == 0)
                    len = (1ll << i);
            }
            else
                break;
        }
        ans.push_back({L, L + len});
        L = L + len;
    }
    cout << ans.size() << endl;
    for (auto v : ans)
        cout << v.first << " " << v.second << endl;
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
