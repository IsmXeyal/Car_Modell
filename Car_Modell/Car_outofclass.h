#pragma once

Car::Car() {
	_vendor = NULL;
	_model = NULL;
	_color = NULL;
	_id = new int((*static_id)++);
}

// Set Methods

void Car::SetVendor(const char* vendor) {
	if (this->_vendor != NULL) {
		delete[] this->_vendor;
	}
	int len = strlen(vendor);
	this->_vendor = new char[len + 1];
	strcpy_s(this->_vendor, len + 1, vendor);
}

void Car::SetModel(const char* model) {
	if (this->_model != NULL) {
		delete[] this->_model;
	}
	int len = strlen(model);
	this->_model = new char[len + 1];
	strcpy_s(this->_model, len + 1, model);
}

void Car::SetColor(const char* color) {
	if (this->_color != NULL) {
		delete[] this->_color;
	}
	int len = strlen(color);
	this->_color = new char[len + 1];
	strcpy_s(this->_color, len + 1, color);
}

void Car::SetYear(const int* year) {
	if (this->_year != NULL) {
		delete[] this->_year;
	}
	this->_year = new int(*year);
}

Car::Car(const char* vendor, const char* model, const char* color, const int* year) {
	SetVendor(vendor);
	SetModel(model);
	SetColor(color);
	SetYear(year);
	_id = new int((*static_id)++);
}

inline const char* Car::GetVendor() {
	return this->_vendor;
}

inline const char* Car::GetModel() {
	return this->_model;
}

inline const char* Car::GetColor() {
	return this->_color;
}

inline const int* Car::GetYear() {
	return this->_year;
}

inline const int* Car::GetId() {
	return this->_id;
}

inline const int* Car::GetStaticId() {
	return static_id;
}

void Car::Show() {
	cout << "Id: " << (_id != NULL ? *_id : 0) << endl;
	cout << "Vendor: " << (_vendor != NULL ? _vendor : "NULL") << endl;
	cout << "Model: " << (_model != NULL ? _model : "NULL") << endl;
	cout << "Color: " << (_color != NULL ? _color : "NULL") << endl;
	cout << "Year: " << (_year != NULL ? *_year : 0) << endl << endl;
}

Car::~Car() {
	delete[] _vendor;
	delete[] _model;
	delete _year;
	delete[] _color;
	delete _id;
}