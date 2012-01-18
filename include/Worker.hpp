/// Zaczynam pracować społecznie, pozdrawiam Paweł Ściegienny
#include <iostream>
#include <string>
#include <sstream>
class Executor{
  public:
      virtual std::string exec(std::string s)=0;
};

class CalkujKwadratoweExecutor: public Executor{
  public:
     virtual std::string exec(std::string s){
          double a, b;
          double A, B, C;
          std::stringstream tmp, res;
          tmp << s;
          tmp >> a;
          tmp >> b;
          tmp >> A;
          tmp >> B;
          tmp >> C;
          double width = (b-a)/1000;
          double f1, f2;
          double wynik = 0;
          for(int i=0; i<1000; ++i){
             f1=A*(a+i*width)*(a+i*width)+B*(a+i*width)+C;
             f2=A*(a+(i+1)*width)*(a+(i+1)*width)+B*(a+(i+1)*width)+C;
             wynik+=width*(f1+f2)/2;
          }
          res << wynik;
          return res.str(); 
     }
};

class Worker{
  public:
      std::string execute(std::string s){
           std::cout << "EXECUTUJE: "<< s << std::endl;
           size_t terminator = s.find(" ");
           std::string tmp = s.substr(0, terminator);
           if(tmp=="calkujKwadratowe"){
               _executor= new CalkujKwadratoweExecutor();
           }
           std::string params = s.substr(terminator+1);
           return _executor->exec(params);
      }
   private:
      Executor* _executor;
};


