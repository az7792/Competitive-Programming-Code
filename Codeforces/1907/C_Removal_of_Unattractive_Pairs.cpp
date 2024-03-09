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
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> a(26, 0);
    for (auto v : str)
        a[v - 'a']++;
    int M = *max_element(all(a));
    if (n - M >= M)
    {
        if (n % 2 == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    else
    {
        cout << n - 2 * (n - M) << endl;
    }
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
