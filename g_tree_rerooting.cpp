#include <iostream>
#include <vector>
using namespace std;

void dfs_check_subtree_validity(int node, int parent, const vector<vector<int>> &graph, const vector<int> &colors, vector<bool> &is_subtree_valid) {
    is_subtree_valid[node] = true;
    int expected_next_color = (colors[node] + 1) % 3; // Colors should follow the cycle Red (0) -> White (1) -> Black (2)

    for (int neighbor : graph[node]) {
        if (neighbor == parent) continue;

        is_subtree_valid[node] = is_subtree_valid[node] && (colors[neighbor] == expected_next_color);
        dfs_check_subtree_validity(neighbor, node, graph, colors, is_subtree_valid);
        is_subtree_valid[node] = is_subtree_valid[node] && is_subtree_valid[neighbor];
    }
}

void update_subtree_validity(int node, int skip_child, const vector<vector<int>> &graph, vector<bool> &is_subtree_valid, const vector<int> &colors) {
    int expected_next_color = (colors[node] + 1) % 3;
    is_subtree_valid[node] = true;

    for (int neighbor : graph[node]) {
        if (neighbor == skip_child) continue;

        is_subtree_valid[node] = is_subtree_valid[node] && (colors[neighbor] == expected_next_color);
        is_subtree_valid[node] = is_subtree_valid[node] && is_subtree_valid[neighbor];
    }
}

void re_rooting_search(int node, int parent, const vector<vector<int>> &graph, const vector<int> &colors, vector<bool> &is_subtree_valid, vector<int> &result_root) {
    if (result_root[0] != -1) return; // Valid root already found, no need to proceed further

    for (int neighbor : graph[node]) {
        if (neighbor == parent) continue;

        // Save previous validity states
        bool prev_validity_node = is_subtree_valid[node];
        bool prev_validity_neighbor = is_subtree_valid[neighbor];

        // Re-root
        update_subtree_validity(node, neighbor, graph, is_subtree_valid, colors);
        update_subtree_validity(neighbor, -1, graph, is_subtree_valid, colors);

        // If `neighbor` becomes a valid root
        if (is_subtree_valid[neighbor] && graph[neighbor].size() <= 2) {
            result_root[0] = neighbor;
        }

        // Continue searching with the new root
        re_rooting_search(neighbor, node, graph, colors, is_subtree_valid, result_root);

        // Restore previous validity states
        is_subtree_valid[node] = prev_validity_node;
        is_subtree_valid[neighbor] = prev_validity_neighbor;
    }
}

int find_valid_root(int n, const vector<vector<int>> &graph, const vector<int> &colors) {
    vector<bool> is_subtree_valid(n, false);
    dfs_check_subtree_validity(0, -1, graph, colors, is_subtree_valid);

    // If the initial root (0) is valid, return it
    if (is_subtree_valid[0]) return 0;

    // Search for a valid root using re-rooting technique
    vector<int> result_root(1, -1);
    re_rooting_search(0, -1, graph, colors, is_subtree_valid, result_root);
    return result_root[0];
}

int main() {
    // Sample Input 1
    int n1 = 8;
    vector<vector<int>> graph1(n1);
    vector<pair<int, int>> edges1 = {{2, 3}, {2, 4}, {2, 1}, {3, 5}, {3, 0}, {4, 6}, {4, 7}};
    vector<int> colors1 = {1, 0, 2, 0, 0, 1, 1, 1}; // Colors for Sample Input 1

    for (auto &[u, v] : edges1) {
        graph1[u].push_back(v);
        graph1[v].push_back(u);
    }

    cout << "Sample Input 1 Answer: " << find_valid_root(n1, graph1, colors1) << "\n"; // Expected Output: -1

    // Sample Input 2
    int n2 = 8;
    vector<vector<int>> graph2(n2);
    vector<pair<int, int>> edges2 = {{2, 3}, {2, 4}, {2, 1}, {3, 5}, {3, 0}, {4, 6}, {4, 7}};
    vector<int> colors2 = {1, 1, 2, 0, 0, 1, 1, 1}; // Colors for Sample Input 2

    for (auto &[u, v] : edges2) {
        graph2[u].push_back(v);
        graph2[v].push_back(u);
    }

    cout << "Sample Input 2 Answer: " << find_valid_root(n2, graph2, colors2) << "\n"; // Expected Output: 1

// Sample Input 2
    int n3 = 6;
    vector<vector<int>> graph3(n3);
    vector<pair<int, int>> edges3 = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {3, 5}};
    vector<int> colors3 = {0,1,1,1,2,2}; // Colors for Sample Input 2

    for (auto &[u, v] : edges3) {
        graph3[u].push_back(v);
        graph3[v].push_back(u);
    }

    cout << "Sample Input 2 Answer: " << find_valid_root(n3, graph3, colors3) << "\n"; // Expected Output: 1

    return 0;
}
