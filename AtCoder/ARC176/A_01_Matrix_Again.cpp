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
    vector<pii> di(m);
    set<int> dx, dy;
    for (int i = 0; i < m; ++i)
    {
        cin >> di[i].first >> di[i].second;
        dx.insert(di[i].first);
        dy.insert(di[i].second);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (dx.size() >= m)
            break;
        if (dx.find(i) == dx.end())
            dx.insert(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (dy.size() >= m)
            break;
        if (dy.find(i) == dy.end())
            dy.insert(i);
    }
    vector<int> DX, DY;
    for (auto v : dy)
        DY.push_back(v);
    for (auto v : dx)
        DX.push_back(v);

    vector<pii> ans;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            ans.push_back({DX[i], DY[j]});

    vector<set<int>> S(n + 1);
    vector<int> row(n + 1, m), col(n + 1, m);
    for (auto [a, b] : ans)
    {
        S[a].insert(b);
        row[a]--;
        col[b]--;
    }

    priority_queue<pii> Qc;
    for (int i = 1; i <= n; ++i)
        Qc.push({col[i], i});

    for (int i = 1; i <= n; ++i)
    {
        vector<pii> tmp;
        while (row[i] != 0)
        {
            tmp.push_back(Qc.top());
            Qc.pop();
            if (S[i].find(tmp.back().second) != S[i].end())
                continue;
            ans.push_back({i, tmp.back().second});
            S[i].insert(tmp.back().second);
            tmp.back().first--;
            row[i]--;
        }
        for (int j = 0; j < tmp.size(); ++j)
        {
            if (tmp[j].first != 0)
                Qc.push(tmp[j]);
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
