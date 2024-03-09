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
    ll n, p;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 1; --i)
    {
        a[i] = min(a[i], a[i + 1]);
    }
    cin >> p;
    ll ct = p % a[1];
    ll la = p / a[1];
    cout << la << ' ';
    for (int i = 2; i <= n; ++i)
    {
        // a[i] - a[i-1]
        if (a[i] - a[i - 1] == 0)
        {
            cout << la << ' ';
        }
        else
        {
            la = min(la, ct / (a[i] - a[i - 1]));
            ct = ct - la * (a[i] - a[i - 1]);
            cout << la << ' ';
        }
    }
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