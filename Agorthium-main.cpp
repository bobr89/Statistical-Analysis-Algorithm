/*
 * Name: Brian Chan
 * Date Last Modified: 1/31/2016
 * Purpose: Stats Analysis
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <climits>
#include <cmath>
using namespace std;

extern float avg(float item[], int size);
extern float median(float item[], int size);
extern float stdDev(float item[], float a, int size);
extern float aad(float item[], float m, int size);

int main () {     //int numArgs, char* arg[]
	
/*	if (numArgs != 2) {
		cerr << "Error" << endl;
		return -1;
	}
	
	int passWord = atoi(arg[1]);
	if (passWord != 123){
		cerr << "Error" << endl;
		return -1;
	}*/
	/*
	cout << "            *      * ******* *        ******  ******** *      * *******   *      * *******      ******  *      *    *    *     *" << endl;
	cout << "            *  **  * *       *       *      * *      * **    ** *         **    ** *      *    *      * *      *   * *   **    *" << endl;
	cout << "            *  **  * *       *       *        *      * * *  * * *         * *  * * *      *    *        *      *  *   *  * *   *" << endl;
	cout << "            *  **  * *****   *       *        *      * *  *   * *****     *  *   * *******     *        ******** ******* *  *  *" << endl;
	cout << "            *  **  * *       *       *        *      * *      * *         *      * *   *       *        *      * *     * *   * *" << endl;
	cout << "            *  **  * *       *       *      * *      * *      * *         *      * *    *   ** *      * *      * *     * *    **" << endl;
	cout << "             **  **  ******* *******  ******  ******** *      * *******   *      * *     *  **  ******  *      * *     * *     *" << endl;
	*/
	
	ifstream inputFile;
	ofstream outputFile;
	
	inputFile.open("testing.txt");
	
	/*if (inputFile.fail()){
		cerr << "Error" << endl;
		return -1;
	}*/
	
	string str;
	int numberOfLines = 0;
	
	while (getline(inputFile, str)){
		numberOfLines++;
	}
	
	inputFile.close();
	inputFile.open("testing.txt");
	
	string servedURI[numberOfLines][3];
	int lineCount = 0;
	
	while (getline(inputFile, str)){
		
		istringstream iss(str);
		string URI1;
		string URI2;
		string URI3;
		
		iss >> URI1 >> URI2 >> URI3;
		
		servedURI[lineCount][0] = URI1;
		servedURI[lineCount][1] = URI2;
		servedURI[lineCount][2] = URI3;
		lineCount++;
	}
	
	float matches[numberOfLines];
	int b = 0;
	int n = 0;
	int x = 0;
	
	for (int i = 0; i < numberOfLines; i++){
		
//		int b = 0; // b = 0 / 1 / 2
		x = 0;
		
		if (servedURI[i][b] == servedURI[i][b + 1]){
			x = 2; 
		}
		if(servedURI[i][b] == servedURI[i][b + 2]){
			x = 2;
		}
		if (servedURI[i][b + 1] == servedURI[i][b + 2]){
			x = 2;
		}
		if (servedURI[i][b] == servedURI[i][b + 1] && servedURI[i][b] == servedURI[i][b + 2]){
			x = 3;
		}
		matches[n] = x;
		n++;
		
		//Testing 
//		cout << x << endl; //x = how many URI are the same 
	}
	
	// Output URI
	
	for (int index = 0; index < numberOfLines; index++){
		
		if (matches[index] != 3){
			cout << index + 1 << " " << servedURI[index][0] << endl << servedURI[index][1] << endl << servedURI[index][2] << endl << endl;
		}
	}
	
	//Central Tendency Calculation
	
	// Averages
	float a1 = avg(matches, numberOfLines);
	
	// Median
	float m1 = median(matches, numberOfLines);
	
	// stdDev
	float s1 = stdDev(matches, a1, numberOfLines);
	
	// aad
	float aad1 = aad(matches, m1, numberOfLines);
	
	//Output
	cout << "Average: " << a1 << endl;
	cout << "Median: " << m1 << endl;
	cout << "Standard Deviation: " << s1 << endl;
	cout << "Average Absolute Deviation: " << aad1 << endl;
	
	// Average => Mean (Use when there is no outliers within set of data) 
	
	// Median => Mean (Use when no /little outliers)
	
	// Standard Deviation => Measure the dispersion of a set of data values, 
	//						 closer to 0 means most data is very close to the mean. 
    //					     (How sprend out is the data / How consistence is the data)
	
	// Average Absolute Deviation => Similar to stdDev but it is a summary statistic of 
	//								 statistical dispersion or variability.
	
	
	return 0;
	}


