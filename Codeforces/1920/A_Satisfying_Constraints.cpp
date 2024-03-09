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
    int n;
    cin >> n;
    vector<ll> no;
    ll l = -1e18, r = 1e18;
    for (int i = 1; i <= n; ++i)
    {
        ll op, x;
        cin >> op >> x;
        if (op == 1)
        {
            l = max(l, x);
        }
        else if (op == 2)
        {
            r = min(r, x);
        }
        else
        {
            no.push_back(x);
        }
    }
    ll ct = 0;
    for (auto v : no)
    {
        if (v <= r && v >= l)
            ct++;
    }
    if (l > r)
        cout << 0 << endl;
    else
        cout << r - l + 1 - ct << endl;
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
