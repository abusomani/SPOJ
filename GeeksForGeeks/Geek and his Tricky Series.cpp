//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
// 8 directions
const ll rows[] = {1, -1, 0, 0, 1, -1, 1, -1};
const ll cols[] = {0, 0, 1, -1, 1, -1, -1, 1};
vector<ll> Ans;

void preprocess()
{
    Ans.push_back(7);
    for (int i = 1; i <= 127; i++)
        Ans.push_back(((Ans[i-1] % MOD * (ll)2) % MOD + i) % MOD);
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    preprocess();
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, K, x;
        cin >> N;
        cout << Ans[N - 1] << endl;
    }
    return 0;
}
// END OF SOURCE CODE