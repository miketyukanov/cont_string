//
//  test_templates.cpp
//  cont_string
//
//  Created by Mike Tyukanov on 05.02.2023.
//
#include <iostream>

#include "test_templates.hpp"

using namespace std;

template<typename T> class ourclass
{
public:
    T a[3];
    T getbyIndex(int index);
};


template<typename T>
T ourclass<T>::getbyIndex(int index)
{return a[index];}
template<typename T>
void swap(ourclass<T> &l, ourclass<T> &r)
{
    ourclass<T> tmp=l;
    l=r;
    r=tmp;
    cout<<"Specialized swap for ourclass was called"<<endl;
}

template<typename T>
void swap(T& l, T&r)
{
    T tmp=l;
    l=r;
    r=tmp;
    cout<<"Local swap was called"<<endl;
}
void test_swaps(void)
{
    string sHi="Hi";
    string sBye="Bye";
    cout << "Before swap sHi="<<sHi<<" SBye="<<sBye<<endl;
    swap(sHi,sBye);
    cout << "After swap sHi="<<sHi<<" SBye="<<sBye<<endl;
 
    ourclass<string> ocs = {"Hi", "Bye", "End"};
    ourclass<string> ocs2 = {"Moin", "Tschuss", "Ende"};
    cout<<"Before swap ocs = ";
    for (auto &s : ocs.a)
    {
        cout << s << " ";
    }
    cout<< endl;
    
    swap(ocs, ocs2);
    
    cout<<"After swap ocs = ";
    for (auto &s : ocs.a)
    {
        cout << s << " ";
    }
    cout<< endl;


}

