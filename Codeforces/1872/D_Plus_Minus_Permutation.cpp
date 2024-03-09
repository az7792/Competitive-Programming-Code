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
    ll n, x, y;
    cin >> n >> x >> y;
    ll numx = n / x;
    ll numy = n / y;
    ll Min = lcm(x, y);
    ll numlcm = n / Min;
    numy -= numlcm;
    numx -= numlcm;
    cout << (((n - numx + 1) + n) * numx / 2ll) - ((1 + numy) * numy / 2ll) << endl;
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