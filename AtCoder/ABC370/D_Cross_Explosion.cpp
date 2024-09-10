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
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> g(h + 1, vector<bool>(w + 1, 1));
    vector<set<int>> H(h + 1);
    vector<set<int>> W(w + 1);
    for (int i = 1; i <= h; ++i)
    {
        H[i].insert(0);
        for (int j = 1; j <= w; ++j)
        {
            H[i].insert(j);
        }
        H[i].insert(w + 1);
    }
    for (int i = 1; i <= w; ++i)
    {
        W[i].insert(0);
        for (int j = 1; j <= h; ++j)
        {
            W[i].insert(j);
        }
        W[i].insert(h + 1);
    }
    int x, y;
    int ans = h * w;
    while (q--)
    {
        cin >> x >> y;
        if (g[x][y] == 1)
        {
            g[x][y] = 0;
            H[x].erase(y);
            W[y].erase(x);
            ans--;
        }
        else
        {
            auto D = W[y].upper_bound(x);
            auto U = (prev(D));
            auto R = H[x].upper_bound(y);
            auto L = (prev(R));
            if (*D != h + 1)
            {
                g[*D][y] = 0;
                H[*D].erase(y);
                W[y].erase(D);
                ans--;
            }
            if (*U != 0)
            {
                g[*U][y] = 0;
                H[*U].erase(y);
                W[y].erase(U);
                ans--;
            }

            if (*R != w + 1)
            {
                g[x][*R] = 0;
                W[*R].erase(x);
                H[x].erase(R);
                ans--;
            }
            if (*L != 0)
            {
                g[x][*L] = 0;
                W[*L].erase(x);
                H[x].erase(L);
                ans--;
            }
        }
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
