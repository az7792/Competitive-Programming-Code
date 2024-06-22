#include <bits/stdc++.h> //26/30
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n, m, num;
    cin >> n;
    string str;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num;
        str.push_back(num);
    }
    cin >> m;
    vector<pii> ans(m);
    for (int i = 0; i < m; ++i)
    {
        string tmpstr;
        ans[i].second = i + 1;
        int k;
        cin >> k;
        while (k--)
        {
            cin >> num;
            tmpstr.push_back(num);
        }
        ans[i].first = str.find(tmpstr);
    }
    sort(all(ans));
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i].second;
        if (i != ans.size() - 1)
            cout << " ";
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
