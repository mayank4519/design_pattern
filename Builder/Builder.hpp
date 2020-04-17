#include <string>
#include <vector>
#include <ostream>
using namespace std;

class Field
{
  string name, type;
public:
  Field(string const& name, string const& type) : 
    name(name) , type(type)
  {
  }

  friend ostream& operator<<(ostream& os, const Field& f)
  {
    os << "Field name " << f.name << " and type " << f.type;
    return os;
  }
};

class Class
{
public:
  string name;
  vector<Field> vf;
  friend ostream& operator<<(ostream& os, const Class& cl)
  {
    os << "Name " << cl.name << ".\n";
    for(auto field : cl.vf)
    {
      os << field << "\n";
    }
    return os;
  }
    
};

class CodeBuilder
{
  Class cl;
public:
  CodeBuilder(const string& class_name)
  {
      cl.name = class_name;
  }

  CodeBuilder& add_field(const string& name, const string& type)
  {
    cl.vf.push_back(Field{name, type});
    return *this;
  }

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
  {
    return os << obj.cl;
  }
};
