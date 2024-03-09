#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
set<ll> S;
vector<ll> ans;
void init()
{
    S.insert(1);
    for (ll k = 2; k <= 1e6; ++k)
    {
        ll tmp = k * k;
        while (tmp <= 1e12)
        {
            S.insert(tmp);
            tmp *= k;
        }
    }
    for (auto &v : S)
        ans.push_back(v);
}
void solve()
{
    ll n;
    cin >> n;
    int p = upper_bound(all(ans), n) - ans.begin();
    cout << p << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
