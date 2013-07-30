//  CardStack.h
//  Assignment6
//
//  Created by brad waier on 7/20/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#ifndef Assignment6_CardStack_h
#define Assignment6_CardStack_h

#include <iostream>

using namespace std;

class Stack
{
    
public:
    Stack();
    ~Stack();
    void Push(int value);
    void Pop();
    int Top();
    int GetSize();
    
private:
    typedef struct Node
    {
    public:
        friend class Stack;
    private:
        int m_data;
        Node* m_next;
    } *nodePtr;
   
    int m_size;
    Node* m_top;
    Node* m_bottom;
    
    
};

#endif
