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
    int n, m;
    cin >> n >> m;
    vector<int> vis(n);
    vector<pii> ans;
    set<pii> s;
    set<int> ss;
    for (int i = 0, a, b; i < m; ++i)
    {
        cin >> a >> b;
        ans.emplace_back(a, b);
        s.emplace(a, b);
        vis[(a + b) % n] = 1;
        ss.insert((a + b) % n);
    }
    for (int i = 0; i < n; ++i)
    {
        if (ss.size() >= m)
            break;
        if (ss.find(i) == ss.end())
            ss.insert(i);
    }
    for (auto v : ss)
    {
        for (int i = 1; i <= n; ++i)
        {
            int tmp = i < v ? v - i : (n - i + v == 0 ? n : n - i + v);
            if (s.find({tmp, i}) == s.end())
            {
                s.insert({tmp, i});
                ans.push_back({tmp, i});
            }
        }
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans)
        cout << x << " " << y << endl;
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
