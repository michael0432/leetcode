// #include <iostream>
// #include <vector>

// class Solution {
// public:
//     bool canReorderDoubled(vector<int>& A) {
//         vector<int> positive_v;
//         vector<int> negative_v;
//         for(int i=0 ; i<A.size() ; i++){
//             if(A[i] < 0) negative_v.push_back(A[i]);
//             else positive_v.push_back(A[i]);
//         }
//         sort(positive_v.begin(), positive_v.end());
//         sort(negative_v.begin(), negative_v.end());
//         if(positive_v.size() % 2 != 0 || negative_v.size() % 2 != 0) return false;
//         for(int i=0 ; i<positive_v.size() ; i+=2){
//             bool find = false;
//             for(int j=i+1 ; j<positive_v.size() ; j+= 2){
//                 if(positive_v[i] * 2 == positive_v[i+1]){
//                     find = true;
//                     break;
//                 }
//             }
//             if(find == false) return false;
//         }
//         for(int i=0 ; i<negative_v.size() ; i+=2){
//             bool find = false;
//             for(int j=i+1 ; j<negative_v.size() ; j+= 2){
//                 if(negative_v[i] * 2 == negative_v[i+1]){
//                     find = true;
//                     break;
//                 }
//             }
//             if(find == false) return false;
//         }
//         return true;
//     }
// };