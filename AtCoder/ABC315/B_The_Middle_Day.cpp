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
    ll m, sum = 0;
    cin >> m;
    vector<ll> G(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> G[i];
        sum += G[i];
    }
    ll day = (sum + 1) / 2;
    ll tmp = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (tmp + G[i] >= day)
        {
            cout << i << ' ';
            cout << day - tmp;
            return;
        }
        tmp += G[i];
    }
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