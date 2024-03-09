#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int num[4][4];
bool f[4][4];
vector<pii> G;
double ans = 0;

int TMP = 0;
void dfs(int x, int y)
{
    if (G.size() == 9)
    {
        vector<int> p;
        for (int i = 1; i <= 3; ++i)
        {
            p.clear();
            for (int j = 1; j <= 3; ++j)
            {
                for (int k = 0; k < 9; ++k)
                    if (G[k].first == i && G[k].second == j)
                    {
                        p.push_back(k);
                        break;
                    }
            }
            sort(all(p));
            if (num[G[p[0]].first][G[p[0]].second] == num[G[p[1]].first][G[p[1]].second] && num[G[p[0]].first][G[p[0]].second] != num[G[p[2]].first][G[p[2]].second])
            {
                ans++;
                return;
            }
        }

        for (int i = 1; i <= 3; ++i)
        {
            p.clear();
            for (int j = 1; j <= 3; ++j)
            {
                for (int k = 0; k < 9; ++k)
                    if (G[k].first == j && G[k].second == i)
                    {
                        p.push_back(k);
                        break;
                    }
            }
            sort(all(p));
            if (num[G[p[0]].first][G[p[0]].second] == num[G[p[1]].first][G[p[1]].second] && num[G[p[0]].first][G[p[0]].second] != num[G[p[2]].first][G[p[2]].second])
            {
                ans++;
                return;
            }
        }
        p.clear();
        for (int j = 1; j <= 3; ++j)
        {
            for (int k = 0; k < 9; ++k)
                if (G[k].first == j && G[k].second == j)
                {
                    p.push_back(k);
                    break;
                }
        }
        sort(all(p));
        if (num[G[p[0]].first][G[p[0]].second] == num[G[p[1]].first][G[p[1]].second] && num[G[p[0]].first][G[p[0]].second] != num[G[p[2]].first][G[p[2]].second])
        {
            ans++;
            return;
        }
        p.clear();
        vector<pii> ttt;
        ttt.push_back({1, 3});
        ttt.push_back({3, 1});
        ttt.push_back({2, 2});
        for (int j = 0; j <= 2; ++j)
        {
            for (int k = 0; k < 9; ++k)
                if (G[k].first == ttt[j].first && G[k].second == ttt[j].second)
                {
                    p.push_back(k);
                    break;
                }
        }
        sort(all(p));
        if (num[G[p[0]].first][G[p[0]].second] == num[G[p[1]].first][G[p[1]].second] && num[G[p[0]].first][G[p[0]].second] != num[G[p[2]].first][G[p[2]].second])
        {
            ans++;
            return;
        }
        return;
    }
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
        {
            if (f[i][j] == false)
            {
                f[i][j] = true;
                G.push_back({i, j});
                dfs(i, j);
                f[i][j] = false;
                G.pop_back();
            }
        }
}
void solve()
{

    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            cin >> num[i][j];
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
        {
            for (int _ = 1; _ <= 3; _++)
                for (int __ = 1; __ <= 3; __++)
                    f[_][__] = false;
            f[i][j] = true;
            G.clear();
            G.push_back({i, j});
            dfs(i, j);
        }
    double tmp = 1.0 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9;
    printf("%.10lf", (tmp - ans) / tmp);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}