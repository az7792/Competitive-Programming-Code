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
    ll n, k;
    cin >> n >> k;
    map<ll, set<ll>> mp;
    set<ll> S;
    for (int i = 1; i <= n; ++i)
    {
        ll tmp;
        cin >> tmp;
        S.insert(i);
        mp[tmp].insert(i);
    }
    for (int i = 1; i <= k; ++i)
    {
        if (mp.find(i) == mp.end())
        {
            cout << 0 << " ";
        }
        else
        {
            ll len = *S.rbegin() - *S.begin() + 1;
            cout << len + len << ' ';
            for(auto v:mp[i])
            {
                S.erase(v);
            }
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