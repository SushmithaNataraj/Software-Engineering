//
//  expr.cpp
//  HW2
//
//  Created by Sushmitha on 1/20/21.
//  Copyright © 2021 Sushmitha. All rights reserved.
//

#include "expr.hpp"
#include "catch.hpp"

Number::Number(int val){
    this->val = val;
}

bool Number::equals(Expr *e){
    Number *num = dynamic_cast<Number*>(e);
    if(num == NULL)
        return false;
    else return val == num->val;
}

Add::Add(Expr *lhs, Expr *rhs){
    this->lhs = lhs;
    this->rhs = rhs;
}

bool Add::equals(Expr *e){
    Add *add_ptr = dynamic_cast<Add*>(e);
    if(add_ptr == NULL)
        return false;
    else return (lhs->equals(add_ptr->lhs) && rhs -> equals(add_ptr->rhs));
}

Mult::Mult(Expr *lhs, Expr *rhs){
    this->lhs = lhs;
    this->rhs = rhs;
}

bool Mult::equals(Expr *e){
    Mult *mult_ptr = dynamic_cast<Mult*>(e);
    if(mult_ptr == NULL)
        return false;
    else return (lhs->equals(mult_ptr->lhs) && rhs -> equals(mult_ptr->rhs));
}

TEST_CASE("equals"){
    CHECK((new Number(5))-> equals(new Number(5)));
}
