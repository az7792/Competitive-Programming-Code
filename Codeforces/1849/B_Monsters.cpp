#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 3e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<ll, ll> mp;
pll G[MAX];
vector<pll> ans;
vector<pll> ans2;
bool cmp1(pll a, pll b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

void solve()
{
    ans.clear();
    ans2.clear();
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> G[i].first;
        G[i].second = i;
        if (G[i].first % k == 0)
            G[i].first = k;
        else
            G[i].first %= k;
        ans2.eb(G[i]);
    }
    sort(all(ans), cmp1);
    sort(all(ans2), cmp1);
    for (auto v : ans)
        cout << v.second << ' ';
    for (auto v : ans2)
        cout << v.second << ' ';
    cout << endl;
    // cout << "___________________";
    // while (!S.empty())
    // {
    //     sort(all(S), cmp1);
    //     pll tmp = S[0];
    //     S.erase(S.begin());
    //     if(tmp.first<=k)
    //         cout << tmp.second<<' ';
    //     else{
    //         tmp.first -= k;
    //         S.eb(tmp);
    //     }
    // }
    // cout << "\n\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/