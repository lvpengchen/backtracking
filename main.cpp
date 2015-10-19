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
    string jobName[9];
    jobName[0] = "NOT_ASSIGNED";
    jobName[1] = "CHEF";
    jobName[2] = "GUARD";
    jobName[3] = "NURSE";
    jobName[4] = "CLERK";
    jobName[5] = "POLICE_OFFICE";
    jobName[6] = "TEACHER";
    jobName[7] = "ACTOR";
    jobName[8] = "BOXER";
    
    for (int i=0; i<4; i++) {
        if (i==0) {
            cout << "Roberta   " << jobName[(solution.assignment[i][0])] << "     " << jobName[(solution.assignment[i][1])] << endl;
        }
        if (i==1) {
            cout << "Thelma    " << jobName[(solution.assignment[i][0])] << "      " << jobName[(solution.assignment[i][1])] << endl;
        }
        if (i==2) {
            cout << "Steve     " << jobName[(solution.assignment[i][0])] << "     " << jobName[(solution.assignment[i][1])] << endl;
        }
        if (i==3) {
            cout << "Pete      " << jobName[(solution.assignment[i][0])] << "     " << jobName[(solution.assignment[i][1])] << endl;
        }
    }
    cout << "-----------------------------------" << endl;
    
}

void backTrack(JobsPuzzle jobsPuzzle){
    if (jobsPuzzle.getAssignment().jobAllocatedComplete()) {
        
        cout << "Name      " << "Job1      " << "Job2" << endl;
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
    cout << "======================================" << endl;
    backTrack(jobsPuzzle);
    cout << "======================================" << endl;
}



