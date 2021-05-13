#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_MEMORY_SIZE = 30000;

int main(){
    string code;
    cout << "enter code : ";
    std::getline(cin, code);
    string input;
    cout << "enter input: ";
    std::getline(cin, input);
    int input_ptr = 0;

    vector<char> memory(MAX_MEMORY_SIZE, 0);
    int ptr = 0;

    int depth_count = 0;
    int code_ptr = 0;

    for(char code_ptr = 0; code_ptr < code.length(); code_ptr++){
        switch(code[code_ptr]){
        case '>':
            ptr++;
            if(ptr == code.length()) ptr = 0;
            break;

        case '<':
            if(ptr == 0) ptr = code.length();
            ptr--;
            break;

        case '+':
            memory[ptr]++;
            break;

        case '-':
            memory[ptr]--;
            break;

        case ',':
            memory[ptr] = input[input_ptr];
            input_ptr++;
            break;

        case '.':
            putchar(memory[ptr]);
            break;

        case '[':
            if(memory[ptr] == 0){
                depth_count = 0;
                while(true){
                    if(code[code_ptr] == '['){
                        depth_count++;
                    }else if(code[code_ptr] == ']'){
                        depth_count--;
                        if(depth_count == 0){
                            break;
                        }
                    }
                    code_ptr++;
                    if(code_ptr >= code.length()){
                        cout << endl << "syntax error: ']' corresponding to '[' was not found. Check the correspondence between '[' and ']'." << endl;
                        return 0;
                    }
                }
            }
            break;

        case ']':
            depth_count = 0;
            while(true){
                if(code[code_ptr] == ']'){
                    depth_count++;
                }else if(code[code_ptr] == '['){
                    depth_count--;
                    if(depth_count == 0){
                        break;
                    }
                }
                code_ptr--;
                if(code_ptr < 0){
                    cout << endl << "syntax error: '[' corresponding to ']' was not found. Check the correspondence between '[' and ']'." << endl;
                    return 0;
                }
            }
            code_ptr--;
            break;

        default:
            break;
        }
    }

    return 0;
}
