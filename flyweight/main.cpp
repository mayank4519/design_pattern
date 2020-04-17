#include <iostream>
#include <boost/bimap.hpp>
#include <string>
#include <map>
#include <cstdint>

#define key uint16_t

using namespace std;

class User {
private:
  key first_name;
  key last_name;
  static boost::bimap<key, string> names;
  static key count;
public:
  User(string first_name, string last_name) {
   this->first_name = add(first_name);
   this->last_name  = add(last_name); 
  }
  
  static key add(const string &s) {
    auto it = names.right.find(s);
    if (it == names.right.end()) {
      key temp = ++count;
      names.insert({temp, s});
      return temp;
    }
    return it->second;
  }

  const string& get_first_name() const {
    return names.left.find(first_name)->second;
  }
  
   const string& get_last_name() const {
    return names.left.find(last_name)->second;
  }
  friend ostream& operator<<(ostream &out, User &user);
};

ostream& operator<<(ostream &out, User &user) {
   out << "first name is: " << user.get_first_name() << "(" << user.first_name << ")" << " and last name is: " 
      << user.get_last_name() << "(" << user.last_name << ")" << endl;
   return out;
}

boost::bimap<key, string> User::names{};
key User::count = 0;

int main() {
  User user1{"mayank", "jain"};
  User user2{"sameer", "jain"};
  cout << user1 << user2;
  User user3{"mayank", "jain"};
  User user4{"mayank", "sharma"};
  cout << user3 << user4;
}
