//Sayeed Gulmahamad
#include<iostream>
#include<cstdlib>
using namespace std;

	const int rows = 5;
	const int cols = 6;
	int weight[rows][cols]={
			{3,4,1,2,8,6},
			{6,1,8,2,7,4},
			{5,9,3,9,9,5},
			{8,4,1,3,2,6},
			{3,7,2,8,6,4}};
	int memo [rows][cols]={0};
	
	
	int cost(int i, int j){ // i is the row, j is the column
		int left, up, down, min;

	//base case
		if(j==0)
			return weight[i][0];
	
	// recursive call
		/**
		left = weight[i][j] + cost(i,j-1); 
 		up = weight[i][j] + cost(i-1>=0?i-1:rows-1,j-1); 
 		down = weight[i][j] + cost(i+1<=rows-1?i+1:0,j-1);
 		**/
 		
 		if( memo[ i][j-1] != 0){
			left = weight[i][j] + memo[ i][j-1];
		}
		else left = weight[i][j] + cost( i, j-1);
		
		if( memo[i-1>=0?i-1:rows-1][j-1] != 0){
			up = weight[i][j] + memo[i-1>=0?i-1:rows-1][j-1];
		}
		else up = weight[i][j] + cost( i-1>=0?i-1:rows-1, j-1);

		if( memo[i+1<=rows-1?i+1:0][j-1] !=0 ){
			down = weight[i][j] + memo[i+1<=rows-1?i+1:0][j-1];
		}
		else down = weight[i][j] + cost( i+1<=rows-1?i+1:0, j-1);
	
	// find the value of the shortest path through cell (i,j)
		if( down < left && down < up) min = down;
		else if( up < left && up < down ) min = up;
		else min = left;
		
		memo[i][j] = min;


		return min;
	}
	
	int main(){
		//for( int r=0; r < rows; r++)
		//	memo [r][0] =weight[r][0];
		
		int ex[rows];
		int mini; 
	
	// get the shortest path out of each cell on the right
		for( int i=0; i<rows; i++)
			ex[i]=cost(i,cols-1);
			
			//for debugging
		for( int i =0; i< rows; i++){
			cout<< ex[i]<< " " ;
		}
		cout<< endl;
	
	// now find the smallest of them
		mini = ex[0];
		for( int r = 1; r < rows; r++) 
			if( ex[r]<mini) 
				mini = ex[r];

		cout<<"The shortest path is of length "<<mini<<endl;
		system("PAUSE");
		return EXIT_SUCCESS;
}
	/**	
		int weight[rows][cols]={
			{3,4,1,2,8,6},
			{6,1,8,2,7,4},
			{5,9,3,9,9,5},
			{8,4,1,3,2,6},
			{3,7,2,8,6,4}};
			
			
		
	**/

