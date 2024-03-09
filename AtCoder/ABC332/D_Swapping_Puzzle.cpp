#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<int> L, R;
vector<int> vL(6, 0), vR(6, 0);
int n, m, ans = 1e9;
vector<vector<int>> a;
vector<vector<int>> b;
int Getnum(vector<int> num)
{
    int ct = 0;
    for (int i = 1; i <= num.size(); ++i)
    {
        for (int j = i - 1; j < num.size(); ++j)
        {
            if (num[j] == i)
            {
                for (int k = j - 1; k >= i - 1; --k)
                {
                    swap(num[k], num[k + 1]);
                    ct++;
                }
                break;
            }
        }
    }
    return ct;
}
void dfs(int p, int t, char op)
{
    if (op == 'L')
    {

        if (p == m)
        {
            for (int i = 1; i <= n; ++i)
            {
                if (vR[i])
                    continue;
                vR[i] = true;
                R.push_back(i);
                dfs(1, i, 'R');
                R.pop_back();
                vR[i] = false;
            }
        }
        else
        {
            for (int i = 1; i <= m; ++i)
            {
                if (vL[i])
                    continue;
                vL[i] = true;
                L.push_back(i);
                dfs(p + 1, i, 'L');
                L.pop_back();
                vL[i] = false;
            }
        }
    }
    else
    {
        if (p == n)
        {
            vector<vector<int>> mp(n + 1, vector<int>(m + 1, 0));
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                    mp[i][j] = a[R[i - 1]][L[j - 1]];
            if (mp != b)
                return;
            vector<int> ttt;
            ttt = L;
            int sum = Getnum(ttt);
            ttt = R;
            sum += Getnum(ttt);
            ans = min(ans, sum);
        }
        else
        {
            for (int i = 1; i <= n; ++i)
            {
                if (vR[i])
                    continue;
                vR[i] = true;
                R.push_back(i);
                dfs(p + 1, i, 'R');
                R.pop_back();
                vR[i] = false;
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    a.resize(n + 1, vector<int>(m + 1, 0));
    b.resize(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> b[i][j];
    for (int i = 1; i <= m; ++i)
    {
        if (vL[i])
            continue;
        vL[i] = true;
        L.push_back(i);
        dfs(1, i, 'L');
        L.pop_back();
        vL[i] = false;
    }
    if (ans == 1e9)
        cout << -1;
    else
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
