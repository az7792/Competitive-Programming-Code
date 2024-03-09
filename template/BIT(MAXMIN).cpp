#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e0 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<int> num(MAX, 0); // i点的值
vector<int> Max(MAX, 0); // i点维护区间的最值
int N = 8;
int lowbit(int x)
{
    return x & (-x);
}
int q(int l, int r) // max[l,r]
{
    int res = 0;
    while (r >= l)
    {
        if (r - lowbit(r) + 1 >= l)
        {
            res = max(res, Max[r]);
            r -= lowbit(r);
        }
        else
        {
            res = max(res, num[r]);
            r--;
        }
    }
    return res;
}
void add(int p, int x) // updata( num[p] -> x)
{
    num[p] = x;
    // 更新当前结点维护的区间
    Max[p] = x;
    for (int j = 1; j < lowbit(p); j <<= 1)
        Max[p] = max(Max[p], Max[p - j]);
    // 用当前结点去更新包含当前结点的区间
    int tmp = p;
    p += lowbit(p);
    for (; p <= N; p += lowbit(p))
    {
        Max[p] = max(Max[p], Max[tmp]);
    }
}
int main()
{
    for (int t = 1; t <= 8; ++t)
    {
        num[t] = t;
        add(t, t);
    }
    num[4] = 3;
    add(4, 3);
    cout << q(1, 4);
}