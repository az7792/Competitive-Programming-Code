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
string s;
pii G[MAX];
set<pii> ans;
bool ok(int a, int b)
{
    if (G[a] == G[b])
        return true;
    if (G[a].second + 1 == G[b].first && s[a] == '0' && s[b] == '1')
        return true;
    return false;
}
void solve()
{
    ans.clear();
    int n, m;
    cin >> n >> m;
    cin >> s;
    s = '*' + s + "*";
    G[1].first = 1;
    G[n].second = n;
    for (int i = 2; i <= n; ++i)
    {
        if (s[i] == s[i - 1])
            G[i].first = G[i - 1].first;
        else
            G[i].first = i;
    }
    for (int i = n - 1; i >= 1; --i)
    {
        if (s[i] == s[i + 1])
            G[i].second = G[i + 1].second;
        else
            G[i].second = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (ok(a, b))
        {
            ans.emplace(0, 0);
        }
        else
        {
            pii tmp;
            if (s[a - 1] == '0')
                tmp.first = G[a - 1].first;
            else
                tmp.first = a;
            if (s[b + 1] == '1')
                tmp.second = G[b + 1].second;
            else
                tmp.second = b;
            ans.emplace(tmp);
        }
    }
    cout << ans.size() << endl;
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