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
map<char, int> mp;
void solve()
{
    ll n, k;
    cin >> n >> k;
    set<ll> s;
    while (k >= 1)
    {
        s.insert(k);
        k = (k + 1) / 2;
        k--;
    }
    if (s.find(n) != s.end())
        cout << "Bob\n";
    else
        cout << "Alice\n";
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
