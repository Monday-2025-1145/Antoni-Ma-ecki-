#include <iostream>

using namespace std;


//zad 1
class Pojazd{
    public:
       virtual void przyspiesz(){
            cout<<"Przyspieszam !!!"<<endl;
        }
        void zatrzymaj(){
            cout<<"hamujeeee"<<endl;
        }    
        virtual ~Pojazd(){cout<<"koniec przejazdzki"<<endl;} 
};

class Rower: public Pojazd{
    public:
        void przyspiesz(){
                cout<<"Przyspieszam  roweeeer!!!"<<endl;
        }
};

class Samochod: public Pojazd{
    public:
        void przyspiesz(){
                cout<<"Przyspieszam  samochodzik!!!"<<endl;
        }
};

//zad2
class Pojazd2{
    public:
       virtual void przyspiesz(){
            cout<<"Przyspieszam !!!"<<endl;
       }
        virtual ~Pojazd2(){cout<<"koniec przejazdzki"<<endl;} 
};
class Rower2: public Pojazd2{
    public:
        void przyspiesz(){
                cout<<"Przyspieszam  roweeeer!!!"<<endl;
        }
};

class Samochod2: public Pojazd2{
    public:
        void przyspiesz(){
                cout<<"Przyspieszam  samochodzik!!!"<<endl;
        }
};

//zad3 metody już podają specyficzne dla siebei komunikaty w powyższych zadaniach
//zad 5
class Pojazd5{
    protected:
        string marka= "super" ;
        string model= "wowowo";
};
class Samochod5: protected Pojazd5{
    public:
    void Display(){
        cout<<marka<<" "<<model<<endl; 
    }

};
//zad6
class Pojazd6{
    private:
        string marka= "super" ;
        string model= "wowowo";
};
class Samochod6: private Pojazd6{
    public:
    void Display(){
     //   cout<<marka<<" "<<model<<endl; 
    }

};
//zad7
 class Silnikowy{
    public:
        void przyspiesz(){
            cout<<"ziuuu"<<endl;
        } 
};
class Elektryczny{
    public:
    void ladowanie(){
        cout<<"kabooom"<<endl; 
    }

};
class Hybryda: public Silnikowy, public Elektryczny{

};
//zad 9
class Pojazd9{
    public:
       virtual void przyspiesz(){
            cout<<"Przyspieszam !!!"<<endl;
       }
       void hamuj(){    
        cout<<"Piiiisk"<<endl;
       }
        virtual ~Pojazd9(){cout<<"koniec przejazdzki"<<endl;} 
};
class Samochod9: public Pojazd9{
};
class ElektrycznySamochod9: public Samochod9{
    public:
        void przyspiesz() {
            cout<<"jestem szybki "<<endl;
        }   
};

class Pojazd10{
    public:
       virtual void przyspiesz(){
            cout<<"Przyspieszam !!!"<<endl;
       }
       void hamuj(){    
        cout<<"Piiiisk"<<endl;
       }
        virtual ~Pojazd10(){cout<<"koniec przejazdzki"<<endl;} 
};
class Silnikowy10: virtual public Pojazd10{
};
class Elektryczny10: virtual public Pojazd10{
    public:
        void przyspiesz() {
            cout<<"jestem szybki "<<endl;
        }   
};

class Hybryda10: public Silnikowy10, public Elektryczny10{

};

int main(){
    Pojazd9 p;
    ElektrycznySamochod9 e;
    p.przyspiesz();
    e.przyspiesz();

    return 0;
}