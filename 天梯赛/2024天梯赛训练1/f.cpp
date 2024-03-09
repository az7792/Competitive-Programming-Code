#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n, m;
    cin >> n >> m;
    getchar();
    vector<string> ans;
    for (int i = 1; i <= n; ++i)
    {
        string str;
        getline(cin, str);
        if (str.find("qiandao") != str.npos || str.find("easy") != str.npos)
            ;
        else
            ans.push_back(str);
    }
    if (m >= ans.size())
        cout << "Wo AK le\n";
    else
        cout << ans[m] << "\n";
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
