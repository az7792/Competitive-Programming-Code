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
map<ll, ll> mp;
vector<int> G(MAX, 0);
void solve()
{
    int n, m, q, p;
    cin >> n >> m >> q;
    string op, f;
    map<int, pair<bool,int>> ROW, COL;
    vector<int> ron, roff, con, coff;
    for (int i = 1; i <= q; ++i)
    {
        cin >> op >> p >> f;
        if (op == "row")
        {
            if (f == "on")
            {
                ROW[p].first = true;
                ROW[p].second = i;
            }
            else
            {
                ROW[p].first = false;
                ROW[p].second = i;
            }
        }
        else
        {
            if (f == "on")
            {
                COL[p].first = true;
                COL[p].second = i;
            }
            else
            {
                COL[p].first = false;
                COL[p].second = i;
            }
        }
    }
    for(auto &[x,y]:ROW)
    {
        auto &[a, b] = y;
        if(a==true)
            ron.eb(b);
        else
            roff.eb(b);
    }

    for(auto &[x,y]:COL)
    {
        auto &[a, b] = y;
        if(a==true)
            con.eb(b);
        else
            coff.eb(b);
    }
    sort(all(ron));
    sort(all(roff));
    sort(all(con));
    sort(all(coff));
    ll ans = m * ron.size();
    for(auto v:con)
    {
        ll tans = n - ron.size();
        int p = upper_bound(all(roff),v) - roff.begin();
        tans -= roff.size() - p;
        ans += tans;
    }

    for(auto v:coff)
    {
        int p = upper_bound(all(ron),v) - ron.begin();
        ans -= p;
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/