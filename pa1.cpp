/*
Name: vikram singh (11491025)
Assignment: 11491025
*/

//Dependcies
#include "pa1.h"

using namespace std;//humans are lazy creatures

//prototypes
void allRuns(void);
float completeRun(int sizeOfVector);
void doBubbleSort(vector<int> &mainVector);
void intDoubleArray(float array[][16], int yComp, int xComp);
void printDoubleArray(float array[][16], int yComp, int xComp); //for testing

//basic runners for cases
void bestCase(float mainData[][16]);
float bestCaseRunner(int sizeOfVector);
float worstCaseRunner(int sizeOfVector);

//prints to csv
void printToCsv(float mainData[][16]);


int main(int argc, char** argv)
{//starting point of the code
	//main vars
	allRuns();
	return 0;
}

//contains all logic and function calls
void allRuns(void)
{
	//vars
	int ycounter = 0, xcounter = 0;

	//data structure for time y = 9 x = 5(both starts from 0)
	/*y: 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000*/
	// x: run 1, run 2, run 3, run 4, run 5, best1,  best2, best3, best4, best5, worse1, worse2, worse3, worse4, worse5, n
	//      0       1     2       3       4    5     	6    7		8		9		10		11		12		13		14
	float timeForAllRuns[9][16];

	//inti double array to 0
	intDoubleArray(timeForAllRuns, 9, 16);

	cout << "Started Runs: " << endl; //update user

	//do 5 runs fill the double time array
	for (; ycounter < 9; ycounter++)
	{
		for (; xcounter < 5; xcounter++)
		{
			if (ycounter == 0) timeForAllRuns[ycounter][xcounter] = completeRun(10);
			if (ycounter == 1) timeForAllRuns[ycounter][xcounter] = completeRun(50);
			if (ycounter == 2) timeForAllRuns[ycounter][xcounter] = completeRun(100);
			if (ycounter == 3) timeForAllRuns[ycounter][xcounter] = completeRun(500);
			if (ycounter == 4) timeForAllRuns[ycounter][xcounter] = completeRun(1000);
			if (ycounter == 5) timeForAllRuns[ycounter][xcounter] = completeRun(5000);
			if (ycounter == 6) timeForAllRuns[ycounter][xcounter] = completeRun(10000);
			if (ycounter == 7) timeForAllRuns[ycounter][xcounter] = completeRun(50000);
			if (ycounter == 8) timeForAllRuns[ycounter][xcounter] = completeRun(100000);
		}
		cout << "Finished " << ycounter + 1 << " of 9 runs." << endl;//update user
		xcounter = 0;
	}

	cout << "Finished random runs.\nStarting best and worst cases.\n";//update user

	bestCase(timeForAllRuns); //finish worst and best case
	cout << "Finished best and worst. Writing to file.\n";//update user
	printToCsv(timeForAllRuns);//start writing to file
	cout << "Finished writing to file\n";//update user

}

void printToCsv(float mainData[][16])
{
	//create file object and open correct file
	ofstream csvFile;
	csvFile.open("BSStats.csv");

	//format file
	csvFile << "N size, Optimal time, Worst Time, Average Time, Run 1, Run 2, Run 3, Run 4, Run 5\n";

	//write double array to file 
	for (int counter = 0; counter < 9; counter++)
	{
		csvFile << mainData[counter][15] << ", " << (mainData[counter][5] + mainData[counter][6]+ mainData[counter][7]+ mainData[counter][8]+ mainData[counter][9])/5 << ", " << (mainData[counter][10] + mainData[counter][11] + mainData[counter][12] + mainData[counter][13] + mainData[counter][14])/5 << ", " << (mainData[counter][0] + mainData[counter][1] + mainData[counter][2] + mainData[counter][3] + mainData[counter][4]) / 5 << ", "
			<< mainData[counter][0] << ", " << mainData[counter][1] << ", " << mainData[counter][2] << ", " << mainData[counter][3] << ", " << mainData[counter][4] << "\n";
	}

	//close file
	csvFile.close();
}

