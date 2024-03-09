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
vector<ll> G(2000 + 10, 0);
ll n;
int Get(int R)
{
    ll sum = 0;
    int ans = R;
    for (int i = 1; i <= R; ++i)
    {
        sum += G[i];
    }
    ll tmp = 0;
    int L = R + 1;
    for (int i = L; i <= n; ++i)
    {
        tmp += G[i];
        if (tmp == sum)
        {
            ans = max(ans, i - L + 1);
            L = i + 1;
            tmp = 0;
        }
        else if (tmp > sum)
        {
            return 1e8;
        }
    }
    if (tmp != 0)
        return 1e8;
    return ans;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> G[i];
    int ans = 1e8;
    for (int i = 1; i <= n; ++i)
    {
        ans = min(ans, Get(i));
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