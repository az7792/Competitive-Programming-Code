#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool nisp[MAX];
void init(int n)
{
    vector<int> isp;
    for (int i = 2; i <= n; ++i)
    {
        if (!nisp[i])
            isp.push_back(i);
        for (int j = 0; j < isp.size() && isp[j] * i <= n; ++j)
        {
            nisp[isp[j] * i] = true;
            if (isp[j] % i == 0)
                break;
        }
    }
}
string Str = "abcdefghijklmnopqrstuvwxyz";
void solve()
{
    int n;
    cin >> n;
    if (!nisp[n])
    {
        for (int i = 0, p = 0; i < n; ++i, p = (p + 1) % 2)
            cout << Str[p];
    }
    else
    {
        int S = 1;
        while (n % S == 0)
        {
            S++;
        }
        for (int i = 0, p = 0; i < n; ++i, p = (p + 1) % S)
            cout << Str[p];
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    init(MAX);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}