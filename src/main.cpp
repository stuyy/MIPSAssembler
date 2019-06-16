#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include "Assembler.h"

Assembler * h = new Assembler();

using namespace std;

void assembleLine(string line);
char * getRegister(char * line);

int main() {
    ifstream asm_file;
    asm_file.open("./assembly/sample.asm");
    string line;

    if(asm_file.is_open())
    {
        stringstream stream;
        stream << asm_file.rdbuf();
        string str = stream.str();

        if(str.find(".data") == 0 || str.find(".data")) // If there is a data segment, we shall start parsing from .data. Since there's a .data, there NEEDS to be a .text
        {
            string line = str.substr(str.find(".data"), str.find(".text"));
        }
        if(str.find(".text") == 0 || str.find(".text")) // If there is a text segment, we shall start parsing from .text
        {
            string textSegment = str.substr(str.find(".text")); // Get the substring after '.text'
            
            stringstream text(textSegment);
            string tok;
            while(getline(text, tok, '\n')) // Tokenize each line with the newline character.
            {
                stringstream line(tok);
                if(line.str().length() == 0) // If blank line, skip
                    continue;
                else
                    assembleLine(tok); // Assemble the current line.
            }
        }
    }
    return 0;
}

char * getRegister()
{
    char * tok = strtok(NULL, " ,");
    return tok;
}

void assembleLine(string line)
{
    char * str = (char*) malloc(line.length()+1);
    strcpy(str, line.c_str());
    char * instruction = strtok(str, " ");
    if(strcmp(instruction, "add") == 0)
    {
        cout << "Add instruction" << endl;
        char * token = getRegister();
        cout << "Destination = " << token << endl;
        token = getRegister();
        cout << "Source = " << token << endl;
        token = getRegister();
        cout << "Target = " << token << endl;
    }
    else if(strcmp(instruction, "li") == 0) 
    {
        cout << "Load Immediate Instruction " << instruction << endl;
        char * dest = getRegister();
        int immediate = atoi(getRegister());
        cout << "Dest: " << dest << endl;
        cout << "Immediate: " << immediate << endl;
    }
    else if(strcmp(instruction, "addi") == 0)
    {
        char * dest = getRegister();
        char * target = getRegister();
        int immediate = atoi(getRegister());
        cout << dest << " " << target << " " << immediate << endl;
    }
    else if(strcmp(instruction, "and") == 0)
    {

    }
    else if(strcmp(instruction, ""));
}