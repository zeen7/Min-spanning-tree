#pragma once
#include <iostream>
#include <string>
#include <vector>


class heapNode {
public:
	heapNode();
	int node_num;
	double key;
	int parent;
	bool in_pq;
	int current_index;
};