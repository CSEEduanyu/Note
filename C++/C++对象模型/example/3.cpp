#include <iostream>
#include <string>
using namespace std;

class X{};
class Y:public virtual X{};
class Z:public virtual X{};
class A: public Y, public Z {};

int main(){
cout<< sizeof(X) <<endl;
cout<< sizeof(Y) <<endl;
cout<< sizeof(Z) <<endl;
cout<< sizeof(A) <<endl;
}
