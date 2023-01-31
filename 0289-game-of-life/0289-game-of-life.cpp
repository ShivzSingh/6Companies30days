class Solution {
public:
    int Neighbour(int i , int j , int m , int n , vector<vector<int>> &curr){
        int liveNeighbours = 0;
        //check for upper neighbour
        if(i > 0){
            if(curr[i-1][j] == 1){
                liveNeighbours ++;
            }
        }
        //check for lower neighbour
        if(i < m-1){
            if(curr[i+1][j] == 1){
                liveNeighbours ++;
            }
        }
        //check for left neighbour
        if(j > 0){
            if(curr[i][j-1] == 1){
                liveNeighbours ++;
            }
        }
        //check for right neighbour
        if(j < n-1){
            if(curr[i][j+1] == 1){
                liveNeighbours ++;
            }
        }
        //check for diagonal neighbours
        if(i > 0 && j > 0){
            if(curr[i-1][j-1] == 1){
                liveNeighbours ++;
            }
        }
        if(i > 0 && j < n-1){
            if(curr[i-1][j+1] == 1){
                liveNeighbours ++;
            }
        }
        if(i < m-1  && j > 0){
            if(curr[i+1][j-1] == 1){
                liveNeighbours ++;
            }
        }
        if(i < m-1  && j < n-1){
            if(curr[i+1][j+1] == 1){
                liveNeighbours ++;
            }
        }
        return liveNeighbours;
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> curr = board;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int ln = Neighbour(i , j , m , n , curr);
                //check for dead cells
                if(board[i][j] == 0){
                    if(ln == 3){
                        board[i][j] = 1;
                    }
                }
                //check for live cells
                else if(board[i][j] == 1){
                    if(ln < 2 || ln > 3){
                        board[i][j] = 0;
                    }
                }
            }
        }
        
    }
};