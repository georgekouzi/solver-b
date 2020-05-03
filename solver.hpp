#include <iostream>
#include <complex>
#include <math.h>
using namespace std;

 namespace solver{

class RealVariable {

private:
    double _a;
    double _b;
    double _c;
    double _num_rg;
public:

 RealVariable (const double& num_rg=0.0 ,const double& c=0.0,const double& b= 1.0,const double& a= 0.0):_num_rg(num_rg),_c(c), _b(b), _a(a) {
    
    }
    
	double a() const {
		return _a;
	}

	double b() const {
		return _b;
	}
    
    double c() const {
		return _c;
	}

    double num_rg() const {
		return _num_rg;
	}


//op -
       RealVariable operator-(double num)  {
        return RealVariable(_num_rg,_c-num,_b,_a);
     }
    
    friend   RealVariable operator-(double num, const RealVariable& t){
    return RealVariable(t._num_rg,t._c+num,-t._b,t._a);
  }
  friend const  RealVariable operator- ( const RealVariable &t, const RealVariable& t1);
//op+
friend   const RealVariable operator+(double num, const RealVariable& t){
return RealVariable(t._num_rg,t._c+num,t._b,t._a);
  }
   
   friend  RealVariable operator+(const RealVariable& t, double num ){
return RealVariable(t._num_rg,t._c+num,t._b,t._a);

   }

friend const  RealVariable operator+ ( const RealVariable& t, const RealVariable& t1);
//op*
  friend   RealVariable operator*(double num, const RealVariable& t);
//op/
friend RealVariable operator/(const RealVariable& t ,double num);
//op==

friend  RealVariable operator==(const RealVariable& t, double num){
          return RealVariable(0,t._c-num,t._b,t._a);
   }

friend  RealVariable operator==(double num, const RealVariable& t){
                return RealVariable(0,t._c-num,t._b,t._a);
   }

friend  RealVariable operator==(const RealVariable& t,const RealVariable& t1){
          return RealVariable(0,t._c-t1._c,t._b-t1._b,t._a-t1._a);
   }

//op^
friend  RealVariable operator^(const RealVariable& t, int num);
};

class ComplexVariable{
private:
    double _a;
    double _b;
    double _c;
    double _num_rg;
    double _i;
public:

    ComplexVariable (const double& num_rg=0.0 ,const double& c=0.0,const double& b= 1.0,const double& a= 0.0,const double& i= 0.0):_num_rg(num_rg),_c(c), _b(b), _a(a),_i(i) {
    
    }
    
	double a() const {
		return _a;
	}

	double b() const {
		return _b;
	}
    
    double c() const {
		return _c;
	}
  double num_rg() const {
		return _num_rg;
	}
  double i() const {
		return _i;
	} 
//op -
 ComplexVariable operator-(double num)  {
        return ComplexVariable(_num_rg,_c-num,_b,_a,_i);
     }
        friend   ComplexVariable operator-(double num, const ComplexVariable& t){
    return ComplexVariable(t._num_rg,t._c+num,-t._b,t._a,t._i);
  }
  friend const  ComplexVariable operator- ( const ComplexVariable &t, const ComplexVariable& t1);
//op+
friend   ComplexVariable operator+(double num,const  ComplexVariable& t){
return ComplexVariable(t._num_rg,t._c+num,t._b,t._a,t._i);
  }
   
   friend  ComplexVariable operator+(const ComplexVariable& t, double num ){
return ComplexVariable(t._num_rg,t._c+num,t._b,t._a,t._i);
   }

friend const  ComplexVariable operator+ ( const ComplexVariable& t, const ComplexVariable& t1);
//op*
  friend   ComplexVariable operator*(double num, const ComplexVariable& t);
//op/
friend ComplexVariable operator/(const ComplexVariable& t ,double num);
//op==

friend  ComplexVariable operator==(const ComplexVariable& t, double num){
          return ComplexVariable(0,t._c-num,t._b,t._a,t._i);
   }

friend  ComplexVariable operator==(double num, const ComplexVariable& t){
          return ComplexVariable(0,t._c-num,t._b,t._a,t._i)   ;
   }

friend   ComplexVariable operator==(const ComplexVariable& t,const ComplexVariable& t1){
          return ComplexVariable(0,t._c-t1._c,t._b-t1._b,t._a-t1._a,t._i-t1._i)   ;
   }

//op^
friend const   ComplexVariable operator^(const ComplexVariable& t, int num);

 friend const  ComplexVariable operator+ ( const ComplexVariable &t, std::complex<double>num){
        return   ComplexVariable(t._num_rg,t._c,t._b,t._a,t._i+num.imag());

    }

};

double solve(const  RealVariable&t);
complex<double> solve(const ComplexVariable&t);

};