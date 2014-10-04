#include <iostream>
#include <vector>
using namespace std;

class Solution {
	bool isValidInput(vector<vector<int>> &matrix,int &rows,int &cols)
	{
		rows = matrix.size();
		if (rows <= 0)
			return false;
		cols = matrix[0].size();
		if (cols <= 0)
			return false;
		return true;
	}
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int rows = 0,cols = 0;
		if (!isValidInput(matrix,rows,cols))
			return;

		bool shouldFirstRowSetToZero = false, shouldFirstColSetToZero = false;

		for (int i = 0; i < cols;i++)
			if (matrix[0][i] == 0)
				shouldFirstRowSetToZero = true;

		for (int i = 0; i < rows;i++)
			if (matrix[i][0] == 0)
				shouldFirstColSetToZero = true;


		for (int i = 1;i < rows;i++)
		{
			for (int j = 1;j < cols;j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for (int i = 1; i < rows;i++)
		{
			for (int j = 1;j < cols;j++)
			{
				if (matrix[0][j] == 0 || matrix[i][0] == 0)
					matrix[i][j] = 0;
			}
		}

		if (shouldFirstRowSetToZero)
			for (int i = 0;i < cols;i++)
				matrix[0][i] = 0;


		if (shouldFirstColSetToZero)
			for (int i = 0;i < rows;i++)
				matrix[i][0] = 0;
	}
};


int main(int argc,char *agrv[])
{
	return 0;
}