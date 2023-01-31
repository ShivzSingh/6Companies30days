class Solution {
public:
    int Neighbour(int i , int j , int m , int n , vector<vector<int>> &curr){
        int liveNeighbours = 0;
        //check for upper neighbour
        if(i > 0){
            if(curr[i-1][j] == 1 || curr[i-1][j] == 3){
                liveNeighbours ++;
            }
        }
        //check for lower neighbour
        if(i < m-1){
            if(curr[i+1][j] == 1 || curr[i+1][j] == 3){
                liveNeighbours ++;
            }
        }
        //check for left neighbour
        if(j > 0){
            if(curr[i][j-1] == 1 || curr[i][j-1] == 3){
                liveNeighbours ++;
            }
        }
        //check for right neighbour
        if(j < n-1){
            if(curr[i][j+1] == 1 || curr[i][j+1] == 3){
                liveNeighbours ++;
            }
        }
        //check for diagonal neighbours
        if(i > 0 && j > 0){
            if(curr[i-1][j-1] == 1 || curr[i-1][j-1] == 3){
                liveNeighbours ++;
            }
        }
        if(i > 0 && j < n-1){
            if(curr[i-1][j+1] == 1 || curr[i-1][j+1] == 3){
                liveNeighbours ++;
            }
        }
        if(i < m-1  && j > 0){
            if(curr[i+1][j-1] == 1 || curr[i+1][j-1] == 3){
                liveNeighbours ++;
            }
        }
        if(i < m-1  && j < n-1){
            if(curr[i+1][j+1] == 1 || curr[i+1][j+1] == 3){
                liveNeighbours ++;
            }
        }
        return liveNeighbours;
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        //vector<vector<int>> curr = board;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int ln = Neighbour(i , j , m , n , board);
                //check for dead cells
                if(board[i][j] == 0){
                    if(ln == 3){
                        board[i][j] = 2; // newly alive
                    }
                }
                //check for live cells
                else if(board[i][j] == 1){
                    if(ln < 2 || ln > 3){
                        board[i][j] = 3; // newly dead
                    }
                }
            }
        }
        //final modifications 2->1, 3->0
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 2){
                    board[i][j] = 1;
                }
                else if(board[i][j] == 3){
                    board[i][j] = 0;
                }
            }
        }
        
    }
};