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
    vector<int> a(n);
    int b = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b ^= a[i];
    }
    if (n % 2 != 0)
    {
        cout << b << endl;
    }
    else
    {
        if (b == 0)
            cout << 0 << endl;
        else
            cout << -1 << endl;
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