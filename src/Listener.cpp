#include "Listener.hpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool Listener::readMove(int& position) const {
    string line;
    while (true) {
        cout << "Alege casuta (1-9) sau q pentru iesire: ";
        if (!getline(cin, line)) {
            return false;
        }

        // Citim o comanda intreaga, ca sa nu acceptam doar cifra din "2abc".
        istringstream words(line);
        string command;
        string extra;
        words >> command;

        if (words >> extra) {
            cout << "Comanda invalida. Introdu o singura casuta.\n";
            continue;
        }
        if (command == "q" || command == "Q") {
            return false;
        }
        if (command.size() == 1 && command[0] >= '1' && command[0] <= '9') {
            position = command[0] - '0';
            return true;
        }
        cout << "Comanda invalida. Introdu o cifra de la 1 la 9.\n";
    }
}
