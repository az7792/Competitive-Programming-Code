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
    pair<ll, ll> a, b;
    cin >> a.first >> a.second >> b.first >> b.second;
    if (a.second > b.second)
        swap(a, b);
    ll ans = b.second - a.second;
    if (a.first <= b.first) // to right
    {
        if ((a.first + a.second) % 2 == 0)
        {
            a.first++;
        }
        if ((b.first + b.second) % 2 == 0)
        {
            b.first++;
        }
        a.first += ans;
        if (a.first < b.first)
        {
            ans += (b.first - a.first) / 2;
        }
    }
    else // to left
    {
        if ((a.first + a.second) % 2 != 0)
        {
            a.first--;
        }
        if ((b.first + b.second) % 2 != 0)
        {
            b.first--;
        }
        a.first -= ans;
        if (a.first > b.first)
        {
            ans += (a.first - b.first) / 2;
        }
    }
    cout << ans;
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
