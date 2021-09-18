#pragma once
#include "heap.h"
heap::heap(int size) {
	firstRun = true;
	heapCap = size;
	heapSize = 0;
	total = 0;
	h = new heapNode* [size];
	node_address = new heapNode * [size];
	for (int i = 0; i < size; i++)
	{
		h[i] = new heapNode();
		node_address[i] = h[i];
	}
}

void heap::heapify(int parent) {
	int left = get_left(parent);
	int right = get_right(parent);
	int min = parent;
	if (heapSize > left && h[left]->key < h[parent]->key)
	{
		min = left;
		
	}

	if (heapSize > right && h[right]->key < h[min]->key)
	{
		
		min = right;
		h[parent]->current_index--;
	}

	if (min != parent)
	{
		

		h[parent] -> current_index = min;
		h[min] -> current_index = parent;
		heapNode* temp = h[parent];
		h[parent] = h[min];
		h[min] = temp;
		
		heapify(min);
	
	}
	
}

int heap::get_parent(int i) {
	return (i-1)/2;
}

int heap::get_left(int i) {
	return 2*i+1;
}

int heap::get_right(int i) {
	return 2*i+2;
}

int heap::extractMin() {
	
	h[0]->in_pq = false;
	total += h[0]->key;
	//std::cout << "Adding " << h[0]->key << "current total: " << total << std::endl;
	int p = h[0]->node_num;
	h[0] = h[heapSize - 1];
	h[0]->current_index = 0;
	heapSize--;
	heapify(0);
	//std::cout << "now min: " << h[0]->node_num << std::endl;
	
	return p;
}

void heap::insertNode(int n, double k, int p) {
	if (heapSize == heapCap)
	{
		return;
	}
	
	int i = heapSize;
	
	h[i]->node_num = n;
	
	h[i]->key = k;
	
	h[i]->parent = p;

	h[i]->in_pq = true;

	h[i]->current_index = i;
	
	heapSize++;
}

//modifies key and moves it depending on it keeps heap properties
void heap::modifyNode(int n, double k, int p) {
	
	
	int y = node_address[n]->current_index;
	h[y]->key = k;
	h[y]->parent = p;
	
	n = y;
	
	while (n != 0 && h[get_parent(n)]->key > h[n]->key)
	{
		h[n]->current_index = get_parent(n);
		h[get_parent(n)]->current_index = n;
		heapNode* temp = h[n];
		h[n] = h[get_parent(n)];
		h[get_parent(n)] = temp;
		n = get_parent(n);
	}
}

bool heap::find(int k) {
	if (node_address[k]->in_pq == true)
	{
		return true;
	}
	return false;
}

bool heap::empty() {
	if (heapSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double heap::getKey(int i) {
	if (find(i))
	{
		return node_address[i]->key;
	}
	return -1;
}

/*heap::~heap() {
	for (int i = 0; i < heapCap; i++) {
		node_address[i]=nullptr;
		delete  node_address[i];
		delete  h[i];
	}
	delete [] node_address;
	node_address = nullptr;
	delete [] h;
	h = nullptr;
}*/

// functions for debugging
int heap::getMin() {
	return h[0]->node_num;
}
void heap::print() {
	for (int i = 0; i < heapSize; i++)
	{
		std::cout << "node_num " << h[i]->node_num<<"key: " << h[i]->key << std::endl;
		//std::cout << "key " << h[i]->key << std::endl;
		//std::cout << "parent " << h[i]->parent << std::endl;
		std::cout << std::endl;
	}
}

