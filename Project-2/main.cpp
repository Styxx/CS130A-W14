#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include "UFStruct.h"
using namespace std;

// Edge that connects the nodes
struct Edge{
	int node1;
	int node2;
	int weight;
}

// Used to sort edges by weight for algorithm
bool compare(Edge *x, Edge *y) {
	return x->weight < b->weight;
}



int main() {
	// Inputs
	string line;
	int numVerts, numEdges;
	int arg1, arg2, arg3;
	char* chunk;
	
	// Outputs
	int cost = 0;
	
	// Iterators and temps
	int i = 0;
	int j = 0;
	int t1,t2;
	
	// Structs
  	Edge **edges, **mst, **graph;
	  
	// Retrieve the first line
	getline(cin, line);
	chunk = strtok(&line[0], " ");
	numVerts = atoi(chunk);
	chunk = strtok(NULL,"\n");
	numEdges = atoi(chunk);
	
	// numVerts is now # of verticies
	// numEdges is now # of edges
	
	// Create structures
	edges = new Edge*[numEdges];
	UFStruct ds(numVerts);		// Normal graph
	UFStruct ms(numVerts);		// MST
	
	  
	  
	  
  	//Read the rest of the file.
  	while (!cin.eof()) {
    		arg1 = arg2 = arg3 = -1;
    		getline(cin,line);            	//Next line
    		
		chunk = strtok(&line[0]," ");   // Get first number (first vertex)
    		arg1 = atoi(chunk);
    		chunk = strtok(NULL," ");       // Get second number (second vertex)
    		arg2 = atoi(chunk);
    		chunk = strtok(NULL,"\n");      // Get final number (weight of edge)
    		arg3 = atoi(chunk);
    		
		//Create new connection
    		edges[i] = new Edge;
		edges[i]->node1 = arg1;
		edges[i]->node2 = arg2;
    		edges[i]->weight = arg3;
    		
    		i++;
  	}
	
	// From edge array, create graph.
	// Add to graph and output messages
    	for (i=j=0; i < numEdges && j < numVerts-1; i++){
    		t1 = edges[i]->node1;
    		t2 = edges[i]->node2;
	    	
		//If there is no path already between the two nodes
		if(!ds.Path(t1,t2)) {
			cout << "Edge (" << t1 <<","<< t2 <<") successfully inserted" << endl;
		}
    		else{
    			cout << "Edge (" << t1 <<","<< t2 <<") creates cycle" << endl;
		}
    		// Add to graph
    		ds.merge(t1,t2);
	 	graph[j++] = edges[i];
    	}


 	// Tree is created. Now sort the edges for MST
    	// Algorithm helps us sort since we made a comp funct.
    	sort(edges, edges+numEdges, compare);
	    
    	// Now sorted, add to MST
    	mst = new Edge*[numVerts-1];			// MST contains 1 less edges than the number of verticies
	for (i=j=0; i < numEdges && j < numVerts-1; i++){
		t1 = edges[i]->node1;
    		t2 = edges[i]->node2;
	   	
    		// If they're not connected, add to mst
		if (!ms.connected(t1,t2)) {
			ms.merge(t1,t2);
			mst[j++] = edges[i];
			cost = cost + edges[i]->weight;
		}
		// Otherwise, do nothing
	}
		
	// Print out MST
	for (i=0; i < j; i++){
		cout << mst[i]->node1 << " " << mst[i]->node2 << endl;
	}
	
	// Print out cost of MST
	cout << cost << endl;
	
	return 0;
	
}
