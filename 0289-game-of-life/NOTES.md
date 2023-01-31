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
Approach :- 2
Remember our moves (in-place)
we introduce two new states for a cell:
2: newly alive and 3: newly dead
Onto our main function:
Wherever we were modifying the board, now we use our new states, so any cell that we mark as alive will be marked 2, and any cell which we mark as dead, will be marked 3 instead of 1 and 0 respectively. Then after finishing the whole processing (i.e the entire board), we iterate over the matrix again, replacing our new states (2, 3) with their respective values (1, 0).
​
​