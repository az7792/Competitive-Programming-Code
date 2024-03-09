#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, tmp;
    cin >> n;
    map<ll, set<int>> mp;
    vector<pii> ans;
    vector<ll> a(n + 1), b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mp[a[i]].insert(i);
    }
    b = a;
    sort(b.begin() + 1, b.end());
    tmp = b[1] + b[n];
    for (int i = 1; i <= (n + 1) / 2; ++i)
    {
        if (b[i] + b[n + 1 - i] != tmp)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    if (n % 2 == 1)
    {
        if (a[(n + 1) / 2] == tmp / 2)
        {
            mp[tmp / 2].erase((n + 1) / 2);
        }
        else
        {
            ans.push_back({(n + 1) / 2, *mp[tmp / 2].begin()});
            int pp = *mp[tmp / 2].begin();
            mp[tmp / 2].erase(pp);
            mp[a[(n + 1) / 2]].insert(pp);
            mp[a[(n + 1) / 2]].erase((n + 1) / 2);
            swap(a[pp], a[(n + 1) / 2]);
        }
    }
    for (int i = 1; i <= n / 2; ++i)
    {
        mp[a[i]].erase(mp[a[i]].find(i));
        int pp = *prev(mp[tmp - a[i]].end());
        ans.push_back({pp, n - i + 1});
        mp[tmp - a[i]].erase(prev(mp[tmp - a[i]].end()));
        mp[a[n - i + 1]].insert(pp);
        mp[a[n - i + 1]].erase(n - i + 1);
        swap(a[pp], a[n - i + 1]);
    }
    cout << ans.size() << endl;
    for (auto &[x, y] : ans)
        cout << x << " " << y << endl;
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
