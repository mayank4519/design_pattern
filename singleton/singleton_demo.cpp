#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <memory>
#include <map>
#include <fstream>
#include "boost/lexical_cast.hpp"

using namespace std;

class Database{
    virtual int getPopulation(const string& str) = 0;
};

class Singleton : public Database{
	Singleton(){
		ifstream ifs("smsc.txt");
		string s, s2;
		while(getline(ifs, s)){
			getline(ifs, s2);
			int pop =  boost::lexical_cast<int>(s2);
			conn[s] = pop;
		}
	}
	map<string, int> conn;
public:
	Singleton(Singleton const&) = delete;
	void operator=(Singleton const&) = delete;

	static Singleton* get(){
	    //static Singleton sobj;
	    static Singleton *sobj = new Singleton();
	    return sobj;
	}
	int getPopulation(const string& str) override {
	    return conn[str];
	}	
};

struct SingletonRecordFinder{
    int totalPopulation(vector<string> names){
	int result{0};
	for (auto name: names){
	    result += Singleton::get()->getPopulation(name);
	}
	return result;
    }
};

int main()
{
//Use case: 1
    string s = "user5";
    cout << " for test smsc, no. of conns are: " << Singleton::get()->getPopulation(s) << endl;

//Use case: 2
    vector <string> vec = {"user1", "user2"};
    SingletonRecordFinder srf;
    cout << "total population of user1 and user2 is: " << srf.totalPopulation(vec);
    delete Singleton::get();
    return 0;
}
