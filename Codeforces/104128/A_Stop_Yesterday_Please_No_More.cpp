#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
map<char, pii> txy;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> sum(n + 2, vector<int>(m + 2, 0));
    string str;
    cin >> str;
    vector<bool> f(str.size(), 0);
    map<pii, bool> mp;
    int x = 0, y = 0;
    mp[{x, y}] = true;
    for (int i = 0; i < str.size(); ++i)
    {
        char v = str[i];
        x = x + txy[v].first;
        y = y + txy[v].second;
        if (mp.find({x, y}) != mp.end())
            f[i] = true;
        else
            mp[{x, y}] = true;
    }
    pii LU = {1, 1}, RD = {n, m};
    pii lu = {1, 1}, rd = {n, m};
    for (auto v : str)
    {
        if (v == 'U')
        {
            if (lu.first == 1)
                LU.first++;
            else
                lu.first--;
            rd.first--;
        }
        else if (v == 'D')
        {
            if (rd.first == n)
                RD.first--;
            else
                rd.first++;
            lu.first++;
        }
        else if (v == 'R')
        {
            if (rd.second == m)
                RD.second--;
            else
                rd.second++;
            lu.second++;
        }
        else if (v == 'L')
        {
            if (lu.second == 1)
                LU.second++;
            else
                lu.second--;
            rd.second--;
        }
        if (LU.first > RD.first || LU.second > RD.second || lu.first > rd.first || lu.second > rd.second)
        {
            if (k == 0)
                cout << n * m << endl;
            else
                cout << 0 << endl;
            return;
        }
    }
    sum[LU.first][LU.second]++;
    sum[RD.first + 1][LU.second]--;
    sum[LU.first][RD.second + 1]--;
    sum[RD.first + 1][RD.second + 1]++;
    for (int i = 0; i < str.size(); ++i)
    {
        char v = str[i];
        LU.first += txy[v].first;
        LU.second += txy[v].second;
        RD.first += txy[v].first;
        RD.second += txy[v].second;
        if (f[i] == false)
        {
            sum[LU.first][LU.second]++;
            sum[RD.first + 1][LU.second]--;
            sum[LU.first][RD.second + 1]--;
            sum[RD.first + 1][RD.second + 1]++;
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    int ans = 0;
    int SUM = (RD.first - LU.first + 1) * (RD.second - LU.second + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (SUM - sum[i][j] == k)
                ans++;
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    txy['U'] = {-1, 0};
    txy['D'] = {1, 0};
    txy['R'] = {0, 1};
    txy['L'] = {0, -1};
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}