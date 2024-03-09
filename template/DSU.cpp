#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define FAST {ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int num[MAX];
int Find(int p)
{
    if (p != num[p])
        num[p] = Find(num[p]);
    return num[p];
}
void init(int n)
{
    for (int i = 1; i <= n; ++i)
        num[i] = i;
}
void Union(int a,int b)
{
    num[Find(a)] = Find(b);
}
void solve()
{
    
}
