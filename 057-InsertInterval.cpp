/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    int bst(vector<Interval> &intervals, Interval newInterval, int begin, int end){
        if(begin>end)
            return begin;
        int mid = (begin+end)>>1;
        if(newInterval.start==intervals[mid].start)
            return mid;
        else if(newInterval.start<intervals[mid].start)
            return bst(intervals, newInterval, begin, mid-1);
        else
            return bst(intervals, newInterval, mid+1, end);
    }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int pos = bst(intervals, newInterval, 0, intervals.size()-1);
        int st = newInterval.start;
        int ed = newInterval.end;
        //look forward
        if(pos>0 && st<=intervals[pos-1].end){
            st = intervals[pos-1].start;
            ed = max(ed, intervals[pos-1].end);
            intervals.erase(intervals.begin()+pos-1);
            pos -= 1;
        }
        //look afterward
        int i = pos;
        while(i<intervals.size() && intervals[i].start<=ed){
            i++;
        }
        if(i!=pos){
            ed = max(ed, intervals[i-1].end);
            intervals.erase(intervals.begin()+pos, intervals.begin()+i);
        }
        intervals.insert(intervals.begin()+pos, Interval(st, ed));
        return intervals;
    }
};
