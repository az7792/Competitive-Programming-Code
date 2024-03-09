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
    ll n;
    cin >> n;
    vector<ll> num(n + 10, 0);
    for (int i = 1; i <= n; ++i)
    {
        ll x;
        cin >> x;
        num[max(0ll, i - x)]++;
        num[i]--;
        num[i + 1]++;
        num[min(n + 1, i + x + 1)]--;
    }
    int ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        num[i] += num[i - 1];
        if (num[i] != 0)
            ct++;
    }
    cout << ct;
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