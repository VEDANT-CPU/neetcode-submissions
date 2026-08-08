class Solution {
public:
    vector<vector<int>>res;
    vector<int> subList;
    const int MOD = 1000000007;
    
    void dfs(int index,int target,vector<int>& nums) {
        if(index >= nums.size() || target<=0) {
            if(target==0) res.push_back(subList);
            return;
        }
        //decision to choose the current element;
        subList.push_back(nums[index]);
        dfs(index,target-nums[index],nums);

        //decision to not include
        subList.pop_back();
        dfs(index+1,target,nums);
    }
    long long modPow(long long a, long long e) {
        long long res = 1;
        while (e > 0) {
            if (e & 1) res = res * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return res;
    }
    int climbStairs(int n) {
        vector<int> nums = {1,2};
        int ans = 0;
        dfs(0,n,nums);
        vector<long long> fact(n+1), infact(n+1);
        fact[0]=1;
        for(int i=1; i<=n; i++) {
            //fact[i] = i * (fact[i-1] % MOD);
            fact[i] = fact[i-1] * i % MOD;
        }
        infact[n] = modPow(fact[n],MOD-2);
        for(int i=n; i>=1; i--) {
            //infact[i-1] = (infact[i]%MOD) * i;
            infact[i-1] = infact[i] * i % MOD;
        }
        auto C = [&](int N, int R) -> long long {
                if (R < 0 || R > N) return 0;
                return fact[N] * infact[R] % MOD * infact[N - R] % MOD;
        };
        for(int j=0; j<res.size(); j++) {
            int num = res[j].size();
            int num_one=0;
            for(int i=0; i<res[j].size(); i++) {
                if(res[j][i]==1) num_one++;
            }
            ans += C(num,num_one);
        }
        return ans;
    }
};
