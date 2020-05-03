#include <iostream>
#include <string>

#include <math.h>
#include "solver.hpp"
using namespace std;
namespace solver{

//////OP-
 const  RealVariable operator- ( const RealVariable &t, const RealVariable& t1){
    
      cout<<"friend const  RealVariable operator- ( const RealVariable &t, const RealVariable& t1)"<<endl;
cout<<"t= "<<t<<endl;
cout<<"t1= "<<t1<<endl;
if (t.num_rg()!=0){
 
 cout<<"if " <<RealVariable(t1.num_rg(),t.num_rg()-t1.c(),t1.b(),t1.a())<<endl;
 if(t1.b()>=0){
cout<<"in if on if "<<endl;
 
 if(t1.a()!=0&&t1.b()!=0){
    return   RealVariable(t1.num_rg(),t.num_rg()-t1.c(),-t1.b(),-t1.a());
 }
  else if(t1.a()==0&&t1.b()!=0){
    return   RealVariable(t1.num_rg(),t.num_rg()-t1.c(),-t1.b(),t1.a());
  }
 else if (t1.a()!=0&&t1.b()==0)
     return   RealVariable(t1.num_rg(),t.num_rg()-t1.c(),t1.b(),-t1.a());

 }
 else{
   cout<<"in else on if "<<endl;
    return   RealVariable(t1.num_rg(),t.num_rg()-t1.c(),t1.b(),t1.a());
}
}

else if(t1.num_rg()!=0){
    cout<< "else if "<<RealVariable(t.num_rg(),t.c()-t1.num_rg(),t.b(),t.a())<<endl;
    return   RealVariable(t.num_rg(),t.c()-t1.num_rg(),t.b(),t.a());
}

else
    cout<< "else"<<RealVariable(t.num_rg(),t.c()-t1.c(),t.b()-t1.b(),t.a())<<endl;
    return   RealVariable(t.num_rg(),t.c()-t1.c(),t.b()-t1.b(),t.a()-t1.a());

  }
 ///op+
 
const  RealVariable operator+ ( const RealVariable &t, const RealVariable& t1){
    
      cout<<"friend const  RealVariable operator+ ( const RealVariable &t, const RealVariable& t1)"<<endl;
cout<<"t= "<<t<<endl;
cout<<"t1= "<<t1<<endl;
// cout<< RealVariable( t1.a(),t1.b(),t1.c()+t.a())<<endl;
if (t.num_rg()!=0){
  cout<<"t.num_rg()!=0"<<endl;
 cout<< RealVariable( t1.num_rg(),t1.c()+t.num_rg(),t1.b(),t1.a())<<endl;

    return   RealVariable( t1.num_rg(),t1.c()+t.num_rg(),t1.b(),t1.a());
}
else if(t1.num_rg()!=0){
  cout<<"t1.num_rg()!=0"<<endl;
  cout<<RealVariable(t.num_rg(),t.c()+t1.num_rg(),t.b(),t.a())<<endl;

    return   RealVariable(t.num_rg(),t.c()+t1.num_rg(),t.b(),t.a());
}
 else
   cout<< "else "<<RealVariable( t.num_rg(),t.c()+t1.c(),t.b()+t1.b(),t.a()+t1.a())<<endl;

         return   RealVariable( t.num_rg(),t.c()+t1.c(),t.b()+t1.b(),t.a()+t1.a());

}
 
// op*
   RealVariable operator*(double num, const RealVariable& t){
    // cout<<num<<endl;

       cout<<"friend   RealVariable operator*(double num, RealVariable& t)"<<endl;
      cout<<"t= "<<t<<endl;
if(t.a()!=0){
    cout<<"new complex= "<< RealVariable(t.num_rg(),t.c(),t.b(),t.a()+num-1)<<endl;
return RealVariable(t.num_rg(),t.c(),t.b(),t.a()+num-1);

}

else
cout<<"new complex= "<< RealVariable(t.num_rg(),t.c(),t.b()+num-1,t.a())<<endl;
return RealVariable(t.num_rg(),t.c(),t.b()+num-1,t.a());
   }
 
