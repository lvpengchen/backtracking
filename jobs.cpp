//
//  jobs.cpp
//  homework3
//
//  Created by Pengchen Lyu on 10/18/15.
//  Copyright (c) 2015 Pengchen Lyu. All rights reserved.
//

#include "jobs.h"
#include <iostream>
#include <vector>
JobsPuzzle::JobsPuzzle(){
    
}

bool JobsPuzzle::consistency(Assignment partial){
    bool flag1 = JobsPuzzle::cond1(partial);
    bool flag2 = JobsPuzzle::cond2(partial);
    bool flag3 = JobsPuzzle::cond3(partial);
    bool flag4 = JobsPuzzle::cond4(partial);
    bool flag5 = JobsPuzzle::cond5(partial);
    bool flag6 = JobsPuzzle::cond6(partial);
    bool flag7 = JobsPuzzle::cond7(partial);
    
    if(flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7){
        return true;
    }
    
    return false;
}

bool JobsPuzzle::cond1(Assignment partial){
    vector<Jobs> jobsAssigned;
    for (int i=0; i<4; i++) {
        jobsAssigned.push_back(partial.assignment[i][0]);
        jobsAssigned.push_back(partial.assignment[i][1]);
    }
    
    for (int i=1; i<=8; i++) {
        int count = 0;
        for (int j=0; j<(int)jobsAssigned.size(); j++) {
            if (jobsAssigned[j] == Jobs(i)) {
                count++;
            }
            if (count>=2) {
                return false;
            }
        }
    }
    return true;
}//Four people hold eight different jobs.

bool JobsPuzzle::cond2(Assignment partial){
    if (partial.constraintChecking(ROBERTA, NURSE)||partial.constraintChecking(THELMA, NURSE)) {
        return false;
    }
    return true;
}//The job of nurse is held by a male.

bool JobsPuzzle::cond3(Assignment partial){
    if (partial.constraintChecking(PETE, CHEF)||partial.constraintChecking(STEVE, CHEF)){
        return false;
    }
    else if(partial.constraintChecking(ROBERTA, CLERK)||partial.constraintChecking(THELMA, CLERK)){
        return false;
    }
    return true;
}//The husband of the chef is the clerk.

bool JobsPuzzle::cond4(Assignment partial){
    if (partial.constraintChecking(ROBERTA, BOXER)) {
        return false;
    }
    return true;
}//Roberta is not a boxer.

bool JobsPuzzle::cond5(Assignment partial){
    if (partial.constraintChecking(PETE, NURSE)||partial.constraintChecking(PETE, TEACHER)||partial.constraintChecking(PETE, POLICE_OFFICE)) {
        return false;
    }
    return true;
}//Pete has no education past the ninth grade.

bool JobsPuzzle::cond6(Assignment partial){
    if (partial.constraintChecking(ROBERTA, CHEF)||partial.constraintChecking(ROBERTA, POLICE_OFFICE)) {
        return false;
    }
    return true;
}//Roberta is not a chef or a police officer.

bool JobsPuzzle::cond7(Assignment partial){
    if (partial.constraintChecking(ROBERTA, ACTOR)||partial.constraintChecking(THELMA, ACTOR)){
        return false;
    }
    return true;
}

PeopleName JobsPuzzle::variableSelect(){
    PeopleName variableSelect = PeopleName(0);
    for (int i=0; i<4; i++) {
        if (!currentAssignment.jobAllocatedPersonally(PeopleName(i))){
            variableSelect = PeopleName(i);
            return variableSelect;
        }
    }
    return PeopleName(-1);
}

Assignment JobsPuzzle::getAssignment(){
    return currentAssignment;
}

void JobsPuzzle::setAssignment(Assignment assignment){
    this->currentAssignment = assignment;
}





