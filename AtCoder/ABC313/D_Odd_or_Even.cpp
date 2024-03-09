// 未完成

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
vector<int> G(1010, 0);
void solve()
{
    int n, k;
    cin >> n >> k;
    int op;
    if (k == 1)
    {

        vector<int> ans;
        for (int i = 1; i <= n; ++i)
        {
            cout << "? " << i << endl;
            cout.flush();
            cin >> op;
            ans.eb(op);
        }
        cout << "! ";
        for (auto v : ans)
            cout << v << ' ';
        return;
    }
    G[1] = 1;
    int p;
    cout << "? ";
    for (int i = 1; i <= k; ++i)
        cout << i << " \n"[i == k];
    cout.flush();
    cin >> p;
    for (int i = k + 1; i <= n; ++i)
    {
        cout << "? ";
        for (int j = 2; j <= k; ++j)
            cout << j << ' ';
        cout << i << endl;
        cout.flush();
        cin >> op;
        if (op == G[1])
            G[i] = 1;
        else
            G[i] = 0;
    }
    for (int i = 2; i <= k; ++i)
    {
        cout << "? ";
        for (int j = 1; j <= k; ++j)
            if (j != i)
                cout << j << ' ';
        cout << G[n] << endl;
        cout.flush();
        cin >> op;
        if (op == G[n])
            G[i] = G[n];
        else
            G[i] = (G[n] + 1) % 2;
    }
    int sum = 0;
    for (int i = 1; i <= k; ++i)
        sum += G[i];
    if (sum % 2 == p)
    {
        cout << "! ";
        for (int i = 1; i <= n; ++i)
            cout << G[i] << " \n"[i == n];
    }
    else
    {
        cout << "! ";
        for (int i = 1; i <= n; ++i)
            cout << (G[i] + 1) % 2 << " \n"[i == n];
    }
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