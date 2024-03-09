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
    ll n, k, g, Max, tmp;
    cin >> n >> k >> g;
    Max = (g % 2 == 0) ? g / 2ll - 1ll : g / 2ll;
    if (Max * n >= k * g)
    {
        cout << k * g << endl;
        return;
    }
    tmp = k * g - Max * n;
    tmp %= g;
    if(tmp==0)
    {
        cout << Max * n<<endl;
    }
    else if (Max + tmp >= g)
    {
        cout << Max * (n - 1) + (Max + tmp) % g << endl;
    }
    else
    {
        cout << Max * (n - 1) - (g - Max - tmp)<<endl;
    }
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