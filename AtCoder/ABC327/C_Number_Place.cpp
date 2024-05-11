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
    vector<int> ans;
    for (int i = 1; i <= 9; ++i)
        ans.push_back(i);
    vector g(9, vector<int>(9, 0));
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            cin >> g[i][j];
    for (int i = 0; i < 9; ++i)
    {
        vector<int> row(9), col(9);
        for (int j = 0; j < 9; ++j)
            row[j] = g[i][j], col[j] = g[j][i];
        sort(all(row)), sort(all(col));
        if (row != ans || col != ans)
        {
            cout << "No";
            return;
        }
    }
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            vector<int> tmp;
            for (int x = i; x < i + 3; ++x)
                for (int y = j; y < j + 3; ++y)
                    tmp.push_back(g[x][y]);
            sort(all(tmp));
            if (tmp != ans)
            {
                cout << "No";
                return;
            }
        }
    }
    cout << "Yes";
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
