#include <bits/stdc++.h>
#include "Graph.h"

#define endl '\n'

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto *graph = new Graph();

    while(true) {
        string acao;
        cin >> acao;

        if(acao == "END") {
            break;
        } else if (acao == "REQ") {
            string process, resource;
            cin >> process >> resource;
            int positionInQueue = graph->insertProcess(process, resource);
            if(positionInQueue > 0) {
                cout << "WAIT " << positionInQueue << endl;
            } else {
                cout << "AVAIL" << endl;
            }
        } else if (acao == "FRE") {
            string process;
            cin >> process;

            auto removalDetails = graph->terminateProcess(process);
            cout << "TERM " << removalDetails.first << endl;
        } else if (acao == "DLK") {
            string process;
            cin >> process;

            bool hasDeadLock = graph->hasDeadLock(process);
            if(hasDeadLock) {
                auto removalDetails = graph->terminateProcess(process);
                cout << "KILL " << removalDetails.first << " " << removalDetails.second << endl;
            } else {
                cout << "NONE" << endl;
            }
        }
    }
    return 0;
}