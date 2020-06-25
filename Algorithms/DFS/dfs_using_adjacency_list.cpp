#define total_nodes 100
vector<bool> visited(total_nodes);
vector<int> graph[total_nodes]

void dfs(int cur_node) {
	visited[cur_node] = 1;
	for (auto I : graph[cur_node]) {
		if(!visited[I]) {
			dfs(I);
		}
	}
	return;
}