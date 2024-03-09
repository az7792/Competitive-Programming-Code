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
    vector<int> a(n + 1, 0);
    vector<int> num(100010, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        num[a[i]]++;
    }
    ll sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        num[a[i]]--;
        sum += (n - i - num[a[i]]);
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
