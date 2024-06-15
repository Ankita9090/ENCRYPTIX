#include <iostream>
using namespace std;

int main() {
   
      double n1,n2;
      char operation;
      
      cout<<"     SIMPLE CALCULATOR"<<endl;
      cout<<"enter the first number:";
      cin>>n1;
      cout<<"enter the second number:";
      cin>>n2;
      
      cout<<"choose operation"<<endl;
      cout<<"(+,-,*,/):";
      cin>>operation;
      
      switch(operation)
      {
          case '+':
          cout<<"addition of two number"<<n1+n2<<endl;
          break;
          case '-':
          cout<<"substaction of two number"<<n1-n2<<endl;
          break;
          case '*':
          cout<<"multiplication of two number"<<n1*n2<<endl;
          break;
          case '/':
          if(n2==0){
              cout<<"error:division by zero is not allowed"<<endl;
              }
          cout<<"division of two number"<<n1/n2<<endl;
          break;
          default:
          cout<<"operation does not exist, please choose valid  operation"<<endl;
      
          
      }
      
    return 0;
}