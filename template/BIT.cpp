#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
#define fi first
#define se second
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n;      // 数组长度[1,n]
int D[MAX]; // 维护前缀和
int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int v) // 在[x]加上v
{
    while (x <= n)
    {
        D[x] += v;
        x += lowbit(x);
    }
}
int query(int x) // 查询[1,x]的值
{
    int res = 0;
    while (x)
    {
        res += D[x];
        x -= lowbit(x);
    }
    return res;
}