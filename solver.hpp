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
         cout<<"ppfffff ---"<<RealVariable(_num_rg,_c-num,_b,_a)<<endl;      
        return RealVariable(_num_rg,_c-num,_b,_a);
     }
    
    friend   RealVariable operator-(double num,  RealVariable& t){
    cout<<RealVariable(t._num_rg,t._c+num,-t._b,t._a)<<endl;
    return RealVariable(t._num_rg,t._c+num,-t._b,t._a);
  }
  friend const  RealVariable operator- ( const RealVariable &t, const RealVariable& t1);
//op+
friend   RealVariable operator+(double num,  RealVariable& t){
  cout<<"friend   RealVariable operator+(double num,  RealVariable& t)"<<endl<<"t= "<<t<<endl<<RealVariable(t._num_rg,t._c+num,t._b,t._a)<<endl;
return RealVariable(t._num_rg,t._c+num,t._b,t._a);
  }
   
   friend  RealVariable operator+(RealVariable& t, double num ){
            cout<<"friend  RealVariable operator+(RealVariable& t, double num )"<<endl;
      cout<<"t= "<<t<<endl;
    cout<<RealVariable(t._num_rg,t._c+num,t._b,t._a)<<endl;
return RealVariable(t._num_rg,t._c+num,t._b,t._a);

   }

friend const  RealVariable operator+ ( const RealVariable& t, const RealVariable& t1);
//op*
  friend   RealVariable operator*(double num, const RealVariable& t);
//op/
friend RealVariable operator/(const RealVariable& t ,double num);
//op==

friend  RealVariable operator==(const RealVariable& t, double num){
       cout<<" friend  RealVariable operator==(const RealVariable& t, double num)"<<endl;
       cout<<"t= "<<t<<endl;
       //cout<<"t1= "<<t1<<endl;
cout<<"new complex= "<<RealVariable(0,t._c+num,t._b,t._a)<<endl;
          return RealVariable(0,t._c-num,t._b,t._a)   ;
   }

friend  RealVariable operator==(double num, const RealVariable& t){
       cout<<"friend  RealVariable operator==(double num, const RealVariable& t)"<<endl;
       cout<<"t= "<<t<<endl;
       //cout<<"t1= "<<t1<<endl;
cout<<"new complex= "<<RealVariable(0,t._c+num,t._b,t._a)<<endl;
          return RealVariable(0,t._c-num,t._b,t._a)   ;
   }

friend   RealVariable operator==(const RealVariable& t,const RealVariable& t1){
       cout<<"friend   RealVariable operator==(const RealVariable& t,const RealVariable& t1"<<endl;
       cout<<"t= "<<t<<endl;
       cout<<"t1= "<<t1<<endl;
       cout<<"new complex= "<<RealVariable(0,t._c-t1._c,t._b-t1._b,t._a-t1._a)<<endl;
          return RealVariable(0,t._c-t1._c,t._b-t1._b,t._a-t1._a)   ;
   }

//op^
friend   RealVariable operator^(RealVariable& t, int num){
    //  cout<<num<<endl;
    //    cout<<"friend   RealVariable operator^(double num, RealVariable& t)"<<RealVariable(t._a,t._b+num-1,t._c)<<endl;
             if(num!=2){
              throw invalid_argument("no real solution ");
             }
         
             else
                  cout<<"friend   RealVariable operator^(RealVariable& t, int num)"<<endl;
                  cout<<"t= "<<t<<endl;
              cout<<"new complex= "<<RealVariable(t._num_rg,t._c,t._b-1,t._a+1)<<endl;
                   return RealVariable(t._num_rg,t._c,t._b-1,t._a+1);
    }
///for check
 friend ostream& operator<< (ostream& os, const RealVariable& c){
               // return (os <<"A= "<< c._a <<", B= " << c._b<<", C= " <<c._c);
               return (os<<"_num_rg= "<<c._num_rg <<", A= "<< c._a <<", B= " << c._b<<", C= " <<c._c);

    }

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
         cout<<"ppfffff ---"<<ComplexVariable(_num_rg,_c-num,_b,_a,_i)<<endl;      
        return ComplexVariable(_num_rg,_c-num,_b,_a,_i);
     }
    
    friend   ComplexVariable operator-(double num,  ComplexVariable& t){
    cout<<ComplexVariable(t._num_rg,t._c+num,-t._b,t._a,t._i)<<endl;
    return ComplexVariable(t._num_rg,t._c+num,-t._b,t._a,t._i);
  }
  friend const  ComplexVariable operator- ( const ComplexVariable &t, const ComplexVariable& t1);
