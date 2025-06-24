//we generalize our vector of doubles type to a vector or anything type by making it a template and replacing the 
//specific type with the parameter
#include <iostream>
#include <list>
#include "Vector.h"
# include <vector>
#include <complex>



void write(const Vector<std::string>&);   //forward declaration of the function 
void f2(Vector<std::string>&);     //forward declaration for the function
void f2(Vector<char*>&); 
void user(Vector<int>& vi,std::list<double>&, std::vector<std::complex<double>>&);
void user();
void f(const Vector<int>& vec, const std::list<std::string>& lst, int x, const std::string&s);
int main(){
    Vector<int> v(10);
    v[0] = 42;

    Vector<char> vc(200);
    Vector<std::list<int>> vli(45);
    Vector<std::string> vs(17);
    Vector<char*> vs2(17);
    f2(vs);

    Less_than<int> lti(10);
    bool result = lti(5);
    std::cout<<std::boolalpha<<result<<std::endl;

    Less_than<std::string> lts{"Backus"}; //declaring and initializing the functor lts

    void fct(int n, const std:: string & s){
            bool b1 = lti(n);
            bool b2 = lts(s);
            std::cout<<std::boolapha<<b1<<std::endl;
            std::cout<<std::boolalpha<<b2<<std::endl;
    }
    fct(10,"Backus");

    //such function objects like the lti and the lts are used as arguments to algorithms 
    


    bool b1 = lts("s");
    std::cout<<std::boolalpha<<b1<<std::endl;


    Vector<int> v2(10);
    for(int i = 0; i<10; ++i) v2[i] = i+1;
    
    std::list<std::string>lst ={"apple", "banana", "cherry", "date"};
    int x = 5;
    std::string s = "carrot";

    f(v2,lst,x,s);
    return 0;
}

void write(const Vector<std::string> &vs)
{
    for(int i = 0; i!=vs.size();++i)
        std::cout<<vs[i]<<'\n';
}

void f2(Vector<std::string> &vs){
    for(auto& s: vs)
        std::cout<<s<<'\n';
}

void f2 (Vector<char*> &vs){
    for(auto& s: vs)
        std::cout<<s<<'\n';
}
void user (Vector<int>& vi, std::list<double>& Id,std::vector<std::complex<double>>& vc){
   int x = sum(vi,0);
   double d = sum(vi,0.0);
   double dd= sum(Id,0.0);
   auto z = sum(vc,std::complex<double>{});

   std::cout<<"x = "<<x<<"\n";
   std::cout<<"d = "<<d<<"\n";
   std::cout<<"dd = "<<dd<<"\n";
   std::cout<<"z = "<<z<<"\n";
}



void f(const Vector<int>& vec, const std::list<std::string>& lst, int x, const std::string&s)
{
    std::cout<<"number of values less than "<<x<<":"<<count(vec, Less_than<int>{x})<<'\n';
    std::cout<<"number of values less than "<<'s'<<":"<<count(lst,Less_than<std::string>{"s"})<<'\n';
}

// we have to define the Less_than separately from its use . That could be seen as inconvinient. Coonsequently there is 
// a notation for implicitly generatirng function objects

void f2(const Vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s)
{
    std::cout<<"number of values less than "<<x
              <<":"<<count(vec,[&](int a){return a<x;})
              <<'\n';
    std::cout<<"number of values less than"<<'s'
            <<":"<<count(lst,[&](const std::string& a){return a<s;})
            <<'\n';
}

