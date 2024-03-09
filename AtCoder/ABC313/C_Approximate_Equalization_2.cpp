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
vector<int> G[100];
void solve()
{
    ll n, sum = 0,ans=0;
    cin >> n;
    vector<ll> G(n + 10, 0);
    for (int i = 1; i <= n; ++i)
        cin >> G[i], sum += G[i];
    sort(G.begin ()+ 1, G.begin() + 1 + n);
    for (ll i = 1; i <= n; i++)
        ans += i <= n - sum % n ? abs(sum / n - G[i]) : abs((sum / n + 1) - G[i]);
    cout << ans / 2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}