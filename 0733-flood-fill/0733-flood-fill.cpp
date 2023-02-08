class Solution {
public:
    void(dfs(int i , int j , vector<vector<int>> &vis , vector<vector<int>>& image , int n , int m , int oldcolor,int color)){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return;
        }
        if(vis[i][j] || image[i][j] != oldcolor){
            return;
        }
        vis[i][j] = 1;
        image[i][j] = color;
        dfs(i+1,j,vis,image,n,m,oldcolor,color);
        dfs(i-1,j,vis,image,n,m,oldcolor,color);
        dfs(i,j+1,vis,image,n,m,oldcolor,color);
        dfs(i,j-1,vis,image,n,m,oldcolor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x = image.size();
        int y = image[0].size();
        vector<vector<int>> vis(x,vector<int> (y,0));
        int oldcolor = image[sr][sc];
        dfs(sr,sc,vis,image,x,y,oldcolor,color);
        return image;
    }
};