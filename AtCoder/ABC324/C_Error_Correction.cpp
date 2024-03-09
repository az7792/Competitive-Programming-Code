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
void solve()
{
    int n;
    string T;
    cin >> n >> T;
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        if (str == T)
        {
            ans.push_back(i + 1);
            continue;
        }
        else if (str.size() < T.size() - 1 || str.size() > T.size() + 1)
            continue;
        else if (str.size() == T.size())
        {
            int ct = 0;
            for (int i = 0; i < str.size(); ++i)
                if (str[i] != T[i])
                    ct++;
            if (ct == 1)
                ans.push_back(i + 1);
        }
        else if (str.size() < T.size())
        {
            int ct = 0;
            for (int i = 0, j = 0; i < T.size(); ++i)
            {
                if (str[j] != T[i])
                    ct++;
                else
                    j++;
            }
            if (ct == 1)
                ans.push_back(i + 1);
        }
        else
        {
            int ct = 0;
            for (int i = 0, j = 0; i < str.size(); ++i)
            {
                if (str[i] != T[j])
                    ct++;
                else
                    j++;
            }
            if (ct == 1)
                ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;
    for (auto v : ans)
        cout << v << " ";
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