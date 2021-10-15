Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
  
 
  
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        if(intervals.size()==0){
            return ans;
        }
        
        sort(intervals.begin(),intervals.end());
        
        vector<int> tempinterval = intervals[0];
        
        for(auto it: intervals ){
            if(it[0] <= tempinterval[1]){
                tempinterval[1] = max(it[1], tempinterval[1]);
            }
            else{
                ans.push_back(tempinterval);
                tempinterval = it;
            }
        }
        
        ans.push_back(tempinterval);
        return ans;
    }
};
