#include <iostream>
#include <stdlib.h> 
using namespace std;

void createPyramid(int amountRowPyramid) {
    for (int i = 1; i <= amountRowPyramid; i++) {
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
        for (int j = amountRowPyramid; j >= i; j--) {
            cout << j;
        }
        for (int j = amountRowPyramid; j > i; j--) {
            cout << "*";
        }
        cout << "\n";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    int amountRowPyramid = 5;

    switch (argc) {
    case 1: {
        do {
            cout << "enter a job number or non number for close: " << endl;
            cin >> amountRowPyramid;

            // amount in range 6-9
            // so that the Egyptian pyramid does not collapse under its own
            amountRowPyramid = amountRowPyramid % 5 + 5;

            createPyramid(amountRowPyramid);
        } while (!cin.fail());
        break;
    }
    default: {
        if (argc >= 2) {
            for (int i = 1; i < argc; ++i) {
                // amount in range 6-9, argv for insert in terminal
                int operateArg = atoi(argv[i]) % 5 + 5;

                cout << "number of arguments: " << argc << endl;
                cout << "argument " << i << ": " << atoi(argv[i]) << endl;
                createPyramid(operateArg);
            }
            break;
        }
        break;
    }}
}



