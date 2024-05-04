#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        p[a[i]] = i;
    }
    multiset<int> s;
    for (int i = 1; i <= k; ++i)
        s.insert(p[i]);
    int ans = *s.rbegin() - *s.begin();
    for (int i = k + 1; i <= n; ++i)
    {
        auto it = s.find(p[i - k]);
        s.erase(it);
        s.insert(p[i]);
        ans = min(ans, *s.rbegin() - *s.begin());
    }

    cout << ans;
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
