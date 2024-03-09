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
    vector<char> ch;
    for (auto v : str)
    {
        if (v == 'C' && ch.size() >= 2)
        {
            if (ch[ch.size() - 1] == 'B' && ch[ch.size() - 2] == 'A')
            {
                ch.pop_back();
                ch.pop_back();
            }
            else
                ch.push_back(v);
        }
        else
            ch.push_back(v);
    }
    for(auto v:ch)
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