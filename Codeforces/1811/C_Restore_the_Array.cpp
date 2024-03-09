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
    int n;
    cin >> n;
    vector<ll> b(n + 10, 0);
    for (int i = 1; i < n; ++i)
        cin >> b[i];
    cout << b[1] << " ";
    for (int i = 1; i < n - 1; ++i)
        cout << min(b[i], b[i + 1]) << ' ';
    cout << b[n - 1] << '\n';
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