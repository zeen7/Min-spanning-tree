#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include "mstprim.h"

std::string line;
std::string siteURL;
std::regex e("");
class illegal_exception : public std::exception
{

};

int main()
{
	mstprim a;

	while (true) {

		if (std::cin.eof()) {
			break;
		}

		getline(std::cin, line);

		//exit command
		if (line == "exit") {
			//a.~mstprim();


			break;
		}
		int pos = line.find(" ");
		std::string cmd = line.substr(0, pos);
		std::string cmd2 = line.substr(pos + 1);
		int sc1_pos = cmd2.find(";");
		std::string u = cmd2.substr(0, sc1_pos);
		std::string cmd3 = cmd2.substr(sc1_pos + 1);
		int sc2_pos = cmd3.find(";");
		std::string v = cmd3.substr(0, sc2_pos);
		std::string w = cmd3.substr(sc2_pos + 1);
		try {
			//Generates graph with m nodes
			if (cmd == "n")
			{
				/*std::cout << cmd << std::endl;
				std::cout << cmd2 << std::endl;
				std::cout << u << std::endl;
				std::cout << v << std::endl;
				std::cout << w << std::endl;*/

				a.create_graph(stoi(cmd2));
				std::cout << "success" << std::endl;
			}

			//Inserts an edge between nodes u and v with weight w
			else if (cmd == "i")
			{
				/*std::cout << cmd << std::endl;
				std::cout << cmd2 << std::endl;
				std::cout << u << std::endl;
				std::cout << v << std::endl;
				std::cout << w << std::endl;*/
				
				if ( stoi(u) >= a.graph_size || stoi(v) >= a.graph_size || stod(w) <= 0.00 || stod(u) == stod(v) || stoi(u) < 0 || stoi(v) < 0) {
					
					throw illegal_exception();
				}
				else{
					a.insert(stoi(u), stoi(v), stod(w));
					std::cout << "success" << std::endl;
				}
			}

			//Erases the edge between nodes u and v
			else if (cmd == "e")
			{
				if (stoi(u) >= a.graph_size || stoi(cmd3) >= a.graph_size  || stod(u) == stod(cmd3) || stoi(u) < 0 || stoi(cmd3) < 0) {
					throw illegal_exception();
				}
				else {
					if (a.erase(stoi(u), stoi(v)) == true)
					{
						std::cout << "success" << std::endl;
					}
					else {
						std::cout << "failure" << std::endl;
					}
					
				}
			}

			//Check if there is an edge between nodes u and v with weight w
			else if (cmd == "adjacent")
			{
				if (stoi(u) >= a.graph_size || stoi(v) >= a.graph_size || stod(w) <= 0.00 || stod(u) == stod(v) || stoi(u) < 0 || stoi(v) < 0) {
					throw illegal_exception();
				}
				else {
					if (a.adjacent(stoi(u), stoi(v), stod(w))==true)
					{
						std::cout << "adjacent " << u<<" " << v <<" "<< std::fixed << std::setprecision(2) << w<< std::endl;
					}
					else {
						std::cout << "not adjacent " << u << " " << v << " " << w << std::endl;
					}
				}
			}

			//Returns the degree of node u
			else if (cmd == "degree")
			{
				if (stoi(cmd2) >= a.graph_size ) {
					throw illegal_exception();
				}
				else {
					std::cout << "degree of "<<cmd2 <<" is "<< a.degree(stoi(cmd2)) << std::endl;
				}
				
			}

			//Returns the total number of edges in the graph
			else if (cmd == "edge_count")
			{
				std::cout << "edge count is " << a.edge_count() << std::endl;
			}

			//Removes all the edges from the graph
			else if (cmd == "clear")
			{
				a.clear();
				std::cout << "success" << std::endl;
			}

			//Calculates the MST value and returns its total weight starting from node u
			else if (cmd == "mst")
			{
				if (stoi(cmd2) >= a.graph_size) {
					throw illegal_exception();
				}
				else {
					double answer = a.mst(stoi(cmd2));
					double infinity = std::numeric_limits<double>::max();
					if (answer > 0 && answer < infinity)
					{
						std::cout << "mst " << std::fixed << std::setprecision(2) << answer << std::endl;
					}
					else {
						std::cout << "not connected" << std::endl;
					}
				}
			}
			

		}
		catch (const illegal_exception& e) {
			std::cout << "illegal argument" << std::endl;
		}

	}

	return 0;
}

