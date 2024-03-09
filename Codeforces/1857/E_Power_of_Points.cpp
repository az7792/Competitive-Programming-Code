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
    set<ll> S;
    vector<ll> X(n + 10, 0);
    vector<ll> x;
    vector<ll> L(n + 10, 0);
    vector<ll> R(n + 10, 0);
    map<ll, ll> mp;
    map<ll, ll> LL;
    map<ll, ll> RR;
    for (int i = 1; i <= n; ++i)
        cin >> X[i], S.emplace(X[i]), mp[X[i]]++;
    x.emplace_back(0);
    for (auto v : S)
        x.eb(v);
    int ct = 0;
    for (int i = 1; i < x.size() - 1; ++i)
    {
        ct += mp[x[i]];
        L[i] = L[i - 1] + (x[i + 1] - x[i]) * ct;
        LL[x[i]] = L[i];
    }
    ct = 0;
    for (int i = x.size() - 1; i > 1; --i)
    {
        ct += mp[x[i]];
        R[i] = R[i + 1] + (x[i] - x[i - 1]) * ct;
        RR[x[i]] = R[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (X[i] == x[1])
        {
            ll RRR = *(S.lower_bound(X[i] + 1));
            cout << RR[RRR] + n << ' ';
        }
        else if (X[i] == x.back())
        {
            ll LLL = *(--S.lower_bound(X[i]));
            cout << LL[LLL] + n << ' ';
        }
        else
        {
            // X[i];
            ll LLL = *(--S.lower_bound(X[i]));
            ll RRR = *(S.lower_bound(X[i] + 1));
            cout << LL[LLL] + RR[RRR] + n << ' ';
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