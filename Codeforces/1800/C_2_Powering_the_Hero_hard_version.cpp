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
    vector<ll> s(n);
    multiset<ll> p;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        if (s[i] == 0 && !p.empty())
        {
            ans += *p.rbegin();
            p.erase(--p.end());
        }
        if(s[i]!=0)
            p.emplace(s[i]);
    }
    cout << ans << endl;
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