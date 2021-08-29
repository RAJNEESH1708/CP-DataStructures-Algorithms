
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& 
        queries) {
        vector<int> prefixXor(arr.size()+1,0),result;
       //Create Prefix Xors as mentioned above. 
        for(int i=0;i<arr.size();i++)      
            prefixXor[i+1]=prefixXor[i]^arr[i];
     //Add result to the query according to the above observation.   
        for(vector<int> &v:queries)
           result.push_back(prefixXor[v[1]+1]^prefixXor[v[0]]);  
        return result;
    }
};
