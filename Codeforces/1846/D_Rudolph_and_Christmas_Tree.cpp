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
double y[MAX];
void solve()
{
    int n;
    double d, h,ans=0;
    cin >> n >> d >> h;
    ans += d * h / 2.0;
    cin >> y[1];
    for (int i = 2; i <= n;++i)
    {
        cin >> y[i];
        ans += d * h / 2.0;
        if(y[i]<y[i-1]+h)            
        {
            double H = y[i - 1] + h - y[i];
            double D = d*H/h;
            ans -= D * H / 2.0;
        }
    }
    //cout << ans<<endl;
    printf("%.7lf\n", ans);
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}