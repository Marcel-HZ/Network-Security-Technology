#include <iostream>
#include "client.h"
#include "server.h"

using namespace std;

int main() {
    cout << "————————【chat start】————————" << endl;
    while(1) {
        cout << "Client or Server?" << endl;
        char cs;
        cin >> cs;
        if (cs == 's') {
            if(server() != 0){
                break;
            }
        }
        else if (cs == 'c') {
            if(client() != 0){
                break;
            }
        }
        else {
            cout << "err input" << endl;
        }
    }
    cout << "————————【chat end】————————" << endl;
    return 0;
}
