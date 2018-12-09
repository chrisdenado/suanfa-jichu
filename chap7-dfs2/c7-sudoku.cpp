#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
//POJ2982, sudoku(数独)
int rowFlag[9][10], colFlag[9][10], blockFlag[9][10];
struct point
{
    int row, col;
    point() {}
    point(int r, int c):row(r), col(c) {}
};

int getBlockNumber(int i, int j)
{
    int temp = i/3;
    temp = temp*3 + j/3;
    return temp;
}

void setFlags(int i, int j, int num, int stat)
{
    rowFlag[i][num] = stat;
    colFlag[j][num] = stat;
    blockFlag[getBlockNumber(i,j)][num] = stat;
}

bool dfs(int id, vector<point> &pointSet, vector<vector<int>> &sudoku)
{
    if(id < 0) return true;
    for(int i=1; i<=9; i++)
    {
        int m=pointSet[id].row, n=pointSet[id].col;
        if( !rowFlag[m][i] && !colFlag[n][i] && !blockFlag[getBlockNumber(m,n)][i] )
        {
            setFlags(m, n, i, 1);
            sudoku[m][n] = i;
            if( dfs(id-1, pointSet, sudoku) ) return true;
            setFlags(m, n, i, 0);
            sudoku[m][n] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    while (n-- > 0) {
        memset(rowFlag, 0, sizeof(rowFlag));
        memset(colFlag, 0, sizeof(colFlag));
        memset(blockFlag, 0, sizeof(blockFlag));
        vector<point> pointSet;
        vector<vector<int>> sudoku(9, vector<int>(9,0));
        string str;
        for(int i=0; i<9; i++)
        {
            cin>>str;
            for(int j=0; j<9; j++)
            {
                int temp = str[j] - '0';
                if( temp > 0 )
                {
                    setFlags(i, j, temp, 1);
                    sudoku[i][j] = temp;
                }
                else pointSet.push_back(point(i,j));
            }
        }
        if( dfs(pointSet.size()-1, pointSet, sudoku) )
        {
            for(int i=0; i<9; i++)
            {
                for(int j=0; j<9; j++)
                {
                    cout<<sudoku[i][j];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
