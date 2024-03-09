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
vector<ll> G(MAX, 0);
vector<ll> T(MAX, 0);
ll n, k, Max;
bool ok(int p, ll mid)
{
    ll sum = 0;
    for (int i = p; i <= n; ++i)
    {
        if (i == n && mid > G[n])
            return false;
        else if(n==i)
            break;
        if (G[i] >= mid)
            break;
        sum += mid - G[i];
        mid--;
    }
    if (sum <= k)
        return true;
    return false;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> G[i];
    Max = G[n];
    for (int i = 1; i <= n - 1; ++i)
    {
        ll L = G[i], R = 1e9, mid;
        while (L < R)
        {
            mid = (L + R + 1) / 2;
            if (ok(i, mid))
                L = mid;
            else
                R = mid - 1;
        }
        Max = max(Max, L);
    }
    cout << Max << endl;
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