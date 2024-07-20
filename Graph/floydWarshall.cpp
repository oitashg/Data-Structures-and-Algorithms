#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//-----------------------Multi source shortest path algorithm---------------------------
//--------------------Applicable to negative edges or negative cycle---------------------
//----------------------------------TC- O(n^3)-------------------------------------------

class Solution {
  public:
    //---------------------------------------------------------------------

	void shortest_distance(vector<vector<int>>&mat){
	    int n = mat.size();
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(mat[i][j] == -1)
	                mat[i][j] = 1e9;
	            else if(i == j) mat[i][j] = 0;
	        }
	    }
	    
	    for(int k=0; k<n; k++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
	            }
	        }
	    }
	    
        //to check if there is negative cycle
        
        // for(int i=0; i<n; i++){
        //     if(mat[i][i] < 0)
        //         //negative cycle exist
        // }


	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(mat[i][j] == 1e9)
	                mat[i][j] = -1;
	        }
	    }
	}

    //-------------------------------------------------------------------
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}