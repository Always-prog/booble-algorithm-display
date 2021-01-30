#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;


string draw_lines(int lines_count){
    string line = "";
    std::cout << line;
    for(int i=0;i<lines_count;i++){
        line = line+"=";
    };
    line = line+"+";
    std::cout << line+"\n";
    return "";
}
int main() {
    int nums[15] = {};
    int size = sizeof(nums)/sizeof(*nums);
    for (int i=0;i<size;i++){
        nums[i] = rand()%20;
    }
    int save_variable = 0;
    
    for (int i=0;i<size-1;i++){
        for (int j=0;j < size - i - 1;j++){
            if (nums[j] > nums[j+1]){
                save_variable = nums[j];
                nums[j] = nums[j+1]; 
                nums[j+1] = save_variable;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
            std::cout << "\x1B[2J\x1B[H";
            for (int i=0;i<sizeof(nums)/sizeof(*nums);i++){std::cout << draw_lines(nums[i]);}

        }


    }
    
    
    
    
    return 0;
}