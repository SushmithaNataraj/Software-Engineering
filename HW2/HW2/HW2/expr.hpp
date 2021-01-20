//
//  expr.hpp
//  HW2
//
//  Created by Sushmitha on 1/20/21.
//  Copyright © 2021 Sushmitha. All rights reserved.
//

#ifndef expr_hpp
#define expr_hpp

#include <string>

class Expr{
public:
    virtual bool equals(Expr *e);
};

class Number : public Expr{
public:
    int val;
    
    Number(int val);
    bool equals(Expr *e);
};

class Add : public Expr{
public:
    Expr *lhs;
    Expr *rhs;
    Add(Expr *lhs, Expr *rhs);
    bool equals(Expr *e);
};

class Mult : public Expr{
public:
    Expr *lhs;
    Expr *rhs;

    Mult(Expr *lhs, Expr *rhs);
    bool equals(Expr *e);
};

#endif /* expr_hpp */
