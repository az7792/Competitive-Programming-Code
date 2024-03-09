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
bool ok(vector<ll> &a)
{
    for (int i = 1; i < a.size(); ++i)
    {
        if (a[i] != a[0])
            return false;
    }
    return true;
}
void solve()
{
    vector<ll> a(3);
    for (int i = 0; i < 3; ++i)
        cin >> a[i];
    sort(all(a));
    if (a[0] == a[1] && a[1] == a[2])
        cout << "YES\n";
    else if (a[0] == a[1] && (a[2] == a[1] * 2 || a[2] == a[1] * 3 || a[2] == a[1] * 4))
        cout << "YES\n";
    else if (a[1] == a[2] && a[2] == a[0] * 2)
        cout << "YES\n";
    else if (2 * a[0] == a[1] && 3 * a[0] == a[2])
        cout << "YES\n";
    else
        cout << "NO\n";
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