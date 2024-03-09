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
map<int, ll> n2, n5;
pll get(int n)
{
    // if (n2.find(n) != n2.end())
    //     return pll(n2[n], n5[n]);
    int N = n;
    ll t2 = 0, t5 = 0;
    for (int i = 2; i <= 5; ++i)
    {
        while (n % i == 0)
        {
            if (i == 2)
                t2++;
            if (i == 5)
                t5++;
            n /= i;
        }
    }
    // n2[N] = t2;
    // n5[N] = t5;
    return pll(t2, t5);
}
void solve()
{
    int n;
    cin >> n;
    pll n25 = {0, 0}, m25 = {0, 0};
    for (int i = 1; i <= n; ++i)
    {
        // (4*i - 2   / i + 1)^(n-i+1)
        int a = 4 * i - 2;
        int b = i + 1;
        pll t1 = get(a);
        pll t2 = get(b);
        t1.first *= (n - i + 1);
        t1.second *= (n - i + 1);
        t2.first *= (n - i + 1);
        t2.second *= (n - i + 1);
        n25.first += t1.first;
        n25.second += t1.second;
        m25.first += t2.first;
        m25.second += t2.second;
    }
    n25.first -= m25.first;
    n25.second -= m25.second;
    cout << min(n25.first, n25.second);
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