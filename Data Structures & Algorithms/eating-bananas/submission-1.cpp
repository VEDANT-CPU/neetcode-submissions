class Solution {
public:
    int finishpile(vector<int>& piles, int k) {
        int time=0;
        for(int i=0; i<piles.size(); i++) {
            time += ceil(piles[i]/(double)k);
        }
        return time;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int k;
        int time=0;
        
        int i=1;
        int j= *max_element(piles.begin(), piles.end());
        int mid;
        while(i <= j) {
            mid = (i+j)/2;
            if(finishpile(piles, mid) > h) {
                i = mid+1;
            }else if(finishpile(piles, mid) <= h) {
                j = mid-1;
                k = mid;
            }
        }
        return k;
    }
};
