#include <iostream>

using namespace std;

class Car {
private:
	char* _vendor;
	char* _model;
	char* _color;
	int* _year;
	int* _id;
	static int* static_id;

public:
	Car();
	Car(const char* vendor, const char* model, const char* color, const int* year);

	// Get Methods
	inline const char* GetVendor();
	inline const char* GetModel();
	inline const char* GetColor();
	inline const int* GetYear();
	inline const int* GetId();
	inline const static int* GetStaticId();

	// Set Methods
	void SetVendor(const char* vendor);
	void SetModel(const char* model);
	void SetColor(const char* color);
	void SetYear(const int* year);

	// print
	void Show();

	// destructor
	~Car();
};

int* Car::static_id = new int(1);

#include"Car_outofclass.h"

int main() {

	Car** cars = new Car * [5];

	cars[0] = new Car("Vendor_1", "Model_1", "Yellow", new int(2012));
	cars[1] = new Car("Vendor_2", "Model_2", "Black", new int(2009));
	cars[2] = new Car("Vendor_3", "Model_3", "Red", new int(2014));
	cars[3] = new Car("Vendor_4", "Model_4", "Blue", new int(2005));
	cars[4] = new Car("Vendor_5", "Model_5", "Purple", new int(2015));


	for (size_t i = 0; i < 5; i++) {
		cars[i]->Show();
	}

	for (size_t i = 0; i < 5; i++) {
		delete cars[i];
	}
	delete[] cars;

	return 0;
}