#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    ll n;
    cin >> n;
    cout << 0 << " ";
    n--;
    ll ct = 1;
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
            cout << ct << " ";
        else
        {
            cout << -ct << " ";
            ct++;
        }
    }
    cout << endl;
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