//op+
friend   ComplexVariable operator+(double num,const  ComplexVariable& t){
  cout<<"friend   ComplexVariable operator+(double num,  ComplexVariable& t)"<<endl<<"t= "<<t<<endl<<ComplexVariable(t._num_rg,t._c+num,t._b,t._a,t._i)<<endl;
return ComplexVariable(t._num_rg,t._c+num,t._b,t._a,t._i);
  }
   
   friend  ComplexVariable operator+(const ComplexVariable& t, double num ){
            cout<<"friend  ComplexVariable operator+(ComplexVariable& t, double num )"<<endl;
      cout<<"t= "<<t<<endl;
    cout<<ComplexVariable(t._num_rg,t._c+num,t._b,t._a,t._i)<<endl;
return ComplexVariable(t._num_rg,t._c+num,t._b,t._a,t._i);

   }

friend const  ComplexVariable operator+ ( const ComplexVariable& t, const ComplexVariable& t1);
//op*
  friend   ComplexVariable operator*(double num, const ComplexVariable& t);
//op/
friend ComplexVariable operator/(const ComplexVariable& t ,double num);
//op==

friend  ComplexVariable operator==(const ComplexVariable& t, double num){
       cout<<" friend  ComplexVariable operator==(const ComplexVariable& t, double num)"<<endl;
       cout<<"t= "<<t<<endl;
       //cout<<"t1= "<<t1<<endl;
cout<<"new complex= "<<ComplexVariable(0,t._c+num,t._b,t._a,t._i)<<endl;
          return ComplexVariable(0,t._c-num,t._b,t._a,t._i)   ;
   }

friend  ComplexVariable operator==(double num, const ComplexVariable& t){
       cout<<"friend  ComplexVariable operator==(double num, const ComplexVariable& t)"<<endl;
       cout<<"t= "<<t<<endl;
       //cout<<"t1= "<<t1<<endl;
cout<<"new complex= "<<ComplexVariable(0,t._c+num,t._b,t._a,t._i)<<endl;
          return ComplexVariable(0,t._c-num,t._b,t._a,t._i)   ;
   }

friend   ComplexVariable operator==(const ComplexVariable& t,const ComplexVariable& t1){
       cout<<"friend   ComplexVariable operator==(const ComplexVariable& t,const ComplexVariable& t1"<<endl;
       cout<<"t= "<<t<<endl;
       cout<<"t1= "<<t1<<endl;
       cout<<"new complex= "<<ComplexVariable(0,t._c-t1._c,t._b-t1._b,t._a-t1._a,t._i-t1._i)<<endl;
          return ComplexVariable(0,t._c-t1._c,t._b-t1._b,t._a-t1._a,t._i-t1._i)   ;
   }

//op^
friend const   ComplexVariable operator^(const ComplexVariable& t, int num){
    //  cout<<num<<endl;
    //    cout<<"friend   ComplexVariable operator^(double num, ComplexVariable& t)"<<ComplexVariable(t._a,t._b+num-1,t._c)<<endl;
       if(num!=2){
        throw invalid_argument("pow need to be ^2");
       }
       else
       cout<<"friend   ComplexVariable operator^(ComplexVariable& t, int num)"<<endl;
       cout<<"t= "<<t<<endl;
cout<<"new complex= "<<ComplexVariable(t._num_rg,t._c,t._b-1,t._a+1,t._i)<<endl;
 return ComplexVariable(t._num_rg,t._c,t._b-1,t._a+1,t._i);
       
    

    }
///for check
 friend ostream& operator<< (ostream& os, const ComplexVariable& c){
               // return (os <<"A= "<< c._a <<", B= " << c._b<<", C= " <<c._c);
               return (os<<"_num_rg= "<<c._num_rg <<", A= "<< c._a <<", B= " << c._b<<", C= " <<c._c<<", i= "<<c._i);

    }
 friend const  ComplexVariable operator+ ( const ComplexVariable &t, std::complex<double>num){
   cout<<num.imag()<<endl;
        return   ComplexVariable(t._num_rg,t._c,t._b,t._a,t._i+num.imag());

    }


};
double solve(const  RealVariable&t);
complex<double> solve(const ComplexVariable&t);


};