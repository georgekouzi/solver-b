#include <iostream>
#include <math.h>
#include "solver.hpp"
using namespace std;
namespace solver{

//////OP-
 const  RealVariable operator- ( const RealVariable &t, const RealVariable& t1){
if (t.num_rg()!=0){
 
 if(t1.b()>=0){
 
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
    return   RealVariable(t1.num_rg(),t.num_rg()-t1.c(),t1.b(),t1.a());
}
}
else if(t1.num_rg()!=0){
    return   RealVariable(t.num_rg(),t.c()-t1.num_rg(),t.b(),t.a());
}

    return   RealVariable(t.num_rg(),t.c()-t1.c(),t.b()-t1.b(),t.a()-t1.a());
}
  
 ///op+
 
const  RealVariable operator+ ( const RealVariable &t, const RealVariable& t1){
    
     
if (t.num_rg()!=0){
    return   RealVariable( t1.num_rg(),t1.c()+t.num_rg(),t1.b(),t1.a());
}
else if(t1.num_rg()!=0){
    return   RealVariable(t.num_rg(),t.c()+t1.num_rg(),t.b(),t.a());
}
 else
         return   RealVariable( t.num_rg(),t.c()+t1.c(),t.b()+t1.b(),t.a()+t1.a());

}
 
// op*
   RealVariable operator*(double num, const RealVariable& t){
  
if(t.a()!=0){
return RealVariable(t.num_rg(),t.c(),t.b(),t.a()+num-1);

}

else
return RealVariable(t.num_rg(),t.c(),t.b()+num-1,t.a());
   }
 
 //op/
 
RealVariable operator/(const RealVariable& t ,double num){
       if(num==0){
             throw invalid_argument("no real solution ");
       }
if(t.a()!=0){
return RealVariable(t.num_rg(),t.c(),t.b(),t.a()/num);

}
else
return RealVariable(t.num_rg(),t.c(),t.b()/num,t.a());
   }
 //op^
  RealVariable operator^(const RealVariable& t, int num){
             if(num!=2){
              throw invalid_argument("no real solution ");
            }
              return RealVariable(t._num_rg,t._c,t._b-1,t._a+1);
             
}
 ///func solve
 double solve(const RealVariable& t){
double resultPluse;
// double resultMinus;
if(t.a()==0&&t.b()==0){
    throw invalid_argument("no real solution ");
}
if(t.a()!=0){
resultPluse=(-t.b()+sqrt(t.b()*t.b()-4*t.a()*t.c()))/(2*t.a());
//resultMinus=(-t.b()-sqrt(t.b()*t.b()-4*t.a()*t.c()))/(2*t.a());
if(isnan(resultPluse)){
    throw invalid_argument("no real solution ");
}
else
return resultPluse;
}
else
resultPluse=(t.c()*-1)/t.b();
return resultPluse;
}
  
  ///////////ComplexVariable////////////
   //////OP-
 const  ComplexVariable operator- ( const ComplexVariable &t, const ComplexVariable& t1){
if (t.num_rg()!=0){
 
  if(t1.b()>=0){
 
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
    return   ComplexVariable(t1.num_rg(),t.num_rg()-t1.c(),t1.b(),t1.a(),t1._i);
}
}
else if(t1.num_rg()!=0){
    return   ComplexVariable(t.num_rg(),t.c()-t1.num_rg(),t.b(),t.a());
}
    return   ComplexVariable(t.num_rg(),t.c()-t1.c(),t.b()-t1.b(),t.a()-t1.a(),t.i());
  }
 ///op+
 
const  ComplexVariable operator+ ( const ComplexVariable &t, const ComplexVariable& t1){
    
if (t.num_rg()!=0){
    return   ComplexVariable( t1.num_rg(),t1.c()+t.num_rg(),t1.b(),t1.a(),t.i());
}
else if(t1.num_rg()!=0){
    return   ComplexVariable(t.num_rg(),t.c()+t1.num_rg(),t.b(),t.a(),t.i());
}
 else
    return   ComplexVariable( t.num_rg(),t.c()+t1.c(),t.b()+t1.b(),t.a()+t1.a(),t.i());

}
 
// op*
   ComplexVariable operator*(double num, const ComplexVariable& t){
if(t.a()!=0){
return ComplexVariable(t.num_rg(),t.c(),t.b(),t.a()+num-1,t.i());
}
else
return ComplexVariable(t.num_rg(),t.c(),t.b()+num-1,t.a(),t.i());
   }
 
 //op/
 
ComplexVariable operator/(const ComplexVariable& t ,double num){
       if(num==0){
             throw invalid_argument("no real solution ");
       }
if(t.a()!=0){
return ComplexVariable(t.num_rg(),t.c(),t.b(),t.a()/num,t.i());

}
else
return ComplexVariable(t.num_rg(),t.c(),t.b()/num,t.a(),t.i());
   }
//op^
 const ComplexVariable operator^(const ComplexVariable& t, int num){
       if(num!=2){
        throw invalid_argument("pow need to be ^2");
       }
       else
      return ComplexVariable(t._num_rg,t._c,t._b-1,t._a+1,t._i);
    
    }


complex<double> solve( const ComplexVariable& t) {
double i=t.i();
double result;
if(t.a()!=0){
result=(-t.b()+sqrt(t.b()*t.b()-4*t.a()*t.c()))/(2*t.a());;

if(isnan(result)){

result=(-t.b()+sqrt((t.b()*t.b()-4*t.a()*t.c())*-1))/(2*t.a());;
i=i+result;
return std::complex<double>(0,i);
}
else{ 
return std::complex<double>(result,i);
}
}
else{
  result=(t.c()*-1)/t.b();
return std::complex<double>(result,i);
}

        }

 
 };
 
 
 
 
 
 
 
 
 
