//PRANEEL MISTHRY
// 202515355
//COMPUTER METHODS 3 Tut6-Vector
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <vector>  //std::vector
#include <algorithm> //std::sort
#include <list>

using namespace std;

void fillVector(vector<int> &myVector);
void printVector(const vector<int> &myVector);

int main()
{
	vector<int> testVector; //Vector for demo of user input

	int testArray[20] = { 1, 20, 52, 65, 78, 1, 32, 15, 6, 8, 7, 23, 41, 13, 52, 90, 7, 65, 17, 5 }; //Arbitary integer array to pass to the vector
	vector<int> testVector2(testArray, testArray + 20); //Fill the vector with 20 elements from the array

	//Print it out
	cout << "Original testVector2: " << endl;
	printVector(testVector2);

	//sort the vector
	sort(testVector2.begin(), testVector2.begin() + 20); //sort 20 elements starting at the beginning 
	cout << "Sorted lowest to highest testVector2: " << endl;
	printVector(testVector2);

	//The sort function by default sorts from lowest to highest
	//To sort from highest to lowest use the reverse function AFTER using the sort function
	reverse(testVector2.begin(), testVector2.end());
	
	//print it out
	//Print it out
	cout << "Sorted testVector2 highest to lowest: " << endl;
	printVector(testVector2);

	//For the other vector
	//Fill the vector
	fillVector(testVector);

	//Print the vector
	printVector(testVector);

	//Erase the current vector values
	testVector.clear();

	//check if vector was cleared properly
	if (testVector.empty()) //returns true if the vector is cleared
	{
		cout << "Please enter more than 20 integers for your next vector" << endl;
		fillVector(testVector);

		//Sort the vector up to 20 integers
		//using the sort function from algorithm stl
		// using default comparison (operator <)
		sort(testVector.begin(), testVector.begin() + 20);
		reverse(testVector.begin(), testVector.end());

		//Print out the new vector which has been sorted up to 20 integers
		printVector(testVector);
	}

	else
	{
		cout << "Vector was not cleared properly" << endl;
	}

	system("PAUSE");
	return 0;
}

void fillVector(vector<int> &myVector) //must pass by reference
{
	int input = -1;

	cout << "Please enter integers for your vector" << endl;
	cout << "Enter -1 to stop" << endl;
	cin >> input;

	while (input != -1) //Don't need to worry about the size as the push back method resizes the vector
	{
		myVector.push_back(input);	 
		cin >> input;              //Used to help terminate the loop ==> Keeps checking for termination value also
	}

}

void printVector(const vector<int> &myVector)
{
	cout << "Vector: ";

	for (unsigned int i = 0; i < myVector.size(); i++) //must use unsigned int for vector loop counter or iterator
	{
		cout << myVector[i] << "\t";
	}

	cout << endl;
}