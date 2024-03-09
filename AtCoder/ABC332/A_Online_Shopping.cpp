#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, s, k;
    cin >> n >> s >> k;
    ll sum = 0;
    for (int i = 0; i < n;++i)
    {
        ll a, b;
        cin >> a >> b;
        sum += a * b;
    }
    if(sum>=s)
    {
        cout << sum;
    }
    else
        cout << sum + k;
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
