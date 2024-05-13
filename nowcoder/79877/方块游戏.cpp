#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 1, 0, -1};
int ty[] = {1, 0, -1, 0};
void solve()
{
    int n, m;
    cin >> n >> m;
    ll A = 0, B = 0, C = 0;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        A += count(all(str), '1');
        B += count(all(str), '2');
        C += count(all(str), '3');
    }
    ll x, y, z;
    y = C - B;
    x = ((A + 3 * B - 2 * C) / 3 + (A - B)) / 2;
    z = x - (A - B);
    cout << x << ' ' << y << " " << z;
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
