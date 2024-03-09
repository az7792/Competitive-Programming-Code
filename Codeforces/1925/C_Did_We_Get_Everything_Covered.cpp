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
    vector<char> ans;
    set<char> S;
    string str;
    int n, k, m;
    cin >> n >> k >> m;
    cin >> str;
    for (auto v : str)
    {
        S.insert(v);
    }
    int ct = S.size();
    if (ct != k)
    {
        cout << "NO\n";
        for (int i = 0; i < k; ++i)
        {
            if (S.find(i + 'a') == S.end())
            {
                for (int j = 0; j < n; ++j)
                    cout << (char)(i + 'a');
                cout << endl;
                return;
            }
        }
    }
    set<char> tmp;
    for (int i = 0; i < str.size(); ++i)
    {
        if (tmp.find(str[i]) == tmp.end())
        {
            tmp.insert(str[i]);
            if (tmp.size() == ct)
            {
                ans.push_back(str[i]);
                tmp.clear();
            }
        }
    }
    if (ans.size() >= n)
        cout << "YES\n";
    else
    {
        cout << "NO\n";
        for (auto v : ans)
            cout << v;
        for (int i = 0; i < k; ++i)
        {
            if (tmp.find(i + 'a') == tmp.end())
            {
                for (int j = 0; j < n - ans.size(); ++j)
                    cout << (char)(i + 'a');
                cout << endl;
                return;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
