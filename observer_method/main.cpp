#include <iostream>
#include <string>
#include "Observer.hpp"
#include "Observable.hpp"

class Person : public Observable<Person> {
	int age;
public:
	Person(int age) : age(age)
	{}
	void set_age(int age) 
	{
		if(age == Person::age) return;
		this->age = age;
		notify(*this, "age");	
	}
	int get_age()
        {
		return age;
        }
};

//observer
class ComponentPersonObserver : public Observer<Person> {
	void field_changed(Person &person, std::string field_name) override 
	{
		std::cout << "Person's " << field_name << " has changed to  ";
		if (field_name == "age") std::cout << person.get_age() << ".\n";
	}
};

int main() 
{
	Person person{10};
	ComponentPersonObserver cpo, cpo1;
	person.subscribe(cpo);
	person.subscribe(cpo1);

	person.set_age(15);
	person.set_age(16);
	//person.unsubscribe(cpo);
	//person.get_age();
	return 0;
}


