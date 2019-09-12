#include <bits/stdc++.h>
#include "parkings/ParkingA.h"
#include "parkings/ParkingB.h"

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int initialParks;
    cin >> initialParks;

    int fMin;
    cin >> fMin;

    int fMax;
    cin >> fMax;

    auto parkingA = new ParkingA(initialParks, fMin, fMax);
    int dMaxA = 0;

    auto parkingB = new ParkingB(initialParks, fMin, fMax);
    int dMaxB = 0;

    while(true) {
        string operation;
        cin >> operation;

        if(operation == "END") {
            break;
        }

        string plate;
        cin >> plate;

        ParkedCar* carA = ParkedCar::buildInvalidCar();
        ParkedCar* carB = ParkedCar::buildInvalidCar();

        if(operation == "IN") {
            carA = parkingA->insert(plate);
            carB = parkingB->insert(plate);
        } if (operation == "SCH") {
            carA = parkingA->search(plate);
            carB = parkingB->search(plate);
            if(carA->distance > dMaxA) {
                dMaxA = carA->distance;
            }
            if(carB->distance > dMaxB) {
                dMaxB = carB->distance;
            }
        } else if (operation == "OUT") {
            carA = parkingA->remove(plate);
            carB = parkingB->remove(plate);
        }

        cout << carA->position << " " << carA->distance << " " << carB->position << " " << carB->distance << endl;
    }

    cout << dMaxA << " " << dMaxB << endl;
    return 0;
}