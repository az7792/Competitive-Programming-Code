#include <bits/stdc++.h>//JI
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<int> a;
map<int, int> mp;
ll Get(int R, int num)
{
    int la = -1;
    for (int i = 0; i <= R; ++i)
    {
        if (a[i] != la + 1 && a[i] != la)
            return (la + 1) * mp[num];
        la = a[i];
    }
    return (la + 1) * mp[num];
}
void solve()
{
    mp.clear();
    a.clear();
    int n;
    cin >> n;
    a.resize(n);
    set<int> S;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        S.insert(a[i]);
        mp[a[i]]++;
    }
    ll ans = 0;
    sort(all(a));
    int R = n - 1;
    while (S.size() > 0)
    {
        ll tmp = 1e18;
        int num = 1e9 + 10;
        ll tmpR = R;
        for (auto v : S)
        {
            int p = upper_bound(all(a), v) - a.begin();
            p--;
            ll tt = Get(R, v);
            if (tt < tmp)
            {
                tmp = tt;
                tmpR = p;
                num = v;
            }
        }
        R = tmpR;
        for (set<int>::iterator it = S.begin(); it != S.end();)
        {
            if (*it >= num)
            {
                set<int>::iterator tttt = it;
                it++;
                S.erase(tttt);
            }
            else
                it++;
        }
        ans += tmp;
    }
    cout << ans << endl;
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