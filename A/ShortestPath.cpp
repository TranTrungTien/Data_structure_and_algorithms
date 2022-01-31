#include <fstream>
#include <iostream>
#include <vector>

// using Backtracking and Brute force

int findShortestPath(std::vector<int> &path, const std::vector<std::vector<int>> &graph, std::vector<bool> &visited, const unsigned startVertex, const unsigned endVertext)
{
    if(startVertex == endVertext) return 0;

    unsigned columns = graph[0].size();

    visited[startVertex] = true;
    auto ans = INT32_MAX;

    for(unsigned i = 0 ; i < columns; ++i)
    {
        if(visited[i] == false && graph[startVertex][i] != 0)
        {
            auto res = findShortestPath(path, graph, visited, i, endVertext);

            if(res < INT32_MAX)
            {
                ans = std::min(ans, graph[startVertex][i] + res);
            }
        }
    }
    visited[startVertex] = false;
    return ans;
}


int findNextVertex(const std::vector<bool> &visited, const std::vector<int> &distance)
{
    int mindist = INT32_MAX;
    int vertex = -1;
    int n = distance.size();
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && distance[i] <= mindist)
        {
            mindist = distance[i];
            vertex = i;
        }
    }
    return vertex;
}

std::vector<int> dijkstra(const std::vector<std::vector<int>> &graph, std::vector<bool> &visited, std::vector<int> &distance, const unsigned startVertex)
{
    std::vector<int> path(graph.size(), -1);
    int n = graph[0].size();

    distance[startVertex] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        int u = findNextVertex(visited, distance);

        visited[u] = true;

        for (int v = 0; v < n; ++v)
        {
            if (!visited[v] && graph[u][v] && distance[v] > (distance[u] + graph[u][v]))
            {
                distance[v] = distance[u] + graph[u][v];
                path[v] = u;
            }
        }
    }
    return path;
}

void printPath(const std::vector<int> path, const int pos)
{
    if (path[pos] == - 1)
        return;
   
    printPath(path, path[pos]);
   
    printf(" --> %d ", pos);
}

int main(int argc, char *argv[])
{

    unsigned vertex = 6;
    std::vector<std::vector<int>> graph = {
        {0, 5, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 2},
        {0, 2, 0, 0, 0, 0},
        {0, 1, 3, 0, 0, 0},
        {0, 0, 0, 1, 2, 0}
    };

    std::vector<bool> visited(vertex, false);
    std::vector<int> distance(vertex, INT32_MAX);

    int start = 5;
    int end = 1;
    std::vector<int> path = dijkstra(graph, visited, distance, start);
    
    for(size_t i = 0; i < distance.size(); ++i)
    {
        if(end == (int)i)
        {
            if(distance[i] == INT32_MAX) {std::cerr << "no road from " << start << " to " << end << std::endl; break;}
            std::cout << start << "-->" << i << " : " << distance[i] << "   Path : " << start;
            printPath(path, i); std::cout << std::endl;
        }

    }

    return EXIT_SUCCESS;
}
