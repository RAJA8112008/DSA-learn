#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        // Step 1: Map Roman characters to integer values
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };

        int result = 0;

        // Step 2: Loop through the string
        for (int i = 0; i < s.length(); i++) {
            int curr = roman[s[i]];
            int next = (i + 1 < s.length()) ? roman[s[i + 1]] : 0;

            // Step 3: Apply rules (subtract if smaller before larger)
            if (curr < next) {
                result -= curr;
            } else {
                result += curr;
            }
        }

        return result;
    }
};
int main(){
    Solution sol;
   string str;
  cout<<"Enter the roman string"<<endl;
   cin>>str;
  int result=sol.romanToInt(str);
  cout<<"Ans is:"<<result<<endl;
}


