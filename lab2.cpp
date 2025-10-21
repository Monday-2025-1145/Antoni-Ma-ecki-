#include <iostream>

using namespace std;

class Samochod{
    public:
        string marka;
        string model;
        int rokProdukcji;
    //public:
        Samochod(){
            marka="Toyota";
            model="Corolla";
            rokProdukcji=2000;
        }
        Samochod(string o_marka, string o_model, int o_rokProdukcji): marka(o_marka),model(o_model),rokProdukcji(o_rokProdukcji){};
        ~Samochod(){
            cout<<"Destruktor wywolany dla "<<marka<<" "<< model<<endl;
        }
};
class Tablica{
    public:
        int *tab;
        Tablica(){
            tab=new int[10]; 
        }
        Tablica(int komorki){
            tab=new int[komorki]; 
        }
        ~Tablica(){
            delete[] tab;
        }
};  

int main(){
    Tablica x;
    Samochod s1, s2("Zamba", "try", 20003);
    cout<<s1.model<<" "<< s1.marka<<endl;
    cout<<s2.model<<" "<< s2.marka<<endl;





    return 0;

}