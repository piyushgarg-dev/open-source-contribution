#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// an algorithm for finding majority element in an array
// Time complexity: O(n)
// Space complexity: O(1)


int majorityElement(vector<int>& nums) {
    int ct = 0, ret = nums[0];
    for(int e : nums){
        if(e == ret) ct++;
        else if(--ct == 0) ret = e, ct = 1, cout<<e<<" ";
    }
    return ret;
}

  

int main(){

    vector<int> v = {2,2,3,1,1,2,4};
    int n = majorityElement(v);
    cout<<"majority number is (using Boyer-Moore Voting Algorithm) = "<<n;
    return 0;
}
