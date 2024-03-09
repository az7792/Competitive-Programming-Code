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
string ans[2] = {"NO", "YES"};
void solve()
{
    int n, m;
    cin >> n >> m;
    set<string> s[2];
    vector<string> s3;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        s[0].insert(str);
    }
    for (int i = 0; i < m; ++i)
    {
        string str;
        cin >> str;
        s[1].insert(str);
        if (s[0].find(str) != s[0].end())
            s3.push_back(str);
    }
    bool f = 0;
    while (true)
    {
        if (!s3.empty())
        {
            s[0].erase(s3.back());
            s[1].erase(s3.back());
            s3.pop_back();
        }
        else
        {
            if (s[f].empty())
            {
                cout << ans[f];
                return;
            }
            else
                s[f].erase(s[f].begin());
        }
        f = f ^ 1;
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