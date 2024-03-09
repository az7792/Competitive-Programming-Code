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
ll ans[100];
ll sum[100];
void init()
{
    ll tmp = 1;
    for (ll i = 1; i <= 15; ++i)
    {
        ans[i] = tmp * 10 - tmp;
        sum[i] = sum[i - 1] + ans[i]*i;
        tmp *= 10;
    }
}
void solve()
{
    ll n;
    cin >> n;
    string str = to_string(n);
    int len = str.size();
    ll a = sum[len - 1];
    a += len * (n - pow(10, len - 1) + 1);
    cout << a << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}