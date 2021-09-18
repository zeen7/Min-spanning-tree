#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "heapNode.h"

class heap {
public:
	heap(int size);
	//~heap();
	int heapCap;
	int heapSize;
	double total;
	bool firstRun;
	heapNode ** h;
	heapNode ** node_address;
	void heapify(int parent);
	int get_parent(int i);
	int get_left(int i);
	int get_right(int i);
	int extractMin();
	void insertNode(int n, double k, int p);
	void modifyNode(int n, double k, int p); 
	double getKey(int i);
	
	void print(); //for debugging, not used
	bool empty();
	bool find(int k);
	int getMin(); //for debugging, not used
};