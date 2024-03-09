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
    int n, k;
    cin >> n >> k;
    vector<char> ans(n);
    string str;
    cin >> str;
    map<char, vector<int>> mp;
    int ou = 0, ji = 1;
    for (int i = 0; i < n; ++i)
    {
        mp[str[i]].push_back(i);
    }
    if (k % 2 == 0)
    {
        sort(all(str));
        cout << str;
    }
    else
    {
        for (char i = 'a'; i <= 'z'; ++i)
        {
            if (mp.find(i) != mp.end())
            {
                for (auto v : mp[i])
                {
                    if (v % 2 == 1)
                    {
                        ans[ji] = i;
                        ji += 2;
                    }
                    else
                    {
                        ans[ou] = i;
                        ou += 2;
                    }
                }
            }
        }
        for (auto v : ans)
            cout << v;
    }
    cout << endl;
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