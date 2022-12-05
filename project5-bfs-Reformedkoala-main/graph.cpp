/*
 * graph.cpp
 *
 * Method definitions for the graph class.
 *
 * Author: <your name here>
 */

#include "graph.h"
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

graph::graph(int vertex_count){
    numVertices = vertex_count;
    adjacencyList.resize(numVertices);
    visited.resize(numVertices);
}

void graph::add_edge(int from, int to){
    adjacencyList[from].push_back(to);
}

vector<int> graph::find_shortest_path(int from, int to){
    vector<int> shortestPath;
    queue<int> queue;
    graph P(numVertices);
    for(unsigned int i = 0; i < visited.size(); i++){
        visited[i] =  false;
    }
    int u;
    int dest = to;
    
    visited[from] = true;
    queue.push(from);


    while(queue.empty() != true && visited[dest] == false){
        u = queue.front();
        queue.pop();
        for(unsigned int w = 0; w < adjacencyList[u].size(); w++){
            if(visited[adjacencyList[u][w]] == false){
                queue.push(adjacencyList[u][w]);
                visited[adjacencyList[u][w]] = true;
                P.add_edge(adjacencyList[u][w], u);
            }
            
        }
        
    }
    if(visited[dest] == true){
        shortestPath.push_back(dest);
        while(dest != from){
            dest = P.adjacencyList[dest][0];
            shortestPath.push_back(dest);
        }

    }
    reverse(shortestPath.begin(), shortestPath.end());

    return shortestPath;
}