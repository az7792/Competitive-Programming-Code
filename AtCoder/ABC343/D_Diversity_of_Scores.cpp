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
    int n, t;
    cin >> n >> t;
    vector<ll> A(t + 1), B(t + 1), sc(n + 1);
    map<ll, int> mp;
    mp.insert({0, n});
    for (int i = 1; i <= t; ++i)
    {
        cin >> A[i] >> B[i];
        mp[sc[A[i]]]--;
        if (mp[sc[A[i]]] == 0)
            mp.erase(sc[A[i]]);
        sc[A[i]] += B[i];
        mp[sc[A[i]]]++;
        cout << mp.size() << endl;
    }
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
