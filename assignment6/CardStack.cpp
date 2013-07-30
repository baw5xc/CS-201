 //  CardStack.cpp
//  Assignment6
//
//  Created by brad waier on 7/20/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#include "CardStack.h"

#include <iostream>
#include <cstdlib>

using namespace std;


Stack::Stack()
{
    m_bottom = NULL;
    m_top = NULL;
    m_size = 0;
    
}

Stack::~Stack()
{
    nodePtr temp;
    while (m_bottom != NULL)
    {
        Pop();
    }
}

void Stack::Push(int value)
{
    nodePtr node = new Node;          //This sets up a new node pointer.
    node->m_data = value;             //initializes new node with passed-in data
    node->m_next = NULL;              //sets new node's nextPtr to NULL
    if (m_bottom == NULL)             //If the bottomPtr is NULL, then we set the top
    {                                 //and bottom pointers equal to the newly created node, and add one 
        m_top = m_bottom = node;      //to the size.
        m_size++;
    }
    else                              //However, if there's already a node in the stack, we make the top
    {                                 //pointer's pointer equal to the new node.
        m_top->m_next = node;         //Then we set the top's nextPtr equal to the node 
        m_top = node;                 //pointer, and increment our size.
        m_size++;
    }
}


void Stack::Pop()
{
    if (m_size == 1)
    {
        delete m_bottom;
        m_bottom = NULL;
        m_size--;
    }
    else if (m_size > 1)
    {
        nodePtr curNode = m_bottom;
        while (curNode->m_next != m_top)
        {
            curNode = curNode->m_next;
        }
        curNode->m_next = NULL;
        delete m_top;
        m_top = curNode;
        m_size--;
    }
}


int Stack::Top()
{
    if (m_top != NULL)
    {
        return m_top->m_data;
    }
}

int Stack::GetSize()
{
    return m_size;
}














