#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve() 
{
    int n;
    cin>>n;
    vector<int> num(n);
    for (int i = 0; i < n;++i)
        cin >> num[i];
    vector<int> ans;
    ans.push_back(num[0]);
    for (int i = 1; i < n;++i)
    {
        if(num[i-1]>num[i])        
            ans.push_back(1);
        ans.push_back(num[i]);
    }
    cout << ans.size() << endl;
    for(auto v:ans)
        cout << v<<' ';
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}