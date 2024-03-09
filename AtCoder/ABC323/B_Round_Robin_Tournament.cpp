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
    cin >> n;
    vector<pii> G(n);
    for (int i = 0; i < n; ++i)
        G[i].second = i;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; ++j)
            if (str[j] == 'o')
                G[i].first++;
            else if (str[j] == 'x')
                G[j].first++;
    }
    sort(all(G), [](pii a, pii b)
         {
        if(a.first==b.first)
            return a.second < b.second;
        return a.first > b.first; });
    for(auto v:G)
        cout << v.second + 1 << ' ';
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