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
vector<int> G(MAX, 0);
void add(int p)
{
    if (G[p] != 9)
        G[p]++;
    else
    {
        G[p] = 0;
        add(p - 1);
    }
}
void solve()
{
    string str;
    cin >> str;
    int n = str.size(),p=n+1;
    for (int i = 0; i < str.size(); ++i)
        G[i+1] = str[i] - '0';
    G[0] = 0;
    for (int i = n; i >= 1; --i)
    {
        if (G[i] >= 5)
        {
            p = i;
            add(i - 1);
            G[i] = 0;
        }        
    }
    if(G[0]!=0)
        cout << G[0];
    for (int i = 1; i < p;++i)
        cout << G[i];
    for (int i = p; i <= n;++i)
        cout << 0;
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