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
ll sum[1000];
void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;
    if (n - 1 < k - 1)
    {
        cout << -1 << endl;
        return;
    }
    if (x < k - 1)
    {
        cout << -1 << endl;
        return;
    }
    if(x==k)
        x = k - 1;
    cout << sum[k - 1] + x * (n - k) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    sum[0] = 0;
    for (int i = 1; i <= 900; ++i)
    {
        sum[i] = sum[i - 1] + i;
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}