 //op/
 
RealVariable operator/(const RealVariable& t ,double num){
       if(num==0){
             throw invalid_argument("no real solution ");

       }
       
       cout<<"friend   RealVariable operator/(const RealVariable& t ,double num)"<<endl;
if(t.a()!=0){
    cout<<"new complex= "<< RealVariable(t.num_rg(),t.c(),t.b(),t.a()/num)<<endl;
return RealVariable(t.num_rg(),t.c(),t.b(),t.a()/num);

}

else
cout<<"new complex= "<< RealVariable(t.num_rg(),t.c(),t.b()/num,t.a())<<endl;
return RealVariable(t.num_rg(),t.c(),t.b()/num,t.a());
   }
 
 ///func solve
 double solve(const RealVariable& t){
double resultPluse;
double resultMinus;
if(t.a()==0&&t.b()==0){
    throw invalid_argument("no real solution ");
}
if(t.a()!=0){
resultPluse=(-t.b()+sqrt(t.b()*t.b()-4*t.a()*t.c()))/(2*t.a());
resultMinus=(-t.b()-sqrt(t.b()*t.b()-4*t.a()*t.c()))/(2*t.a());
cout<<"result= "<< resultPluse<<endl;
if(isnan(resultPluse)){
    throw invalid_argument("no real solution ");
}
else
return resultPluse;
}
else
resultPluse=(t.c()*-1)/t.b();

cout<<"result= "<< resultPluse;

return resultPluse;
}
  
