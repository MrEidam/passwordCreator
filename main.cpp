#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <fstream>
#include "string"

using namespace std::chrono_literals;
using std::this_thread::sleep_for;

std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-/()[]{}!*?.,'";

int randomGen(int max, int min=1){
    return (std::rand() % (max-min))+min;
}

std::string passwordGen(unsigned int num){
    std::string output;
    for(int i=0; i<num;i++){
        output += letters[randomGen(static_cast<int>(letters.length()),0)];
    }
    return output;
}

int main(){
    std::srand(std::time(0));
    std::ofstream file("password.txt");

    int a;
    std::cout << 
    "\033[32m\033[1m#     #                                                                   \n"
    "#  #  # ###### #       ####   ####  #    # ######                         \n"
    "#  #  # #      #      #    # #    # ##  ## #                              \n"
    "#  #  # #####  #      #      #    # # ## # #####                          \n"
    "#  #  # #      #      #      #    # #    # #                              \n"
    "#  #  # #      #      #    # #    # #    # #                              \n"
    " ## ##  ###### ######  ####   ####  #    # ######                         \n";
    sleep_for(400ms);
    std::cout << 
    "                                                                          \n"
    "#####  ####     ##### #    # ######                                       \n"
    "  #   #    #      #   #    # #                                            \n"
    "  #   #    #      #   ###### #####                                        \n"
    "  #   #    #      #   #    # #                                            \n"
    "  #   #    #      #   #    # #                                            \n"
    "  #    ####       #   #    # ######                                       \n";
    sleep_for(400ms);
    std::cout <<
    "                                                                          \n"
    "######                                                                    \n"
    "#     #   ##    ####   ####  #    #  ####  #####  #####                   \n"
    "#     #  #  #  #      #      #    # #    # #    # #    #                  \n"
    "######  #    #  ####   ####  #    # #    # #    # #    #                  \n"
    "#       ######      #      # # ## # #    # #####  #    #                  \n"
    "#       #    # #    # #    # ##  ## #    # #   #  #    #                  \n"
    "#       #    #  ####   ####  #    #  ####  #    # #####                   \n";
    sleep_for(400ms);
    std::cout <<
    "                                                                          \n"
    " #####                                                #         ###   ### \n"
    "#     # #####  ######   ##   #####  ####  #####      ##        #   #  ### \n"
    "#       #    # #       #  #    #   #    # #    #    # #       #     # ### \n"
    "#       #    # #####  #    #   #   #    # #    #      #       #     #  #  \n"
    "#       #####  #      ######   #   #    # #####       #       #     #     \n"
    "#     # #   #  #      #    #   #   #    # #   #       #   ###  #   #  ### \n"
    " #####  #    # ###### #    #   #    ####  #    #    ##### ###   ###   ### \n"
    "                                                                          \033[0m" << std::endl;
    sleep_for(400ms);
    std::cout << "\033[33mHow long do you want your password to be?\033[31m"<< std::endl;
    std::cin >> a;
    //std::cout << "\033[35m\033[1mHere it is:\033[0m" << std::endl;
    std::string pass = passwordGen(a);
    //std::cout << passwordGen(a) << std::endl;
    std::cout << "\033[36mCreating a file with the password." << std::endl;
    if(file.is_open()){
        file << "This is your generated Password:\n";  // Write to the file
        std::cout << "\033[36mCreating a file with the password.." << std::endl;
        file << pass;
        std::cout << "\033[36mCreating a file with the password..." << std::endl;
        file.close();  // Close the file when done
        std::cout << "File created!" << std::endl;
    }else{
        std::cerr << "Error creating file! Please contact MrEidam ASAP!" << std::endl;
    }
    std::cout << "Program will end after 5s\033[0m" << std::endl;
    sleep_for(5s);
}