void bestCase(float mainData[][16])
{
	//just call best case/ worst case for all n values use the counter for which n to use
	// x: run 1, run 2, run 3, run 4, run 5, best1,  best2, best3, best4, best5, worse1, worse2, worse3, worse4, worse5, n
	//      0       1     2       3       4    5     	6    7		8		9		10		11		12		13		14	 15
	for (int xcounter = 0; xcounter < 9; xcounter++)
	{
		if (xcounter == 0)
		{
			mainData[xcounter][5] = bestCaseRunner(10);
			mainData[xcounter][6] = bestCaseRunner(10);
			mainData[xcounter][7] = bestCaseRunner(10);
			mainData[xcounter][8] = bestCaseRunner(10);
			mainData[xcounter][9] = bestCaseRunner(10);
			mainData[xcounter][10] = worstCaseRunner(10);
			mainData[xcounter][11] = worstCaseRunner(10);
			mainData[xcounter][12] = worstCaseRunner(10);
			mainData[xcounter][13] = worstCaseRunner(10);
			mainData[xcounter][14] = worstCaseRunner(10);
			mainData[xcounter][15] = 10;
		}
		if (xcounter == 1)
		{
			mainData[xcounter][5] = bestCaseRunner(50);
			mainData[xcounter][6] = bestCaseRunner(50);
			mainData[xcounter][7] = bestCaseRunner(50);
			mainData[xcounter][8] = bestCaseRunner(50);
			mainData[xcounter][9] = bestCaseRunner(50);
			mainData[xcounter][10] = worstCaseRunner(50);
			mainData[xcounter][11] = worstCaseRunner(50);
			mainData[xcounter][12] = worstCaseRunner(50);
			mainData[xcounter][13] = worstCaseRunner(50);
			mainData[xcounter][14] = worstCaseRunner(50);
			mainData[xcounter][15] = 50;
		}
		if (xcounter == 2)
		{
			mainData[xcounter][5] = bestCaseRunner(100);
			mainData[xcounter][6] = bestCaseRunner(100);
			mainData[xcounter][7] = bestCaseRunner(100);
			mainData[xcounter][8] = bestCaseRunner(100);
			mainData[xcounter][9] = bestCaseRunner(100);
			mainData[xcounter][10] = worstCaseRunner(100);
			mainData[xcounter][11] = worstCaseRunner(100);
			mainData[xcounter][12] = worstCaseRunner(100);
			mainData[xcounter][13] = worstCaseRunner(100);
			mainData[xcounter][14] = worstCaseRunner(100);
			mainData[xcounter][15] = 100;
		}
		if (xcounter == 3)
		{
			mainData[xcounter][5] = bestCaseRunner(500);
			mainData[xcounter][6] = bestCaseRunner(500);
			mainData[xcounter][7] = bestCaseRunner(500);
			mainData[xcounter][8] = bestCaseRunner(500);
			mainData[xcounter][9] = bestCaseRunner(500);
			mainData[xcounter][10] = worstCaseRunner(500);
			mainData[xcounter][11] = worstCaseRunner(500);
			mainData[xcounter][12] = worstCaseRunner(500);
			mainData[xcounter][13] = worstCaseRunner(500);
			mainData[xcounter][14] = worstCaseRunner(500);
			mainData[xcounter][15] = 500;
		}
		if (xcounter == 4)
		{
			mainData[xcounter][5] = bestCaseRunner(1000);
			mainData[xcounter][6] = bestCaseRunner(1000);
			mainData[xcounter][7] = bestCaseRunner(1000);
			mainData[xcounter][8] = bestCaseRunner(1000);
			mainData[xcounter][9] = bestCaseRunner(1000);
			mainData[xcounter][10] = worstCaseRunner(1000);
			mainData[xcounter][11] = worstCaseRunner(1000);
			mainData[xcounter][12] = worstCaseRunner(1000);
			mainData[xcounter][13] = worstCaseRunner(1000);
			mainData[xcounter][14] = worstCaseRunner(1000);
			mainData[xcounter][15] = 1000;
		}
		if (xcounter == 5)
		{
			mainData[xcounter][5] = bestCaseRunner(5000);
			mainData[xcounter][6] = bestCaseRunner(5000);
			mainData[xcounter][7] = bestCaseRunner(5000);
			mainData[xcounter][8] = bestCaseRunner(5000);
			mainData[xcounter][9] = bestCaseRunner(5000);
			mainData[xcounter][10] = worstCaseRunner(5000);
			mainData[xcounter][11] = worstCaseRunner(5000);
			mainData[xcounter][12] = worstCaseRunner(5000);
			mainData[xcounter][13] = worstCaseRunner(5000);
			mainData[xcounter][14] = worstCaseRunner(5000);
			mainData[xcounter][15] = 5000;
		}
		if (xcounter == 6)
		{
			mainData[xcounter][5] = bestCaseRunner(10000);
			mainData[xcounter][6] = bestCaseRunner(10000);
			mainData[xcounter][7] = bestCaseRunner(10000);
			mainData[xcounter][8] = bestCaseRunner(10000);
			mainData[xcounter][9] = bestCaseRunner(10000);
			mainData[xcounter][10] = worstCaseRunner(10000);
			mainData[xcounter][11] = worstCaseRunner(10000);
			mainData[xcounter][12] = worstCaseRunner(10000);
			mainData[xcounter][13] = worstCaseRunner(10000);
			mainData[xcounter][14] = worstCaseRunner(10000);
			mainData[xcounter][15] = 10000;
		}
		if (xcounter == 7)
		{
			mainData[xcounter][5] = bestCaseRunner(50000);
			mainData[xcounter][6] = bestCaseRunner(50000);
			mainData[xcounter][7] = bestCaseRunner(50000);
			mainData[xcounter][8] = bestCaseRunner(50000);
			mainData[xcounter][9] = bestCaseRunner(50000);
			mainData[xcounter][10] = worstCaseRunner(50000);
			mainData[xcounter][11] = worstCaseRunner(50000);
			mainData[xcounter][12] = worstCaseRunner(50000);
			mainData[xcounter][13] = worstCaseRunner(50000);
			mainData[xcounter][14] = worstCaseRunner(50000);
			mainData[xcounter][15] = 50000;
		}
		if (xcounter == 8)
		{
			mainData[xcounter][5] = bestCaseRunner(100000);
			mainData[xcounter][6] = bestCaseRunner(100000);
			mainData[xcounter][7] = bestCaseRunner(100000);
			mainData[xcounter][8] = bestCaseRunner(100000);
			mainData[xcounter][9] = bestCaseRunner(100000);
			mainData[xcounter][10] = worstCaseRunner(100000);
			mainData[xcounter][11] = worstCaseRunner(100000);
			mainData[xcounter][12] = worstCaseRunner(100000);
			mainData[xcounter][13] = worstCaseRunner(100000);
			mainData[xcounter][14] = worstCaseRunner(100000);
			mainData[xcounter][15] = 100000;
		}
	}

}

