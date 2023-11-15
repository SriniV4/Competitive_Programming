#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef __int128 lll;
#define PI 3.14159265358979323846
#define sbits(x) __builtin_popcount(x)
#define tbits(total_size , num) total_size - __builtin_clz(num)
#define pb push_back
#define f first
#define s second
#define clr(ds) ds.clear()
#define all(ds) ds.begin() , ds.end()
#define pi pair<ll , ll>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define sz(i) (int)i.size()
int xP[] = {0,0,1,-1,1,1,-1,-1} , yP[] = {1,-1,0,0,1,-1,-1,1};
using namespace std;
uint64_t time() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
bool ckmin(auto& a , auto b){if(a<=b)return 0; else {a=b;return 1;}}
bool ckmax(auto& a , auto b){if(a>=b)return 0; else {a=b;return 1;}}
/*
 _______________________________________
( If you don't fail at least 90% of the )
( time, you're not aiming high enough.  )
(                                       )
( - Alan Kay                            )
 ---------------------------------------
        o   ^__^
         o  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
*/

const int MOD = 1e9+7;
const int MAXN = 1e6+1;
int a[MAXN] , b[MAXN];
void solve(){
	ll n , k , l;
	cin >> n >> l >> k ;
	vector<vll> dp(k+1 , vll(n , 0));
	for(int i = 0 ;i<n;i++)cin >> a[i] , b[i] = a[i];
	sort(a , a+n);
	for(int i = 0;i<n;i++)dp[1][i] = i+1;
	ll ans = 0;
	ans = l%MOD;
	for(int i = 2;i<=k;i++){
			for(int j = 0 ;j<n;j++){
				int left = 0, right = n-1 , answer = -1;
				while(left <= right){
					int mid = left + (right-left)/2;
						if(a[mid]<=a[j])answer = mid , left = mid + 1;
						else right = mid - 1;
				}
				dp[i][j] = dp[i-1][answer];
				if(j)dp[i][j] += dp[i][j-1] , dp[i][j]%=MOD;
			}
			ll count = l/n-i+1;
			if(count>=0)ans += count * dp[i][n-1]%MOD , ans%=MOD;
			if(l/n+1>=i){
				for(int j = 0;j<l%n;j++){
					int left = 0, right = n-1 , answer = -1;
					while(left <= right){
						int mid = left + (right-left)/2;
						if(a[mid]<=b[j])answer = mid , left = mid + 1;
						else right = mid - 1;
					}
					ans += dp[i-1][answer] , ans%=MOD;
				}
			}
	}
	cout << ans << "\n";

}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}




