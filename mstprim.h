#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include "node.h"
#include "heap.h"

class mstprim {
public:
	std::vector<std::vector<double>> graph_adj_matrix;
	//std::vector<node*> vertex_list;
	node** vertex_list;
	int num_edge;
	int graph_size;
	mstprim();
	void create_graph(int m);
	bool insert(int u, int v, double w);
	bool erase(int u, int v);
	bool adjacent(int u, int v, double w);
	int degree(int u);
	int edge_count();
	bool clear();
	double mst(int u);
	//~mstprim();
};