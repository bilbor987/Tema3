#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>

using namespace std;




template <class T>
class Container{
private:
    T info;

public:
    Container(){};
    Container(const Container& c){
        this->info = c.info;
    }
    virtual ~Container(){}

    void setInfo(T input){
        info = input;
    }

    T getInfo() const {
        return info;
    }




};

ostream& operator << (ostream& cout, const Container<string> &c) {
    cout << c.getInfo();
    return cout;
}

bool minimumLength (Container<string> i) {
    return ((i.getInfo().length())<5);
}

int main() {
    vector<Container<string>> v;

    Container<string> obj1,obj2,obj3,obj4;
    obj1.setInfo("bogdan");
    obj2.setInfo("adrian");
    obj3.setInfo("pocol");
    obj4.setInfo("yolo");

    v.push_back(obj1);
    v.push_back(obj2);
    v.push_back(obj3);
    v.push_back(obj4);

    for(auto i : v)
        cout<<i.getInfo()<<" ";

    auto itt = find_if(v.begin(),
                       v.end(),
                       minimumLength
                        );

    cout<<"\n"<<*itt;

    //for(auto i : v)
        //i.getInfo().erase(remove_if(i.getInfo().begin(),i.getInfo().end(),minimumLength ),i.getInfo().end());

    //for(auto i : v)
        //cout<<i.getInfo()<<" ";

    cout<<"\nexited prgrm";



    return 0;
}