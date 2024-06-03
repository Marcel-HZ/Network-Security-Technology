#include <iostream>
#include "server.h"
#include "client.h"

using namespace std;

int main() {
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
    return 0;
}
