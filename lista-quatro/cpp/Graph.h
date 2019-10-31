//
// Created by jpedroh on 30/10/2019.
//

#ifndef CPP_GRAPH_H
#define CPP_GRAPH_H

#include <bits/stdc++.h>

using namespace std;

class Graph {
public:
    int insertProcess(const string &process, string resource) {
        processResources[process].emplace_back(resource);

        if(this->vertices[resource].empty()) {
            this->insertEdge(resource, process);
            return 0;
        }

        this->resourceQueue[resource].emplace_back(process);
        this->insertEdge(process, resource);
        return this->resourceQueue[resource].size();
    }

    pair<int, int> terminateProcess(const string& process) {
        int queuesRemovidas = this->vertices[process].size();
        int freedResources = 0;

        // REMOVEMOS DAS FILAS ATUAIS
        for(const auto& resource: processResources[process]) {
            this->resourceQueue[resource].remove(process);
            this->vertices[resource].remove(process);

            if(this->vertices[resource].empty()) {
                freedResources++;
            }

            if(!this->resourceQueue[resource].empty() && this->vertices[resource].empty()) {
                auto newProcess = *(this->resourceQueue[resource].begin());
                this->insertEdge(resource, newProcess);
                this->vertices[newProcess].remove(resource);
                this->resourceQueue[resource].pop_front();
            }
        }

        this->vertices[process].clear();
        processResources[process].clear();
        return pair<int, int>(freedResources, queuesRemovidas);
    }

    bool hasDeadLock(const string& process) {
        unordered_map<string, int> colors;
        return dfs_visit(process, colors);
    }

private:
    unordered_map<string, list<string>> vertices;
    unordered_map<string, list<string>> resourceQueue;
    unordered_map<string, list<string>> processResources;

    int insertEdge(string u, string v) {
        this->vertices[u].push_back(v);
        return this->vertices[u].size();
    }

    bool dfs_visit(const string &vertice, unordered_map<string, int> colors) {
        colors[vertice] = 1;
        auto edges = this->vertices[vertice];
        for(const auto& iter : edges) {
            if (colors[iter] == 1) {
                return true;
            }
            if(colors[iter] == 0 && dfs_visit(iter, colors)) {
                return true;
            }
        }
        colors[vertice] = 2;
        return false;
    }
};



#endif //CPP_GRAPH_H
