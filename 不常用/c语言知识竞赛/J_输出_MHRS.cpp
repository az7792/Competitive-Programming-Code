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
vector<char> a(4);
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> num(4, 0);
    for (auto v : str)
    {
        if (v == 'M' || v == 'm')
            num[0]++;
        else if (v == 'H' || v == 'h')
            num[1]++;
        else if (v == 'R' || v == 'r')
            num[2]++;
        else if (v == 'S' || v == 's')
            num[3]++;
    }
    int Max = max({num[0], num[1], num[2], num[3]});
    for (int i = 1; i <= Max; i++)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (num[j] >= 1)
            {
                cout << a[j];
                num[j]--;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    a[0] = 'M';
    a[1] = 'H';
    a[2] = 'R';
    a[3] = 'S';
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
