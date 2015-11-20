class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = -1, blue = nums.size();
        int i = 0;
        while(i<blue){
            while(i<blue && nums[i]==2){
                blue -= 1;
                swap(nums[i], nums[blue]);
            }
            if(i<blue && nums[i]==0){
                red += 1;
                swap(nums[i], nums[red]);
            }
            i++;
        }
    }
};
//2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = -1, blue = nums.size(), i = 0;
        while(i<blue){
            if(nums[i]==2){
                swap(nums[i], nums[--blue]);
            }
            else if(nums[i]==0){
                swap(nums[i], nums[++red]);
                i += 1;
            }
            else
                i+=1;
        }
    }
};
