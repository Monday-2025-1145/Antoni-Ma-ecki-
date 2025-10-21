#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;



class Car{
    private:
        string make="Toyota";
        string model="Corolla";
        int year=2000;
        int currentYear=2025;
    public:
        void DisplayInfo(){
            cout<<make<<" "<<model<<" "<<year<<endl;
        }
        int getCarAge(){
            return (currentYear-year);
        }
        bool isSameCar(Car otherCar){
            if(otherCar.make!=make||otherCar.model!=model||year!=otherCar.year)
                return 0;
            return 1;
        }

};

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

class Parrot{
    private:
        vector <string> words;
    public:
        Parrot(string first_wrd){
            words.push_back(first_wrd);
        }
        void say(int repetitions){
            string word=words[random(0,words.size()-1)];
            for(int i=0;i<repetitions;i++){
                cout<<word<<endl;
            }
        } 
        void setWord(string new_wrd){
            words.push_back(new_wrd);
        }
};


int main(){
    srand(time(nullptr));
    Car c1,c2;
    c1.DisplayInfo();
    cout<<c1.getCarAge()<<endl;
    cout<<c1.isSameCar(c2)<<endl;
    Parrot p1("aga");
    p1.say(3);
    p1.setWord("robot");
    p1.say(2);
    p1.say(2);
    p1.say(2);
    p1.say(2);
    p1.say(2);

    return 0;
}