  ///////////ComplexVariable////////////
   //////OP-
 const  ComplexVariable operator- ( const ComplexVariable &t, const ComplexVariable& t1){
    
      cout<<"friend const  ComplexVariable operator- ( const ComplexVariable &t, const ComplexVariable& t1)"<<endl;
cout<<"t= "<<t<<endl;
cout<<"t1= "<<t1<<endl;
if (t.num_rg()!=0){
 
 cout<<"if " <<ComplexVariable(t1.num_rg(),t.num_rg()-t1.c(),t1.b(),t1.a(),t.i())<<endl;
 if(t1.b()>=0){
cout<<"in if on if "<<endl;
 
 if(t1.a()!=0&&t1.b()!=0){
    return   ComplexVariable(t1.num_rg(),t.num_rg()-t1.c(),-t1.b(),-t1.a(),t1._i);
 }
  else if(t1.a()==0&&t1.b()!=0){
    return   ComplexVariable(t1.num_rg(),t.num_rg()-t1.c(),-t1.b(),t1.a(),t1._i);
  }
 else if (t1.a()!=0&&t1.b()==0)
     return   ComplexVariable(t1.num_rg(),t.num_rg()-t1.c(),t1.b(),-t1.a(),t1._i);

 }
 else{
   cout<<"in else on if "<<endl;
    return   ComplexVariable(t1.num_rg(),t.num_rg()-t1.c(),t1.b(),t1.a(),t1._i);
}
}

else if(t1.num_rg()!=0){
    cout<< "else if "<<ComplexVariable(t.num_rg(),t.c()-t1.num_rg(),t.b(),t.a(),t.i())<<endl;
    return   ComplexVariable(t.num_rg(),t.c()-t1.num_rg(),t.b(),t.a());
}

else
    cout<< "else"<<ComplexVariable(t.num_rg(),t.c()-t1.c(),t.b()-t1.b(),t.a(),t.i())<<endl;
    return   ComplexVariable(t.num_rg(),t.c()-t1.c(),t.b()-t1.b(),t.a()-t1.a(),t.i());

  }
 ///op+
 
const  ComplexVariable operator+ ( const ComplexVariable &t, const ComplexVariable& t1){
    
      cout<<"friend const  ComplexVariable operator+ ( const ComplexVariable &t, const ComplexVariable& t1)"<<endl;
cout<<"t= "<<t<<endl;
cout<<"t1= "<<t1<<endl;
// cout<< ComplexVariable( t1.a(),t1.b(),t1.c()+t.a())<<endl;
if (t.num_rg()!=0){
  cout<<"t.num_rg()!=0"<<endl;
 cout<< ComplexVariable( t1.num_rg(),t1.c()+t.num_rg(),t1.b(),t1.a(),t.i())<<endl;

    return   ComplexVariable( t1.num_rg(),t1.c()+t.num_rg(),t1.b(),t1.a(),t.i());
}
else if(t1.num_rg()!=0){
  cout<<"t1.num_rg()!=0"<<endl;
  cout<<ComplexVariable(t.num_rg(),t.c()+t1.num_rg(),t.b(),t.a(),t.i())<<endl;

    return   ComplexVariable(t.num_rg(),t.c()+t1.num_rg(),t.b(),t.a(),t.i());
}
 else
   cout<< "else "<<ComplexVariable( t.num_rg(),t.c()+t1.c(),t.b()+t1.b(),t.a()+t1.a(),t.i())<<endl;

         return   ComplexVariable( t.num_rg(),t.c()+t1.c(),t.b()+t1.b(),t.a()+t1.a(),t.i());

}
 
// op*
   ComplexVariable operator*(double num, const ComplexVariable& t){
    // cout<<num<<endl;

       cout<<"friend   ComplexVariable operator*(double num, ComplexVariable& t)"<<endl;
      cout<<"t= "<<t<<endl;
            cout<<"t= "<<t.c()<<endl;

if(t.a()!=0){
    cout<<"new complex= "<< ComplexVariable(t.num_rg(),t.c(),t.b(),t.a()+num-1,t.i())<<endl;
return ComplexVariable(t.num_rg(),t.c(),t.b(),t.a()+num-1,t.i());

}

else
cout<<"new complex= "<< ComplexVariable(t.num_rg(),t.c(),t.b()+num-1,t.a(),t.i())<<endl;
return ComplexVariable(t.num_rg(),t.c(),t.b()+num-1,t.a(),t.i());
   }
 
 //op/
 
ComplexVariable operator/(const ComplexVariable& t ,double num){
       if(num==0){
             throw invalid_argument("no real solution ");

       }
       
       cout<<"friend   ComplexVariable operator/(const ComplexVariable& t ,double num)"<<endl;
if(t.a()!=0){
    cout<<"new complex= "<< ComplexVariable(t.num_rg(),t.c(),t.b(),t.a()/num,t.i())<<endl;
return ComplexVariable(t.num_rg(),t.c(),t.b(),t.a()/num,t.i());

}

else
cout<<"new complex= "<< ComplexVariable(t.num_rg(),t.c(),t.b()/num,t.a(),t.i())<<endl;
return ComplexVariable(t.num_rg(),t.c(),t.b()/num,t.a(),t.i());
   }



complex<double> solve( const ComplexVariable& t) {
double i=t.i();
double result;
if(t.a()!=0){
result=(-t.b()+sqrt(t.b()*t.b()-4*t.a()*t.c()))/(2*t.a());;

if(isnan(result)){

result=(-t.b()+sqrt((t.b()*t.b()-4*t.a()*t.c())*-1))/(2*t.a());;
i=i+result;
cout<<std::complex<double>(0,i)<<endl;
return std::complex<double>(0,i);
}
else{ 
cout<<std::complex<double>(result,i)<<endl;
return std::complex<double>(result,i);
}
}
else{
  result=(t.c()*-1)/t.b();
cout<<std::complex<double>(result,i)<<endl;
return std::complex<double>(result,i);
}

        }
 
 
 
 
 
 };
 
 
 
 
 
 
 
 
 
