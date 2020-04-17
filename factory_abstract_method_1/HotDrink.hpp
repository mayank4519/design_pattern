#include <iostream>
using namespace std;

struct HotDrink {
	virtual ~HotDrink() = default;
	virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink {
	void prepare(int volume) {
		cout << "Make tea with volume: " << volume << endl;
	}
};

struct Coffee : HotDrink {
    void prepare(int volume) {
        cout << "Make coffee with volume: " << volume << endl;
    }
};

