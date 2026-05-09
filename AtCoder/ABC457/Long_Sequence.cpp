#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll MOD = 1e9 + 7;
// ll MOD = 998244353;

template <typename T>
std::istream &operator>>(std::istream &_in, std::vector<T> &_a)
{
    for (auto &v : _a)
        _in >> v;
    return _in;
}

template <typename T>
std::ostream &operator<<(std::ostream &_out, std::vector<T> &_a)
{
    if (!_a.empty())
        _out << _a[0];
    for (size_t i = 1; i < _a.size(); ++i)
        _out << " " << _a[i];
    return _out;
}

void solve()
{
    int n;cin>>n;
    ll k;cin>>k;
    vector<vector<int>>a(n+1);
    vector<ll>C(n+1);
    vector<int>L(n+1);
    for(int i=1;i<=n;i++){        
        cin>>L[i];
        a[i].resize(L[i]+1);
        for(int j=1;j<=L[i];j++) cin>> a[i][j];
    }
    for(int i=1;i<=n;i++)cin>>C[i];

    for(int i=1;i<=n;i++){
        ll sum = C[i] * L[i];
        if(sum >= k){
            k %= L[i];
            if(k == 0)
                k = L[i];
            cout << a[i][k] << endl;
            return;
        }else{
            k -= sum;
        }
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