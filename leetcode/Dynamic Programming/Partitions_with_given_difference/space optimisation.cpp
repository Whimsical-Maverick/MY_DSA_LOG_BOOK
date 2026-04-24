class Solution {
  public:
    int countPartitions(vector<int>& arr, int d)
    {
        int sum=0;
        int total=0;
        for(auto element : arr)
        {
            total+=element;
        }
        int idx = arr.size()-1;
        vector<int>prev(total+1,0),curr(total+1,0);
        for(int j=0;j<total+1;j++)
        {
            if(2*j - total==d)prev[j]++;
            if(2*(j-arr[0])-total==d)prev[j]++;
        }
        for(int i=1;i<arr.size();i++)
        {
            for(int j=0;j<total+1;j++)
            {
                curr[j] = prev[j];
                if(j-arr[i]>=0)curr[j] += prev[j-arr[i]];
            }
            prev=curr;
        }
        return prev[total];
    }
};