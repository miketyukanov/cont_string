//
//  member_calls_ctor.cpp
//  cont_string
//
//  Created by Mike Tyukanov on 29.01.2023.
//

#include "member_calls_ctor.hpp"
#include <iostream>
using namespace std;

class Father
{
public:
    void sayAsUsual(void) {cout<<"I usually say:"<<endl; say();}
protected:
    virtual void say(void) {cout << "I am Your Father" << endl;}

};

class Son: public Father
{
public:
protected:
    virtual void say(void) {cout << "\tNooooooo" << endl;}
};

class Vader
{
public:
    Vader() {say();}
    void sayAsUsual(void) {cout<<"I usually say:"<<endl; say();}
protected:
    virtual void say(void) {cout << "I am Your Father" << endl;}

};
class Luke: public Vader
{
protected:
    virtual void say(void) {cout << "\tNooooooo" << endl;}
};

class TalkVader
{
public:
    TalkVader() {cout<<"I'm Vader, in constructor ";sayAsUsual();}
    void sayAsUsual(void) {cout<<"I usually say:"<<endl; say();}
protected:
    virtual void say(void) {cout << "I am Your Father" << endl;}

};
class TalkLuke: public TalkVader
{
public:
    TalkLuke() {cout<<"I'm Luke, in constructor ";sayAsUsual();}

protected:
    virtual void say(void) {cout << "\tNooooooo" << endl;}
};


void member_calls_ctor(void) {
    /*
     You can see statements such as "don't call virtual functions from
     constructors" quite often, but there is no such rule in the standard.
     
     What's wrong with that? We start with a quite common demo of
     polymorphic behavior: virtual functions called from base class's
     non-virtuals
     */
    Father *p_son=new Son;
    p_son->sayAsUsual();
    delete p_son;
    /*
     he says Noooo, because he actually a son even if call him by his father's
     pointer.
     Everything looks OK, polymorphism works, but wouldn't it be better to
     call it right from constructor, and see how polymorphism works here?
     Lets work with our impoved father (Vader)
     */
    Vader *p_luke=new Luke;
    /*
     And Luke says "I'm your father". Something's got really wrong.
     but what would happen if we call the old sayAsUsual?
     */
    p_luke->sayAsUsual();
    delete p_luke;
    /*
    Our old call of virtual from non-virtual still works, maybe it's
    better to call that nonvirtual sayAsUsual from the ctor?
    To make it more clear from here which call comes, we will
     addionally make our classes more talkative
     */
    TalkVader *p_talkLuke=new TalkLuke;
    p_talkLuke->sayAsUsual();
    delete p_talkLuke;
}
