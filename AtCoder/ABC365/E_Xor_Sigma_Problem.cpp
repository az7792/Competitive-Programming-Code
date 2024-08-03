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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<int> one(35, 0);
    vector<int> tmp(n + 1);
    ll ans = -a[1];
    for (int i = 1; i <= n; ++i)
    {
        tmp[i] = ((tmp[i - 1] ^ a[i]));
        ans += tmp[i];
    }
    for (int i = 2; i <= n; ++i)
    {
        bitset<35> tt(tmp[i]);
        for (int j = 0; j < 35; ++j)
        {
            if (tt[j] == 1)
                one[j]++;
        }
    }
    int to = n - 1;
    for (int i = 2; i <= n; ++i)
    {
        // i-1 -- i
        bitset<35> la(tmp[i] ^ tmp[i - 2]);
        for (int j = 0; j < 35; ++j)
        {
            if (la[j] == 1)
                one[j]--;
        }
        to--;
        ll sum = 0;
        bitset<35> tt(a[i - 1]);
        for (int j = 0; j < 35; ++j)
        {
            if (tt[j] == 1)
                one[j] = to - one[j];
            sum += (1ll << j) * one[j];
        }
        ans += sum;
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
