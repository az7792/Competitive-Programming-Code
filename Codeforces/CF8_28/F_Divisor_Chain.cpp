#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll lowbit(ll x)
{
    return x & (-x);
}
void solve()
{
    ll x;
    cin >> x;
    vector<ll> ans;
    ans.push_back(x);
    while (lowbit(x) != x)
    {
        x -= lowbit(x);
        ans.push_back(x);
    }
    while (x != 1)
    {
        x -= (x >> 1);
        ans.push_back(x);
    }
    cout << ans.size() << endl;
    for (auto v : ans)
        cout << v << ' ';
    cout << endl;
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