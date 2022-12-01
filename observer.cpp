#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class ObserverInterface {
public:
    virtual void update(string msg) = 0;
};

class SubjectInterface {
    
public:
    virtual void subscribe(ObserverInterface *observer) = 0;
    virtual void unsubscribe(ObserverInterface *observer) = 0;
    virtual void notifyAll(string msg) = 0;
    std::vector<ObserverInterface*> m_observers;
};

class MySubject : public SubjectInterface {
public:
    void subscribe(ObserverInterface *observer) {
        m_observers.push_back(observer);
    }
    
    void unsubscribe(ObserverInterface *observer) {
        int i;
        for(i=0; i < m_observers.size(); i++) {
            if (observer == m_observers[i])
                break;
        }
        m_observers.erase(m_observers.begin() + i);
    }
    
    void notifyAll(string msg) {
        std::for_each(m_observers.begin(), m_observers.end(), [msg](ObserverInterface *observer) {
            observer->update(msg);
        });
    }
    
};

class Myobserver : public ObserverInterface {
    string m_name;
public:
    Myobserver(string name) : m_name(name) {}
    void update(string msg) { cout << "message recieved " << msg << " by observer " << m_name << endl;}
};



int main()
{
    Myobserver o1("mj1");
    Myobserver o2("mj2");
    Myobserver o3("mj3");
    
    MySubject s;
    s.subscribe(&o1);
    s.subscribe(&o2);
    s.subscribe(&o3);
    
    s.notifyAll("hey everyone");
    
    return 0;
}
