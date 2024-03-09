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
    int n, m, s;
    cin >> n >> m >> s;
    vector<queue<char>> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        string str;
        cin >> str;
        for (auto v : str)
            a[i].push(v);
    }
    vector<char> st;
    vector<char> ans;
    int op;
    while (1)
    {
        cin >> op;
        if (op == -1)
            break;
        if (op == 0)
        {
            if (!st.empty())
            {
                ans.push_back(st.back());
                st.pop_back();
            }
        }
        else
        {
            if (a[op].size() != 0)
            {
                if (st.size() == s)
                {
                    ans.push_back(st.back());
                    st.pop_back();
                }
                st.push_back(a[op].front());
                a[op].pop();
            }
        }
    }

    for (auto v : ans)
        cout << v;
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
