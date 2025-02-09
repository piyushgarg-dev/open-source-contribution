#include<iostream>
#include <vector>

using namespace std;

// problem = maximum sub array sum
// kadanes algo
// time complexity = O(n)
// space complexity = O(1)
// this algo is used to find the maximum sub array sum in an array
// first we take two variables sum and max_sum
// sum is used to store the sum of the sub array
// max_sum is used to store the maximum sum of the sub array
// we iterate through the array and add the elements to sum
// if the sum becomes negative we make it 0
// if the sum is greater than max_sum we update max_sum
// finally we return max_sum



int main(){

    vector <int> v = {-2, -3 , 4, -1, -2, 1, 5, -3};

    int sum = v[0];
    int max_sum = 0;
   
    for(int i=1;i<v.size();i++){

        if(sum + v[i] > 0){
            sum += v[i];
            if(sum > max_sum){
                max_sum = sum;
            }
        }
        else sum = 0;
    }
    
    

    cout<<max_sum;

}