#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    int ct = 0;
    int x, y, r;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y >> r;
        if (abs(x) <= 50 && abs(y) <= 50)
            ct++;
    }
    if (ct >= n - ct)
        cout << "buaa-noob\n";
    else
        cout << "bit-noob";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
