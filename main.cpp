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

        stringstream stream;
        stream << asm_file.rdbuf();
        string str = stream.str();

        if(str.find(".data") == 0 || str.find(".data")) // If there is a data segment, we shall start parsing from .data. Since there's a .data, there NEEDS to be a .text
        {
            string line = str.substr(str.find(".data"), str.find(".text"));
        }
        if(str.find(".text") == 0 || str.find(".text")) // If there is a text segment, we shall start parsing from .text
        {
            string textSegment = str.substr(str.find(".text"));
            
            stringstream text(textSegment);
            string tok;
            while(getline(text, tok, '\n')) // Tokenize each line with the newline character.
            {
                stringstream line(tok);
                while(getline(line, tok, ' ')) // Tokenize each
                {
                    cout << tok << endl;
                }
            }
        }
    }
    return 0;
}