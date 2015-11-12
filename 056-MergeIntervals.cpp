/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool comp(Interval &v1, Interval &v2){
     if(v1.start!=v2.start)
        return v1.start<v2.start;
    return v1.end>v2.end;
 }
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.size()==0) return ans;
        sort(intervals.begin(), intervals.end(), comp);
        int st = intervals[0].start;
        int ed = intervals[0].end;
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i].end<=ed)
                continue;
            else if(intervals[i].start>ed){
                ans.push_back(Interval(st, ed));
                st = intervals[i].start;
                ed = intervals[i].end;
            }
            else{
                ed = max(ed, intervals[i].end);
            }
        }
        ans.push_back(Interval(st, ed));
        return ans;
    }
};
