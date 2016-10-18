
#ifndef PA1_H

#include "iostream"
#include "vector"
#include "ctime"
#include "chrono"
#include "fstream"

using namespace std;//humans are lazy creatures

class VectorManager
{

public://public function
	  
	void genRandomNumsInVector(vector<int> &mainVector, int sizeOfVector)  //gen random number in vector
	{
		//local vector to check make sure numbers don't get repeated
		vector<int> local;
		//init srand
		srand((unsigned)time(NULL));
		//gen numbs  
		for (int i = 0; i < sizeOfVector; i++)
		{//gen random nums
			int genedNum = rand() % 2147483647; //gen number
												//do a simple check make sure num issn't repeated
			if (!findNuminVector(local, genedNum))
			{
				mainVector.push_back(genedNum);//push on main vector
				local.push_back(genedNum);//push it on local vector
			}
			else//else decreament counter
				i--;
		}
	}

	int findNuminVector(vector<int> &mainVector, int findNum)//find an num in vector for testing
	{
		for (unsigned int counter = 0; counter < mainVector.size(); counter++)
		{
			if (mainVector[counter] == findNum)
				return 1;
		}
		return 0;
	}

	void createVectorSizeOfNback(vector<int> &mainVector, int makeSize)//create a vecotr backwards with set size
	{
		for (int counter = makeSize; counter > 0; counter--)
			mainVector.push_back(counter);
	}

	void createVectorSizeOfNOrdered(vector<int> &mainVector, int makeSize) //create a vector straight
	{
		for (int counter = 0; counter > makeSize; counter++)
			mainVector.push_back(counter);
	}

	//print vector
	void printVector(vector<int> &mainVector) //mostly for testing
	{
		for (unsigned int counter = 0; counter < mainVector.size(); counter++)
			cout << mainVector[counter] << endl;
	}

};
#endif