/*
	Entire Data Structure's Methods
	Makeset(x) - Creates new set x and adds it to the family of sets
	Find(x) - Return root of set containing x.
	Union(x,y) - Changes family by merging two sets - the set containing x and the set containing y.
		No-op if x and y are in the same set. (Can check by seeing if leaders are same)
		Merge by setting leader of all vertexes in smaller set to leader of bigger set. Connect leaders.

*/

class UFStruct {
	public:
	makeset(int x) {
		Vertex node = new Vertex;
		node.value = x;
		node.parent = node;
		node.root = node;
		node.rank = 0;
		node.pWeight = 0;
	}
	
	find(Vertex* x){
		if(x.parent != x){
			x.parent = find(x.parent);
		}
		return x.parent;
	}
	
	unio(Vertex* x, Vertex* y){
		Vertex xRoot = find(x);			// Get root of x
		Vertex yRoot = find(y);			// Get root of y
		
		// If x and y are in the same set
		if (xRoot.value == yRoot.value){
			return;				// Do nothing
		}
		
		//Otherwise
		if (xRoot.rank < yRoot.rank){		// y's tree is bigger
			xRoot.parent = yRoot;
		}
		else if (xRoot.rank > yRoot.rank){	// x's tree is bigger
			yRoot.parent = xRoot;
		}
		else {					// Arbitraily say x is bigger
			yRoot.parent = xRoot;
			xRoot.rank += 1;		// Increase x's rank by 1.
		}
	}
	
};


/*
what's path compression?
	when you run find
	if theres more than one step up to the root
	it reassigns the parent to the root
	rather than its immediate parent
	it jus means you need to add a thing that parses back up the tree
	something like while(parent.parent != null) parent = parent.parent;
*/


class Vertex {
	public:
	Vertex* root;				// Pointer to root
	Vertex* parent;				// Pointer to parent
	int pWeight;				// Weight of edge to parent
	int value;				// Node's value
	int rank;				// Size of set
};


