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
    vector<int> a(n), b(n);
    int s1, s2;
    s1 = s2 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
        s1 += a[i];
        s2 += b[i];
    }
    if (s1 == s2)
        cout << "Draw";
    else if (s1 < s2)
        cout << "Aoki";
    else
        cout << "Takahashi";
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
