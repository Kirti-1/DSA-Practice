/*  ----------------- LONGEST COMMON PREFIX ---------------- 

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
*/

#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    string longestCommonPrefix(string str, string lcs){
        int llcs = lcs.length();
        int lstr = str.length();
        int size = llcs;
        //To minimize the traversing length as short as possible 
        if(llcs > lstr){
            size = lstr;
        }else if(llcs <lstr){
            size = llcs;
        }else{
            //In case they both have equal length then starting from the mid point and finding minimum possible length for traversal to minimize the time
            int mid = size/2;
            while(mid>0 && lcs[mid]!=str[mid]){
                mid = mid - 1;
            }
            while(mid<size && lcs[mid]==str[mid]){
                mid = mid + 1;
            }
            size = mid;
        }
        int j=0;
        for(;j<size;j++){
            if(str[j]!=lcs[j]){
                break;
            }
        }
        lcs = lcs.substr(0,j);
        return lcs;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string lcs = "";
        if(strs.size() > 0){
            lcs = strs[0];
            for(int i=1;i<strs.size();i++){
                if(strs[i] == lcs){
                    continue;
                }else if(lcs == ""){
                    break;
                }else{
                    lcs = longestCommonPrefix(strs[i],lcs);
                }
            }
        }
        return lcs;
    }
};