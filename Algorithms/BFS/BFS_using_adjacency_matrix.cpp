/*
	Must needed header files:
	#include <queue>
	Assume that the nodes are numbered from 1 to N(total_nodes);
*/

int total_nodes = xxxxx; /* xxxx must be a decimal number */

void bfs(bool adj_list[][total_nodes], int dis_from_src[], int source) {
	
	bool vis[total_nodes+1];
	memset(vis, false, total_nodes+1); 
	memset(dis_from_src, 0, total_nodes+1);
	queue<int> q;
	q.push(source);
	cout << "BFS Order = ";

	while(!q.empty()) {
		int now_at = q.front();
		q.pop();
		cout << now_at << " ";
		
		for (int i = 0; i < total_nodes; ++i) {
			if(adj_list[now_at][i] && vis[i] == false  && i!= now_at) {  /* if i has and edge with current node(now_at) 
																			, i is not the current node and
																			the node(i) is not visited yet */
				q.push(i);
				dis_from_src[i] = dis_from_src[now_at] + 1;       /* distacne of current node from the source node
																	 = distance of my current node from the source node + 1 */
				vis[i] = true;
			}
		}
	} 
	cout << endl;
}
