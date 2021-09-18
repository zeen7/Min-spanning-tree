#include "mstprim.h"

mstprim::mstprim(){
	//std::vector<node> v = {};
}

void mstprim::create_graph(int m) {
	num_edge = 0;
	graph_size = m;
	vertex_list = new node * [m];
	//vertex_list.resize(m);
	graph_adj_matrix.resize(m);
	for (int i = 0; i < m; i++)
	{
		//std::cout<<i<<std::endl;
		graph_adj_matrix[i].resize(m);
		vertex_list[i] = new node();

		for (int j = 0; j < m; j++)
		{
			graph_adj_matrix[i][j] = 0;
		}
	}
}

bool mstprim::insert(int u, int v, double w) {
	if (graph_adj_matrix[u][v] == 0 && graph_adj_matrix[v][u] == 0)
	{
		vertex_list[u]->degree++;
		vertex_list[v]->degree++;
		num_edge += 2;
	}
	graph_adj_matrix[u][v] = w;
	graph_adj_matrix[v][u] = w;

}

bool mstprim::erase(int u, int v) {
	if (graph_adj_matrix[u][v]>0 && graph_adj_matrix[v][u]>0)
	{
		graph_adj_matrix[u][v] = 0;
		graph_adj_matrix[v][u] = 0;
		vertex_list[u]->degree--;
		vertex_list[v]->degree--;
		num_edge-=2;
		return true;
	}
	else {
		return false;
	}
}

bool mstprim::adjacent(int u, int v, double w) {
	//std::cout<< graph_adj_matrix[u][v]<<" "<< w<<std::endl;
	if (graph_adj_matrix[u][v] == w)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int mstprim::degree(int u) {
	return vertex_list[u]->degree;
}

int mstprim::edge_count() {
	return num_edge;
}

bool mstprim::clear() {
	/*for (int i = 0; i < graph_size; i++)
	{
		delete vertex_list[i];
	}
	delete[] vertex_list;
	vertex_list = nullptr;
	graph_adj_matrix.clear();
	graph_adj_matrix.resize(0);*/
	create_graph(graph_size);
}

double mstprim::mst(int r) {
	int u = r;
	heap minHeap(graph_size);
	double a = std::numeric_limits<double>::max(); //infinity
	for (int i = 0; i < graph_size; i++)
	{
		minHeap.insertNode(i, a, -1);
	}
	
	minHeap.modifyNode(r, 0.00, -1);
	
	while(minHeap.empty()!=true){
		
		u = minHeap.extractMin();
		for (int v=0; v<graph_size; v++)
		{
			
			if (graph_adj_matrix[u][v] != 0 && graph_adj_matrix[u][v]< minHeap.getKey(v) && minHeap.find(v)) {
				
				minHeap.modifyNode(v, graph_adj_matrix[u][v], u);
				
			}
			
		}
		
	}
	double temp = minHeap.total;
	//minHeap.~heap();
	return temp;
}
/*mstprim::~mstprim() {
	std::cout << graph_size << std::endl;
	for (int i = 0; i < graph_size; i++)
	{
		std::cout << i << std::endl;
		delete vertex_list[i];
	}
		delete [] vertex_list;
		vertex_list = nullptr;
		graph_adj_matrix.clear();
		graph_adj_matrix.resize(0);
	//}
	//vertex_list.clear();
}*/
