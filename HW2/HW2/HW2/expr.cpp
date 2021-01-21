//
//  expr.cpp
//  HW2
//
//  Created by Sushmitha on 1/20/21.
//  Copyright © 2021 Sushmitha. All rights reserved.
//

#include "expr.hpp"
#include "catch.hpp"
#include <iostream>
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

Variable::Variable(std::string name) {
  this->name = name;
}

bool Variable::equals(Expr *e) {
  Variable *var = dynamic_cast<Variable*>(e);
  if (var == NULL)
    return false;
  else
    return name == var->name;
}

TEST_CASE("equals"){
    CHECK((new Number(5))-> equals(new Number(5)));
    CHECK((new Variable("MSD"))->equals(new Variable("MSD")));
    CHECK( ! (new Number(1))->equals(new Number(5)) );
    CHECK( ! (new Mult(new Number(4), new Number(5))) -> equals(new Number(20)) );
}
