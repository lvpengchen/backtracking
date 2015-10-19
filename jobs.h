//
//  jobs.h
//  homework3
//
//  Created by Pengchen Lyu on 10/18/15.
//  Copyright (c) 2015 Pengchen Lyu. All rights reserved.
//

#ifndef __homework3__jobs__
#define __homework3__jobs__

#include <stdio.h>
#include <iostream>

#endif /* defined(__homework3__jobs__) */

using namespace std;

enum Jobs{
    NOT_ASSIGNED,
    CHEF,
    GUARD,
    NURSE,
    CLERK,
    POLICE_OFFICE,
    TEACHER,
    ACTOR,
    BOXER
};

enum PeopleName{
    ROBERTA,
    THELMA,
    STEVE,
    PETE
};

struct Assignment{
    Jobs assignment[4][2] = {NOT_ASSIGNED};
    
    bool constraintChecking(PeopleName people, Jobs job){
        if(assignment[people][0] == job || assignment[people][1] == job){
            return true;
        }
        return false;
    }
    
    bool jobAllocatedComplete(){
        for(int i = 0; i<4; i++){
            if(assignment[i][0] == NOT_ASSIGNED || assignment[i][1] == NOT_ASSIGNED){
                return false;
            }
        }
        return true;
    }
    
    bool jobAllocatedPersonally(PeopleName person){
        if(assignment[person][0] == NOT_ASSIGNED || assignment[person][1] == NOT_ASSIGNED){
            return false;
        }
        return true;
    }
};



class JobsPuzzle{
private:
    Assignment currentAssignment;

public:
    JobsPuzzle();
    static bool consistency(Assignment partial);
    static bool cond1(Assignment partial);
    static bool cond2(Assignment partial);
    static bool cond3(Assignment partial);
    static bool cond4(Assignment partial);
    static bool cond5(Assignment partial);
    static bool cond6(Assignment partial);
    static bool cond7(Assignment partial);
    
    PeopleName variableSelect();
    Assignment getAssignment();
    void setAssignment(Assignment assignment);
    
};













