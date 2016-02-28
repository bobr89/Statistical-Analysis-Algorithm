#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string.h>
#include <math.h>
using namespace std;

void bubbleSort (float item[], int size){
	for (int currentRound = 0; currentRound < size - 1; currentRound++) {
		for (int currentIteration = 0; currentIteration < size - 1 - currentRound; currentIteration++) {
			if (item[currentIteration] > item[currentIteration + 1]) {
				float temp = item[currentIteration];
				item[currentIteration] = item[currentIteration + 1];
				item[currentIteration + 1] = temp;
			}
		}
	}
}