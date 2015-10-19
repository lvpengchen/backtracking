//
//  main.cpp
//  homework3
//
//  Created by Pengchen Lyu on 10/18/15.
//  Copyright (c) 2015 Pengchen Lyu. All rights reserved.
//

#include <iostream>
#include "jobs.h"

using namespace std;

void print(Assignment solution){
//    cout << "Name  " << "Job1  " << "Job2" << endl;
//    if (<#condition#>) {
//        <#statements#>
//    }
}

void backTrack(JobsPuzzle jobsPuzzle){
    if (jobsPuzzle.getAssignment().jobAllocatedComplete()) {
        print(jobsPuzzle.getAssignment());
    }
    PeopleName var = jobsPuzzle.variableSelect();
    if (var == PeopleName(-1)) {
        return;
    }
    for (int i =1; i<=8; i++) {
        for (int j = i+1; j<=8; j++) {
            Assignment partial = jobsPuzzle.getAssignment();
            partial.assignment[PeopleName(var)][0] = Jobs(i);
            partial.assignment[PeopleName(var)][1] = Jobs(j);
            if (JobsPuzzle::consistency(partial)) {
                JobsPuzzle jobsPuzzle_new;
                jobsPuzzle_new.setAssignment(partial);
                backTrack(jobsPuzzle_new);
            }
        }
    }
}




int main(int argc, const char * argv[]) {
    JobsPuzzle jobsPuzzle;
    backTrack(jobsPuzzle);
}



