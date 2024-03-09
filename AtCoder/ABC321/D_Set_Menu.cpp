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

int main()
{
    ll N, M, P;
    cin >> N >> M >> P;
    vector<ll> A(N);
    vector<ll> B(M);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<ll> sum(M + 1, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }
    sort(all(B));
    for (int i = 1; i <= M; ++i)
    {
        sum[i] += sum[i - 1] + B[i - 1];
    }
    ll res = 0;
    for (int i = 0; i < N; ++i)
    {
        int p = lower_bound(all(B), P - A[i]) - B.begin();
        res += (M - p) * P;
        res += sum[p] + A[i] * p;
    }
    cout << res;
    return 0;
}
