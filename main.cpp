#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

int main() {

    ifstream asm_file;
    asm_file.open("sample.asm");
    string line;

    if(asm_file.is_open())
    {
        cout << "Sucess\n";
        // while(std::getline(asm_file, line))
        // {
        //     istringstream stream(line);
        //     string token;
        //     // while(getline(stream, token, ' '))
        //     // {
                
                
        //     // }
        // }

        stringstream stream;
        stream << asm_file.rdbuf();
        string str = stream.str();
        if(str.find(".text"))
        {
            cout << "Found" << endl;
        }
    }
    return 0;
}