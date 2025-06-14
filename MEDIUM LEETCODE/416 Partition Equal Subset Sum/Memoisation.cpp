class Solution {
public:
    void Solve(vector<int>&nums,int batch1,int batch2,int idx,bool&flag,vector<vector<int>>&memo,int&offset)
    {
        if(batch1-batch2==0)
        {
            flag=true;
            return;
        }
        if(nums.size()<0 || idx<0 ||flag)
        {
            return;
        }
        int diff = batch1-batch2;
        if(offset+diff >= memo[0].size() || offset+diff<0)return;
        if(memo[idx][offset + diff]!=-1)
        {
            if(memo[idx][offset + diff]==1) flag=1;
            return;
        }
        int sum1=batch1;
        int sum2=batch2;
        int sum3=batch1;
        int sum4=batch2;
        sum1-=nums[idx];
        sum2+=nums[idx];
        Solve(nums,sum1,sum2,idx-1,flag,memo,offset);
        Solve(nums,sum3,sum4,idx-1,flag,memo,offset);
        if(flag==1)memo[idx][offset + diff] = 1;
        else memo[idx][offset + diff] = 0;
        return;
    }
    bool canPartition(vector<int>& nums) 
    {
        int sum=0;
        int sum_2=0;
        for(auto element : nums)
        {
           sum+=element;
        }
        int offset = sum;
        vector<vector<int>>memo(nums.size()+1,vector<int>(2*sum+1,-1));
        int idx = nums.size()-1;
        bool flag=false;
        Solve(nums,sum,sum_2,idx,flag,memo,offset);
        if(flag) return true;
        else return false;
    }
};