float bestCaseRunner(int sizeOfVector)
{
	//declare local vectors
	vector<int> mainVector;

	//declare bubble sort class
	VectorManager manager; 

	//chrono declare inteveral local var
	chrono::time_point<chrono::system_clock> start, end;

	//create vector
	manager.createVectorSizeOfNOrdered(mainVector, sizeOfVector);

	//starting and ending point for bubble sort
	start = chrono::system_clock::now();//sort starting point
	doBubbleSort(mainVector); // do bubble sort
	end = chrono::system_clock::now();//sort ends point

	chrono::duration<double> elapsed_seconds = end - start; //do math to extract seconds

	return elapsed_seconds.count(); //return secs
}

float worstCaseRunner(int sizeOfVector)
{
	//declare local vectors
	vector<int> mainVector;

	//declare bubble sort class
	VectorManager manager;

	//chrono declare inteveral local var
	chrono::time_point<chrono::system_clock> start, end;

	//create vector
	manager.createVectorSizeOfNback(mainVector, sizeOfVector);

	//starting and ending point for bubble sort
	start = chrono::system_clock::now();//sort starting point
	doBubbleSort(mainVector); // do bubble sort
	end = chrono::system_clock::now();//sort ends point

	chrono::duration<double> elapsed_seconds = end - start; //do math to extract seconds

	return elapsed_seconds.count(); //return secs
}


//int double array
void intDoubleArray(float array[][16], int yComp, int xComp)
{
	int ycounter = 0, xcounter = 0;
	for (; ycounter < yComp; ycounter++)
	{
		for (; xcounter < xComp; xcounter++)
		{
			array[ycounter][xcounter] = 0.0;
		}
		xcounter = 0;
	}
}

//int double array
void printDoubleArray(float array[][16], int yComp, int xComp)
{
	int ycounter = 0, xcounter = 0;
	for (; ycounter < yComp; ycounter++)
	{
		for (; xcounter < xComp; xcounter++)
		{
			cout << array[ycounter][xcounter] << " ";
		}
		cout << endl;
		xcounter = 0;
	}
}

//do a complete run including creating and sorting vector
float completeRun(int sizeOfVector)
{
	//declare local vectors
	vector<int> mainVector;

	//declare bubble sort class
	VectorManager manager;

	//chrono declare inteveral local var
	chrono::time_point<chrono::system_clock> start, end;

	//create vector
	manager.genRandomNumsInVector(mainVector, sizeOfVector);

	//starting and ending point for bubble sort
	start = chrono::system_clock::now();//sort starting point
	doBubbleSort(mainVector); // do bubble sort
	end = chrono::system_clock::now();//sort ends point

	chrono::duration<double> elapsed_seconds = end - start; //do math to extract seconds

	return elapsed_seconds.count(); //return seconds
}

//bubble sort 
void doBubbleSort(vector<int> &mainVector)
{
	//local vars
	int ittOne = 0, ittTwo = 0, sizeOfVector = 0, temp = 0;

	//set size to int
	sizeOfVector = mainVector.size();

	//bubble sort
	for (; ittOne < sizeOfVector; ittOne++)
	{//first layer
		for (ittTwo = 0; ittTwo < sizeOfVector - ittOne - 1; ittTwo++)
		{//second layer
			if (mainVector[ittTwo] > mainVector[ittTwo + 1])
			{//swap
				temp = mainVector[ittTwo];
				mainVector[ittTwo] = mainVector[ittTwo + 1];
				mainVector[ittTwo + 1] = temp;
			}
		}
		ittTwo = 0; //reset ittTwo
	}
}