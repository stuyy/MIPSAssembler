#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

void assembleLine(string line);

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
                if(line.str().length() == 0)
                    continue;
                else
                    assembleLine(tok);
                
            }
        }
    }
    return 0;
}

void assembleLine(string line)
{
    char * str = (char*) malloc(line.length()+1);
    strcpy(str, line.c_str());
    char * instruction = strtok(str, " ");
    cout << "Instruction: " << instruction << endl;
}