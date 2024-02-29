class Solution {
	private:
		int mp[26];
	public:
		int ind(char x){
			return x-'A';
		}
		bool check(int t){
			if(mp[ind('Q')]>t||mp[ind('W')]>t||mp[ind('E')]>t||mp[ind('R')]>t){
				return false;
			}
			return true;
		}
		int balancedString(string s) {
			for(auto ch:s){
				mp[ind(ch)]++;
			}
			int n=s.length();
			int t=n/4;
			if(check(t)){
				return 0;
			}
			int ans=n;
			for(int l=0,r=0;l<n;l++){
				while(r<n&&!check(t)){
					mp[ind(s[r])]--;
					r++;
				}
				if(!check(t)){
					break;
				}
				ans=min(ans,r-l);
				mp[ind(s[l])]++;
			}
			return ans;
		} 
	};