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
struct Node
{
    int t, x;
    char c;
};

void solve()
{
    int n, q, t, x;
    char c;
    string str;
    cin >> n >> str >> q;
    str = "*" + str;
    int End = 0;
    vector<Node> PP(q + 1);
    for (int i = 1; i <= q; ++i)
    {
        cin >> PP[i].t >> PP[i].x >> PP[i].c;
        if (PP[i].t != 1)
            End = i;
    }
    for (int i = 1; i < End; ++i)
    {
        if (PP[i].t == 1)
            str[PP[i].x] = PP[i].c;
    }
    if (PP[End].t == 2)
    {
        for (int i = 1; i <= n; ++i)
            if (str[i] <= 'Z' && str[i] >= 'A')
                str[i] += 32;
    }
    else if(PP[End].t==3)
    {
        for (int i = 1; i <= n; ++i)
            if (str[i] <= 'z' && str[i] >= 'a')
                str[i] -= 32;
    }
    for (int i = End + 1; i <= q;++i)
    {
        str[PP[i].x] = PP[i].c;
    }
    for (int i = 1; i <= n;++i)
        cout << str[i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}