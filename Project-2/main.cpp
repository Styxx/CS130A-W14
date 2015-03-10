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
};

// Used to sort edges by weight for algorithm
bool compare(Edge *x, Edge *y) {
	if (x->weight == y->weight){
		if (x->node1 == y->node1){
			return x->node2 < y->node2;
		}
		return x->node1 < y->node1;
	}
	return x->weight < y->weight;
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
  	Edge **edges, **mst;
	//Edge **graph;

	// DEBUG for input
	//cout << "Initialized everything successfully" << endl;



	// Retrieve the first line
	getline(cin, line);
	chunk = strtok(&line[0], " ");
	numVerts = atoi(chunk);
	chunk = strtok(NULL,"\n");
	numEdges = atoi(chunk);
	
	// numVerts is now # of verticies
	// numEdges is now # of edges
	
	// DEBUG for input
	//cout << "numVerts: " << numVerts << " " << "numEdges: " << numEdges << endl;

	
	// Create structures
	edges = new Edge*[numEdges];
	UFStruct ds(numVerts);		// Normal graph
	UFStruct ms(numVerts);		// MST

	// DEBUG for structs creations
	//cout << "Structures created" << endl;
	


  	// Read the rest of the file, processing edges
  	// Format: Vert1, Vert2, Weight
  	while (!cin.eof()) {
    		arg1 = arg2 = arg3 = -1;
    		getline(cin,line);            	//Next line
    		
			chunk = strtok(&line[0]," ");   // Get first number (first vertex)
    		arg1 = atoi(chunk);
    		chunk = strtok(NULL," ");       // Get second number (second vertex)
    		arg2 = atoi(chunk);
    		chunk = strtok(NULL,"\n");      // Get final number (weight of edge)
    		arg3 = atoi(chunk);
    		
    		// DEBUG for input
    		//cout << "Vert1: " << arg1 << " " << "Vert2: " << arg2 << " " << "Weight: " << arg3 << endl;
    	
	
			//Create new connection
    		edges[i] = new Edge;
			edges[i]->node1 = arg1;
			edges[i]->node2 = arg2;
    		edges[i]->weight = arg3;
    		
    		i++;
    		
    		// DEBUG for edge creation
    		//cout << "Edge created" << endl;
			/*
			cout << "Vert1: " << edges[i-1]->node1 << endl;
			cout << "Vert2: " << edges[i-1]->node2 << endl;
			cout << "Weight: " << edges[i-1]->weight << endl;
			*/
  	}

	// Sort the edges before creating the graph
   	// Algorithm helps us sort since we made a comp funct. above
    sort(edges, edges+numEdges, compare);

	// DEBUG for sorting
	//cout << "Graph successfully sorted" << endl;

	// Create graph from edge array, for output messages
    for (i=j=0; i < numEdges && j < numVerts-1; i++){
    	t1 = edges[i]->node1;
    	t2 = edges[i]->node2;
	   	
		//If there is no path already between the two nodes
		if(!ds.isPath(t1,t2)) {
			cout << "Edge (" << t1 <<","<< t2 <<") successfully inserted" << endl;
		}
   			else{
   				cout << "Edge (" << t1 <<","<< t2 <<") creates cycle" << endl;
		}
		
		
   		// No matter what, we're adding to the graph.
   		// Move to the next edge to process.
		ds.Union(t1,t2);
		
		// THIS SEGFAULTS? Do i even need it?
	 	//graph[j] = edges[i];
		
   	 }

	    
    // Now create MST
    mst = new Edge*[numVerts-1];			// MST contains 1 less edges than the number of verticies

	for (i=j=0; i < numEdges && j < numVerts-1; i++){
		t1 = edges[i]->node1;
		t2 = edges[i]->node2;
	   	
    		// If they're not connected, add to mst
		if (!ms.isPath(t1,t2)) {
			ms.Union(t1,t2);
			mst[j++] = edges[i];
			cost = cost + edges[i]->weight;

		}
		// Otherwise, do nothing
	}
	
	// Check if the MST is an actual MST.
	bool err = false;
	int mstLeader = ms.Find(mst[0]->node1);

	for (int k = 1; k < j; k++){
	  if (mstLeader != ms.Find(mst[k]->node1)){
	    err = true;
	  }
	}

	// If there is an error, print out error message
	if (err){
	  cout << "ERROR: MST not found.";
	}
	else {
	  // Otherwise, print out MST
	  for (i=0; i < j; i++){
	    cout << mst[i]->node1 << " " << mst[i]->node2 << endl;
	  }
	
	  // Print out cost of MST
	  cout << cost;
	}

	return 0;
	
}
