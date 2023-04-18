#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <climits>
typedef long long int ll;
using namespace std;


ll line_cost(ll number_of_spaces, ll number_of_words)
{
    if (number_of_spaces == 0 && number_of_words == 1) {return 0;}
    ll top = number_of_words - 1;
    if (top <= 0) {top = 1;}
    ll ans = 0;
    ll a = top;
    ll b;
    for(ll x = 0; x < top; x++)
    {
        b = number_of_spaces / a;
        ans += (b - 1) * (b - 1);
        number_of_spaces -= b;
        a = a - 1;
    }

    return ans;
}


void solveWordWrap(ll arr[], ll n, ll k)
{
    ll currlen;
    ll cost;
    ll dp[n+1];

    dp[n] = 0;
    dp[n - 1] = line_cost(k - arr[n - 1], 1);
 
    for (ll i = n - 2; i >= 0; i--) {
        currlen = 0;
        dp[i] = LLONG_MAX;
 
        for (ll j = i; j < n; j++) {
 
            currlen += arr[j];
 
            if (currlen > k)
                break;

            cost = dp[j + 1] + line_cost(k - currlen, j - i + 1);

            if (cost < dp[i]) {
                dp[i] = cost;
            }
        }
    }
 
    cout << dp[0] << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll L, N, R;
    cin >> L >> N >> R;    
    
    ll lengths[N];

    string word;
    for(ll i = 0; i < N; ++i)
    {
        cin >> word;
        lengths[i] = word.length();
    }

    solveWordWrap(lengths, N, R);
    
    return 0;
}