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
    vector<int> num(3);
    int c;
    cin >> num[1] >> num[2] >> c;
    for (int i = 1; i <= c + 10; ++i)
    {
        int tmp = num[i] * num[i + 1];
        string str = to_string(tmp);
        for (auto v : str)
            num.push_back(v - '0');
    }
    for (int i = 1; i < c; ++i)
        cout << num[i] << " ";
    cout << num[c];
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
