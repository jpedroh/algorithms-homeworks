#include <bits/stdc++.h>BasesManager
#include "BasesManager.h"
#include "Agent.h"

#define endl '\n'

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalBases, maximumDepth, initialAgentsNumber;
    cin >> totalBases >> maximumDepth >> initialAgentsNumber;

    BasesManager basesManager = new BasesManager(totalBases, maximumDepth);

    while (true) {
        string action;
        cin >> action;

        if (action == "END") {
            break;
        }

        int casta, id, base;
        cin >> casta >> id >> base;
        Agent agent = new Agent(id, casta, base);

        if(action == "ADM") {
            basesManager.insertAgent(agent);
        } else if (action == "SCH") {
            Agent foundAgent = basesManager.searchAgent(agent);
            cout << foundAgent.getDepth() << endl;
        } else if (action == "INF") {
            Agent insertedAgent = basesManager.insertAgent(agent);
            cout << insertedAgent.getBase();
        } else {
            basesManager.removeAgent(agent);
        }
    }

    return 0;
}

