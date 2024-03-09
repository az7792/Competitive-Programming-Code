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
    int n, m;
    cin >> n >> m;
    vector<string> S(n);
    map<int, vector<int>> mpL, mpU;
    bool f = true;
    for (int i = 0; i < n; ++i)
    {
        cin >> S[i];
        for (int j = 0; j < m; ++j)
            if (S[i][j] == 'L')
                mpL[j].push_back(i);
    }
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (S[i][j] == 'U')
                mpU[i].push_back(j);
        }
    }
    for (auto &[x, y] : mpL)
    {
        if (y.size() % 2 == 1)
        {
            cout << "-1\n";
            return;
        }
        else
        {
            for (int i = 0; i < y.size(); i += 2)
            {
                S[y[i]][x] = 'W';
                S[y[i]][x + 1] = 'B';
                S[y[i + 1]][x] = 'B';
                S[y[i + 1]][x + 1] = 'W';
            }
        }
    }
    for (auto &[x, y] : mpU)
    {
        if (y.size() % 2 == 1)
        {
            cout << "-1\n";
            return;
        }
        else
        {
            for (int i = 0; i < y.size(); i += 2)
            {
                S[x][y[i]] = 'W';
                S[x + 1][y[i]] = 'B';
                S[x][y[i + 1]] = 'B';
                S[x + 1][y[i + 1]] = 'W';
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << S[i] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}