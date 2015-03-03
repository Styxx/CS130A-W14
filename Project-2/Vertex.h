

class Vertex {
	public:
	Vertex* root;				// Pointer to root
	Vertex* parent;				// Pointer to parent
	int pWeight;				// Weight of edge to parent
	int value;				// Node's value
	int rank;				// Size of set
};
