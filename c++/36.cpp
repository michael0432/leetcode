#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0 ; i<9 ; i++){
            unordered_map<char,int> m1;
            unordered_map<char,int> m2;
            
            for(int j=0 ; j<9 ; j++){
                if(board[i][j] != '.'){
                    if(m1.count(board[i][j]) == 0){
                        m1[board[i][j]] = 1;
                    }
                    else{
                        return false;
                    }
                }
                if(board[j][i] != '.'){
                    if(m2.count(board[j][i]) == 0){
                        m2[board[j][i]] = 1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        for(int i=0 ; i<=6 ; i+=3){
            for(int j=0 ; j<=6 ; j+=3){
                // cout << i << " " << j << endl;
                bool b = checkbox(board, i, j);
                if(!b) return false;
            }
        }
        return true;
    }
    bool checkbox(vector<vector<char>>& board, int starti, int startj){
        unordered_map<char,int> m;
        for(int i=starti ; i<=starti+2 ; i++){
            for(int j=startj ; j<=startj+2 ; j++){
                if(board[i][j] != '.'){
                    if(m.count(board[i][j]) == 0){
                        m[board[i][j]] = 1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};