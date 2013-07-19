//  List.h
//  Assignment4
//
//  Created by brad waier on 7/13/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#ifndef Assignment4_List_h
#define Assignment4_List_h



#include <iostream>
#include <string>

using namespace std;

template <class T>
class List
{
public:
    List();
    ~List();
    void AddItem(T item);
    void OutputAll();
    int GetSize();
    T& GetItem(int index);
    void Resize();
    bool IsAlreadyInList(const T& item);
    
    
private:
    T* m_list;
    int m_size;
    int m_allocated;
    
};

template <class T>
List<T>::List()
{
    m_size = 0;
    m_allocated = 10;
    m_list = new T[ m_allocated ];
}

template <class T>
List<T>::~List()
{
    delete [] m_list;
}

template <class T>
void List<T>::AddItem( T item )
{
    bool question = IsAlreadyInList(item);
    if (question == false)
    {
        
        if (m_size == m_allocated)
        {
            Resize();
            m_list[ m_size ] = item;
            m_size++;
        }
        else if (m_size < m_allocated)
        {
            m_list[m_size] = item;
            m_size++;
        }
    }

}

template <class T>
void List<T>::OutputAll()
{
    for (int i = 0; i < m_size; i++)
    {
        cout << m_list[i] << endl;
    }
}
template <class T>
int List<T>::GetSize()
{
    return m_size;
}

template <typename T>
T& List<T>::GetItem( int index )
{
    return m_list[index];
}

template <class T>
void List<T>::Resize()
{
    
    T* dTempList = new T[m_allocated];
    for (int i = 0; i < m_size; i++)
    {
        dTempList[i] = m_list[i];
        
    }
    m_allocated += 10;
    m_list = new T[m_allocated];
    for (int k = 0; k < m_size; k++)
    {
        m_list[k] = dTempList[k];
    }
    delete [] dTempList;
}

template <class T>
bool List<T>::IsAlreadyInList( const T& item )
{
    bool check = false;
    for (int i = 0; i < m_size; i++)
    {
        if (m_list[i] == item)                //overloaded '==' operator
        {
            check = true;
    
        }
        
    }
    return check;
}



#endif
