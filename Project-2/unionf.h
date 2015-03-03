/*
	Entire Data Structure's Methods
	Makeset(x) - Creates new set x and adds it to the family of sets
	Find(x) - Return leader of set containing x.
	Union(x,y) - Changes family by merging two sets - the set containing x and the set containing y.
		No-op if x and y are in the same set. (Can check by seeing if leaders are same)
		Merge by setting leader of all vertexes in smaller set to leader of bigger set. Connect leaders.

*/


/*
	Each vertex needs:
		Pointer to leader.
		linked list with all links with other verticies
*/


