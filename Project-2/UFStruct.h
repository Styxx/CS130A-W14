#include <stdio>
#include <vector>
using namespace std

class UFStruct {
	int* vertexes;
	int* sets;
	int count;

	public:
		
		UFStruct::UF(){					// Empty Ctor
			cnt = 0;
			vertexes = new int[0];
			sets = new int[0];
		}
		
		UFStruct::UF(int num){			// Creates DS with num sets
			cnt = num;
			vertexes = new int[num];
			sets = new int[num];
			for (int i = 0; i < num; i++){
				vetexes[i] = i; sets[i] = i;
			}
			
		}
		
		int UFStruct::Find(int value){
			int leader = value;
			
			// Go find the leader of the set
			while (leader != vertexes[leader]){
				leader = vertexes[leader];
			}
			
			// Path compression
			while (value != leader){
				int val2 = vertexes[value];
				vertexes[value] = leader;
				value = val2;
			}
			
			return leader;
		}
		
		void UFStruct::Union(int x, int y){
			int xLeader = Find(x);
			int yLeader = Find(y);
			
			// If the leaders are the same, then the elements are in the same set
			if (xLeader == yLeader){
				return;		// Do nothing
			}
			
			// Leaders are not the same. Union the smaller one into the bigger one.
			if (sets[xLeader] < sets[yLeader]){
				vertexes[xLeader] = yLeader;
				sets[xLeader] = sets[xLeader] + sets[yLeader];
			}
			else{
				vertexes[yLeader] = xLeader;
				sets[yLeader] = sets[yLeader] + sets[xLeader];
			}
			
			// Since sets were merged, reduce number of sets.
			count--;
		}
		
		// Checks if there is a path between x and y.
		// If leaders are the same, there is a path.
		// Necessary for O(1) cycle checks
		bool UFStruct::Path(int x, int y){
			return Find(x) == Find(y);
		}
		
		// Return number of sets in DS
		int UFStruct::Count {
			return count;
		}
}
