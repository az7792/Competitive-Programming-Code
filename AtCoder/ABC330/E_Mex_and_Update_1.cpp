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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    set<int> S;
    for (int i = 0; i <= 1e6; ++i)
        S.insert(i);
    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], mp[a[i]]++, S.erase(a[i]);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (mp[a[x]] == 1)
            S.insert(a[x]);
        mp[a[x]]--;
        a[x] = y;
        S.erase(y);
        cout << (*S.begin()) << endl;
        mp[y]++;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
