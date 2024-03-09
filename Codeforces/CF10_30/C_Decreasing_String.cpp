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
    string str;
    cin >> str;
    int n = str.size();
    ll pos, p;
    set<pair<int, char>> S;
    vector<char> ans;
    vector<ll> a(n);
    a[0] = n;
    for (int i = 1; i < n; ++i)
        a[i] = n - i + a[i - 1];
    cin >> p;
    pos = lower_bound(all(a), p) - a.begin();
    for (int i = 0; i < n; ++i)
        S.insert({i, str[i]});
    set<pair<int, char>>::iterator it = S.begin(), tmp;
    for (int i = 1; i <= pos; ++i)
    {
        while (1)
        {
            if (it == prev(S.end()))
            {
                it--;
                S.erase(prev(S.end()));
                ans.pop_back();
                break;
            }
            else if ((*it).second > (*next(it)).second)
            {
                tmp = it;
                if (it == S.begin())
                    it++;
                else
                {
                    it--;
                    ans.pop_back();
                }
                S.erase(tmp);
                break;
            }
            else
            {
                ans.push_back((*it).second);
                it++;
            }
        }
    }
    for (; it != S.end(); ++it)
        ans.push_back((*it).second);
    cout << ans[p - (a[pos] - (n - pos) + 1)];
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