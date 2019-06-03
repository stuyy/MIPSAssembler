#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream asm_file;
    asm_file.open("sample.asm");

    if(asm_file.is_open())
    {
        cout << "Sucess\n";
    }
    return 0;
}