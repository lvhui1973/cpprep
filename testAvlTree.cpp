/*
 * testAvlTree.c++
 *
 *  Created on: 2015Äê8ÔÂ8ÈÕ
 *      Author: lh
 */
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "avlTree.h"
using namespace std;

#define MAXNODE 15
int main() {
	datatype data[MAXNODE];
	srand(time(NULL));
	for (int i = 0; i < MAXNODE; i++) {
		data[i] = rand() % MAXNODE; //data is between -15 ~~~~15
	}
	cout << "Original data" << endl;
	for (int i = 0; i < MAXNODE; i++) {
		cout << data[i] << ",";
	}
	cout << endl;
//test insert and print
	avlTree *atr = new avlTree();
	cout << "Before tree build" << endl;
	/*try {
		cout << "The Max is" << atr->findMax() << endl;

	} catch (string &s) {
		cout << s << endl;
	}
	try {
		cout << "The Min is" << atr->findMin() << endl;

	} catch (string &s) {
		cout << s << endl;
	}*/

	for (int i = 0; i < MAXNODE; i++) {
		atr->insert(data[i]);
	}
	cout << "Here is after tree insert node" << endl;
	cout << "The tree depth is" << atr->getMaxdepth() << endl;
	try {
		cout << "The Max is" << atr->findMax() << endl;
		cout << "The Min is" << atr->findMin() << endl;
	} catch (string &s) {
		cout << s << endl;
	}

	cout << "The is empty" << atr->isEmpty() << endl;

	cout << "Data0 is in Tree =" << data[0] << " " << atr->contains(data[0])
			<< endl;
	cout << "Data0 is in Tree =" << data[1] << " " << atr->contains(data[1])
			<< endl;
	cout << "Data0 is in Tree =" << data[2] << " " << atr->contains(data[2])
			<< endl;
	cout << "Data100 is in Tree =" << 100 << " " << atr->contains(100) << endl;

	atr->printtree();
	delete atr;
	return 0;
}

