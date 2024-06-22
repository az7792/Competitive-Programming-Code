#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<ll> ans(MAX, 0);
ll Find(int n)
{
    ll tmp = 1e9;
    for (int i = sqrt(n); i >= 1; --i)
    {
        tmp = min(tmp, 1 + ans[n - i * i]);
    }
    return tmp;
}
void solve()
{
    for (int i = 1; i <= 100000; ++i)
    {
        ans[i] = Find(i);
    }
    int n;
    ll sum = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        sum *= ans[i];
        sum %= MOD;
    }
    cout << sum;
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
