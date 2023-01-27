//
//  main.cpp
//  cont_string
//
//  Created by Mike Tyukanov on 27.01.2023.

//  A comment to a lesson from VT's course


#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>

using namespace std;


template <typename T> string cont_2_string(const T& cont)
{
    return string(begin(cont), end(cont));
}


int main(void)
{
    /*
     It was mentioned that there is not direct initialization/conversion
     from a vector<char> to a string.
     While such conversion would be indeed rarely needed (what is a string if
     not an improved vector<char>, who and why would first manipulate a vector
     only to convert it later, if we can do everything vector can directly in the
     string?), it's hard to foresee everything. And the rarer the usage, the easier to
     make stupid mistakes. Such as, seeing that an array has a data() method, attempt to
     use it this way:
     */
    vector<char> vc {'W','e','l','l'};
    string sVeryBad(vc.data());
    cout<<"A very bad string: "<<sVeryBad<<endl;
    /*
     As you can see, not only everything compiles just fine, it probably works just
     fine. And that's the worst: since the vector's memory management probably had
     zeroed the excessive memory, it worked for me every time. But it has "Undefined
     Behavior" for reason. Indeed, it could stop to work any time, just because some
     unrelated code was entered somewhere. Or something. Bet it would stop to work on
     the presentation of a new shiny release.
     */
    
    
    
     /*
     Fortunately,such a piece of code as above is pretty contrived. Probably, if we
     convert a vector to a string, we manipulated it as a vector previously. So, the
     bug would be more obvious:
     */
    vc.push_back('n'); vc.push_back('e'); vc.push_back('s'); vc.push_back('s');
    vc.pop_back(); vc.pop_back(); vc.pop_back(); vc.pop_back();

    string sBad(vc.data());
    cout<<"An obviously bad string: "<<sBad<<endl;

    /*
     An obviously bad string: Wellness\254j
     was my last result, there were some more fanciful and even more obviously
     corrupt strings. So we can find and fix it.
     
     How? Two versions in brief:
     */
    
    //If we'd like to use data(), we use it with size():
    string sWell(vc.data(), vc.size());
    cout<<"A data/size well-formed string: "<<sWell<<endl;
    
    
    //Alternatively, we can use iterators:
    string sIterWell(vc.begin(),vc.end());
    cout<<"An iterator well-formed string: "<<sIterWell<<endl;
    
    /*
     Why iterators? It is much more universal. Yes, a vector has data() and size()
     members, but not every container does. On the contrary, every container (and some
     more container-like entities, like, well, strings) has iterators and begin() and
     end() members. What about good ole C-style arrays? They do not have member
     functions, but library has just, well, functions begin() and end() for them --
     and, of course, for containers and other begin() and end() member-possessing
     classes. With free-standing begin() and end() we can achieve universal approach:
     */
    
    char arr[] {'A','r','r','a','y'};
    vector<char> vec {'V','e','c','t','o','r'};
    list<char> lst {'L','i','s','t'};
    
    string sFromArr(begin(arr),end(arr));
    string sFromVec(begin(vec),end(vec));
    string sFromList(begin(lst),end(lst));
    
    cout<<"\nInitialized via generic std::begin() and std::end() containers:"<<endl;
    cout<<sFromArr<<" "<<sFromVec<<" "<<sFromList<<endl;

    /*
     This universal interface is especially useful when we write templates.
     The cont_2_string template function defined above is trivial and pretty useless,
     but we can use the same approach in really sophisticated cases as well. Now let's
     see if it works in our trivial one:
     */
    
    deque<char> deq {'D','e','q','u','e'};
    forward_list<char> flst {'F','l','i','s','t'};
    auto initlist = {'I','n','i','t','l','i','s','t'};
    
    cout<<"\nInitialized thru generic function:"<<endl;
    cout<<cont_2_string(deq)<<" "<<cont_2_string(arr)<<" "
        <<cont_2_string(flst)<<" "<<cont_2_string(initlist)<<endl;
    
    /*
     So, if the iterator-based approach is so fine, why does data()/size() even exist?
     Why are there multiple ways to do the same thing?
     
     Each way has its strengths. Iterators and begin()/end() functions give conformity,
     but data()/size() give speed.
     
     By default the iterators will copy the data byte by byte,
     while with data()/size() the constructor calls memcpy() --
     "std::memcpy is meant to be the fastest library routine for memory-to-memory copy"
     as it said in its description and we can imagine what precise processor-dependent
     optimization it can do in addition to the brutality of copying "machine word-by machine word" instead of "byte-by-byte".
     Initializations from zero-ended C-strings, btw, are slower too, because they need
     to find the length of the string by strlen(), and only then they can call memcpy.
     We can use similar initialization with a C-style array, btw, and that array doesn't
     need to be zero-ended:
     */
    
    cout<<"From array via sizeof:\n"<<string(arr, sizeof(arr))<<endl;
    
    /*
     But, as you can see, even here we have a little bit different interface, using
     arr, sizeof(arr) instead of vec.data(), vec.size(). It is harder to template. Such
     are tradeoffs: speed vs. conformity
    */
    
    return 0;
 }
