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
    int input_idx = 0;

    vector<char> memory(MAX_MEMORY_SIZE, 0);
    int idx = 0;

    int depth_count = 0;

    for(int code_idx = 0; code_idx < code.length(); code_idx++){
        switch(code[code_idx]){
        case '>':
            idx++;
            if(idx == code.length()) idx = 0;
            break;

        case '<':
            if(idx == 0) idx = code.length();
            idx--;
            break;

        case '+':
            memory[idx]++;
            break;

        case '-':
            memory[idx]--;
            break;

        case ',':
            memory[idx] = input[input_idx];
            input_idx++;
            break;

        case '.':
            putchar(memory[idx]);
            break;

        case '[':
            if(memory[idx] == 0){
                depth_count = 0;
                while(true){
                    if(code[code_idx] == '['){
                        depth_count++;
                    }else if(code[code_idx] == ']'){
                        depth_count--;
                        if(depth_count == 0){
                            break;
                        }
                    }
                    code_idx++;
                    if(code_idx >= code.length()){
                        cout << endl << "syntax error: ']' corresponding to '[' was not found. Check the correspondence between '[' and ']'." << endl;
                        return 0;
                    }
                }
            }
            break;

        case ']':
            depth_count = 0;
            while(true){
                if(code[code_idx] == ']'){
                    depth_count++;
                }else if(code[code_idx] == '['){
                    depth_count--;
                    if(depth_count == 0){
                        break;
                    }
                }
                code_idx--;
                if(code_idx < 0){
                    cout << endl << "syntax error: '[' corresponding to ']' was not found. Check the correspondence between '[' and ']'." << endl;
                    return 0;
                }
            }
            code_idx--;
            break;

        default:
            break;
        }
    }

    return 0;
}
