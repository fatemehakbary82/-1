#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>

class Graph {
private:
    std::unordered_map<int, std::list<int>> adjList;

public:
    void addVertex(int v) 
    {
        adjList[v] = std::list<int>();
    }

    void addEdge(int v1, int v2) 
    {
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }

    void removeEdge(int v1, int v2) 
    {
        adjList[v1].remove(v2);
        adjList[v2].remove(v1);
    }

    void removeVertex(int v) 
    {
        adjList.erase(v);
        for (auto& it : adjList) 
        {
            it.second.remove(v);
        }
    }

    void bfs(int start) 
    {
        std::queue<int> q;
        std::unordered_map<int, bool> visited;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) 
        {
            int v = q.front();
            q.pop();
            std::cout << v << " ";

            for (auto& neighbor : adjList[v]) 
            {
                if (!visited[neighbor]) 
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void dfs(int start) 
    {
        std::stack<int> stk;
        std::unordered_map<int, bool> visited;

        stk.push(start);

        while (!stk.empty()) 
        {
            int v = stk.top();
            stk.pop();

            if (!visited[v]) 
            {
                std::cout << v << " ";
                visited[v] = true;

                for (auto& neighbor : adjList[v]) 
                {
                    if (!visited[neighbor]) 
                    {
                        stk.push(neighbor);
                    }
                }
            }
        }
    }
};
