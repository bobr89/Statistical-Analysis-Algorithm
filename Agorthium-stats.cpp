#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

extern void bubbleSort (float item[], int size);

float avg(float item[], int size){
	float average = 0;
	float sumOfSizes = 0;
	for (int index = 0; index < size; index++){
	sumOfSizes = sumOfSizes + item[index];
	}
	average = sumOfSizes / size;
	return average;
}

float median (float item[], int size){
	bubbleSort (item, size);
	float median = 0;
	if (size%2 == 0){
		median = (item[size/2] + item[(size/2) + 1]) / 2;
	}
	else {
		median = item[size/2];
	}
	return median;
}

float stdDev(float item[], float a, int size){
	float stdDevOut = 0;
	float sum = 0;
	for (int index = 0; index < size; index++){
		sum = sum + pow((item[index] - a) , 2);
	}
	stdDevOut = sum / size;
	stdDevOut = sqrt(stdDevOut);
	return stdDevOut;
}

float aad(float item[], float m, int size){
	float aad = 0;
	float sum = 0;
	
	for (int n = 0; n < size; n++){
		sum = sum + fabs(item[n] - m); //fabs = absolute value
	}
	aad = sum / size;
	return aad;
}