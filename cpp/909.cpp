#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


//comlicated version
//pair<int, int> get_coordi(int i, int n)
//{
//    int y = n - 1 - ((i - 1) / n);
//    int x = ((n-y) % 2 == 1) ? (i - 1) % n : (n - y) * n - i;
//    return {y, x}; 
//}

//simple version
pair<int, int> get_coordi(int i, int n)
{
        int y = (i - 1) / n;
        int x = (i - 1) % n;
        return {y, x};
}

void organize(vector<vector<int>>& board)
{
	reverse(board.begin(), board.end());
        bool isRev = false; //check if the row needs to be reversed
        for (auto &row: board)
        {
            if (isRev) reverse(row.begin(), row.end());
            isRev = !isRev;
        }
        for (auto row: board)
        {
            for (auto s: row)
                cout << s << " ";
            cout << endl;
        }
}


   int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        organize(board);//simple version
        
        //BFS
        int steps = 0;
        vector<char> visited(n*n + 1, 0);
        queue<int> q;
	q.push(1);
	while (!q.empty())
	{
	   int size = q.size();
	   while (size--)
            {
                int cur = q.front();
                q.pop();
                if (cur == n*n) return steps;
                for (int i = cur + 1; i <= min(cur + 6, n*n) ; i++)
                {
                    auto [y, x] = get_coordi(i, n);
                    int next = board[y][x] == -1 ? i : board[y][x];
                    if (!visited[next])
                    {
                        q.push(next);
                        visited[next] = 1;
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }

int main()
{
   vector<vector<int>> board {{-1,-1,19,10,-1},
                              {2, -1,-1,6-1},
                              {-1,17,-1,19,-1},
                              {25, -1,20,-1,-1},
                              {-1,-1,-1,-1,15}};
   cout << snakesAndLadders(board) << endl;
   //cout << "steps = " << snakesAndLadders(board) << endl;

   return 0;
}
