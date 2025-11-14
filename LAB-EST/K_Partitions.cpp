class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low= *min_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int parti=1, ctr=0, check=0;
            for(auto i: nums){
                if(ctr+i>mid){
                    parti++;
                    check=max(check,ctr);
                    ctr=i;
                }
                else ctr+= i;
            }
            check=max(check,ctr);
            if(parti<=k){ans=min(ans,check);high=mid-1;}
            else low=mid+1;
        }
        return ans;
    }
};
