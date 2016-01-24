/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval &i1, Interval &i2){
    return i1.start<i2.start;
};
class quecomp{
public:
    bool operator()(int a, int b){
        return a>b;
    }
};
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<int, vector<int>, quecomp> endTime;
        int room = 0;
        for(int i = 0; i<intervals.size(); i++){
            if(!endTime.empty() && endTime.top()<=intervals[i].start){
                endTime.pop();
            }
            else{
                room++;
            }
            endTime.push(intervals[i].end);
        }
        return room;
    }
};
