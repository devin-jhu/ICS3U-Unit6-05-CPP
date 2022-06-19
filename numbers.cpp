// Copyright (C) 2022 Devin Jhu All rights reserved
//
// Created by Devin Jhu
// Created on June 2022
// The average

#include <iostream>
#include <list>
#include <cmath>
#include <string>


float FindAverage(std::list<float> gradeList) {
    // this function calculates the average

    float total = 0;
    float average;
    std::list<int> listSize;

    for (int grade : gradeList) {
        total += grade;
    }

    average = total / gradeList.size();

    return average;
}


int main() {
    // this function gets input then shows the average
    std::list<float> gradeList;
    std::string markString;
    int mark;
    int outputFix = 0;  // meant to prevent unnecessary output
    float average;

    std::cout <<
    "This program calculates your average mark. Enter -1 to stop.\n"
    << std::endl;

    // input
    while (true) {
        std::cout << "Enter a mark (%): ";
        std::cin >> markString;
        try {
            mark = std::stoi(markString);
            if (mark == -1) {
                break;
            } else if (mark < 0) {
                std::cout << "not a number" << std::endl;
                outputFix += 1;
                break;
            }
            gradeList.push_back(mark);
        } catch (std::invalid_argument) {
            std::cout << "not a number" << std::endl;
            outputFix += 1;
            break;
        }
    }

    // output
    if (outputFix == 0) {  // only runs if fix has been left at 0
         average = FindAverage(gradeList);
         std::cout << "\nThe average is " << average << "%." << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}
