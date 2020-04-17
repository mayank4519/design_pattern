#include <string>

template<typename T>
class Observer {
public:
	virtual void field_changed(T& source, std::string age)=0;
};
