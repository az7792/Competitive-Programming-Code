#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
struct Math
{
    ll mod;
    vector<bool> nisp; // false 是质数
    vector<int> isp;

    Math(ll MMod)
    {
        mod = MMod;
    }

    ll gcd(ll a, ll b)
    {
        while (b != 0)
        {
            ll temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ll exgcd(ll a, ll b, ll &x, ll &y)
    {
        if (b == 0)
        {
            x = 1, y = 0;
            return a;
        }
        ll res = exgcd(b, a % b, x, y);
        ll t = x;
        x = y;
        y = t - (a / b) * y;
        return res;
    }

    ll lcm(ll a, ll b)
    {
        return (a * b) / gcd(a, b);
    }

    ll POW(ll a, ll b)
    {
        a %= mod;
        if (b == 0)
            return 1;
        if (b % 2 == 0)
            return POW((a * a) % mod, b / 2) % mod;
        else
            return (POW((a * a) % mod, b / 2) % mod * a) % mod;
    }

    void initOula(int n) // 1-n的素数
    {
        nisp.resize(n + 1, 0);
        nisp[0] = nisp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (!nisp[i])
                isp.push_back(i);
            for (int j = 0; j < isp.size() && isp[j] * i <= n; ++j)
            {
                nisp[isp[j] * i] = true;
                if (i % isp[j] == 0)
                    break;
            }
        }
    }

    bool isPrime(int x)
    {
        if (x <= 1)
            return 0;
        for (int i = 2; i <= x / i; ++i)
            if (x % i == 0)
                return 0;
        return 1;
    }
};

int main()
{
    Math m(MOD);
    m.initOula(101);
    for (int i = 0; i <= 101; ++i)
        if (m.isPrime(i))
            cout << i << " ";
}