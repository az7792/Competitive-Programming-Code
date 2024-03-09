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
    ll a, b, n;
    cin >> a >> b >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
        x[i] = min(a - 1, x[i]);
    }
    sort(all(x));
    ll t = b;
    for (auto v : x)
    {
        if (b + v <= a)        
            b += v;        
        else        
            b = a;        
        t += v;
        b--;
        if (b == 0)
            break;
    }
    cout << t << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}