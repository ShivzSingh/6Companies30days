class Solution {
public:
    bool dfs(int i , int j , int idx , vector<vector<char>>& board, string word , vector<vector<int>> &vis){
        //base case
        if(idx == word.size()){
            return true;
        }
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || vis[i][j] == 1 ||               word[idx] != board[i][j]){
            return false;
        }
        //marking visited
        vis[i][j] = 1;
        //traversing all sides
        bool us = dfs(i-1 , j , idx+1 , board , word , vis); //up
        bool ds = dfs(i+1 , j , idx+1 , board , word , vis); //down
        bool ls = dfs(i , j-1 , idx+1 , board , word , vis); //left
        bool rs = dfs(i , j+1 , idx+1 , board , word , vis); //right
        //Backtracking (If no one is found suitable match)
        vis[i][j] = 0;
        return us | ds | ls | rs;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m , vector<int>(n , 0)); 
        for(int i = 0 ; i < m ; i++){
            for(int j  = 0 ; j < n ; j++){
                if(!vis[i][j] && word[0] == board[i][j]){
                    if(dfs(i , j , 0 , board , word , vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};