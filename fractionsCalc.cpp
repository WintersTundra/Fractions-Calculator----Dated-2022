
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class fractions {
public:
	fractions();
	fractions(int num, int denom);
	fractions& operator = (const fractions& otherFraction); //Assignment operator
	fractions operator + (const fractions otherFraction) const; //addition
	fractions operator -(const fractions otherFraction) const; // substrction operator
	fractions operator *(const fractions otherFraction) const; // multiplication operator
	fractions operator * (int k) const;
	fractions operator /(const fractions otherFraction) const; // division operator
	fractions reduce();
	bool operator ==(const fractions& otherFraction) const; // equality operator
	int getNumerator() const;
	int getDenominator() const;
	void setNumerator(int newN);
	void setDenominator(int newD);
	friend ostream& operator<<(ostream& o, const fractions& mClass); //insertion operator
	friend fractions operator *(int k, const fractions& otherFraction);
private:
	int numerator;
	int denominator;
};

//Constructors

fractions::fractions()
	:numerator(0)
	, denominator(1)
{

};
fractions::fractions(int num, int denom)
	:numerator(num)
	, denominator(denom)
{

};

//Operators

fractions& fractions:: operator = (const fractions& otherMyClass) {
	if (this == &otherMyClass) {
		return *this;
	}
	numerator = otherMyClass.numerator;
	denominator = otherMyClass.denominator;
	return *this;
}

fractions fractions::operator + (const fractions otherFraction) const {
	fractions result;
	if (this->denominator == result.getDenominator()) {
		result.setDenominator(this->denominator);
		result.setNumerator(this->numerator + otherFraction.getNumerator());
	}
	else {
		result.setDenominator(this->denominator * otherFraction.getDenominator());
		result.setNumerator((this->numerator * otherFraction.getDenominator()) + (this->denominator * otherFraction.getNumerator()));
	}
	result.reduce();
	return result;
}

fractions fractions:: operator -(const fractions otherFraction) const {
	fractions result;

	if (this->denominator == result.getDenominator()) {
		result.setDenominator(this->denominator);
		result.setNumerator(this->numerator - otherFraction.getNumerator());
	}
	else {
		result.setDenominator(this->denominator * otherFraction.getDenominator());
		result.setNumerator((this->numerator * otherFraction.getDenominator()) - (this->denominator * otherFraction.getNumerator()));
	}

	result.reduce();
	return result;

}

fractions fractions:: operator *(const fractions otherFraction) const {
	fractions result;

	result.setDenominator(this->denominator * otherFraction.getDenominator());
	result.setNumerator(this->numerator * otherFraction.getNumerator());

	result.reduce();
	return result;

}

fractions fractions::  operator * (int k) const {
	fractions result;

	result.setDenominator(this->denominator);
	result.setNumerator(this->numerator * k);

	result.reduce();
	return result;
}

fractions fractions:: operator /(const fractions otherFraction) const {
	fractions result;

	result.setDenominator(this->denominator * otherFraction.getNumerator());
	result.setNumerator(this->numerator * otherFraction.getDenominator());

	result.reduce();
	return result;

}

bool fractions::operator ==(const fractions& otherFraction) const {
	int num1;
	int num2;
	int den1;
	int den2;
	num1 = this->getNumerator();
	den1 = this->getDenominator();
	num2 = otherFraction.getNumerator();
	den2 = otherFraction.getDenominator();
	if (num1 == num2 && den1 == den2) {
		return true;
	}
	return false;

}


ostream& operator<<(ostream& result, fractions& TheFraction) {
	result << TheFraction.getNumerator() << " / " << TheFraction.getDenominator();
	return result;
}
fractions operator *(int k, const fractions& otherFraction) {
	return otherFraction.operator*(k);
}


//other

int gcd(int a, int b) {
	int result = min(a, b);
	while (result > 0) {
		if (a % result == 0 && b % result == 0) {
			break;
		}
		result--;
	}
	return result;
}
fractions fractions::reduce() {

	int d = this->denominator;
	int n = this->numerator;
	int GCD = gcd(n, d);

	this->denominator = this->denominator / GCD;
	this->numerator = this->numerator / GCD;

	return *this;

}

int fractions::getNumerator() const {
	return numerator;
}
int fractions::getDenominator() const {
	return denominator;
}
void fractions::setDenominator(int newD) {
	this->denominator = newD;
}
void fractions::setNumerator(int newN) {
	this->numerator = newN;
}
int fractionsCalc() {
	int num, dem;
	char UsingOperator;
	char stat = '0'; //0 == operating, 1 = exit
	num = 0;
	dem = 1;
	int n1 = 0;
	int d2 = 1;
	char slash;
	fractions firstFrac;
	int firstNumber;
	bool isInt = false;
	int secondNumber;
	bool isInt2 = false;
	fractions secondFrac;
	fractions result;
	bool isEqual;
	/*
	while (stat != '1') {
		cout << "What is your operation? ('+' for addition,'-' for subtraction,'*' for multiplication,'/' for division, '=' to see if they are equal, '1' to exit)" << endl;
		cin >> UsingOperator;
		if (UsingOperator == '1') {
			cout << "You exited the program :(... Well, come back soon!" << endl;
			break;
		}
		if (UsingOperator != '+' && UsingOperator != '-' && UsingOperator != '*' && UsingOperator != '/' && UsingOperator != '=' ) {
			cout << "That is not a valid operator." << endl;
			continue;
		}
		while (dem == 0) {
			cout << "What is your first fraction? (numerator denominator)" << endl;
			cin >> num >> dem;
			if (dem != 0) {
				fractions firstFracTemp(num, dem);
				firstFrac = firstFracTemp;
				break;
			}
			else {
				cout << "Denominator can not be 0. Please try again" << endl;
			}
		}
		num = 0;
		dem = 0;
		while (dem == 0) {
			cout << "What is your second fraction? (numerator denominator)" << endl;
			cin >> num >> dem;
			if (dem != 0) {
				fractions secondFracTemp(num, dem);
				secondFrac = secondFracTemp;
				break;
			}
			else {
				cout << "Denominator can not be 0. Please try again" << endl;
			}
		}
		*/
	cout << "Operators: '+' for addition,'-' for subtraction,'*' for multiplication,'/' for division, '=' to see if they are equal" << endl;
	cin >> num >> slash >> dem >> UsingOperator >> n1 >> slash >> d2;
	if (dem == 1) {
		firstNumber = num;
		isInt = true;
	}
	if (d2 == 1) {
		isInt2 = true;
		secondNumber = n1;
	}
	if (UsingOperator != '+' && UsingOperator != '-' && UsingOperator != '*' && UsingOperator != '/' && UsingOperator != '=') {
		cout << "Operator not valid." << endl;
		
	}else {
		if (dem == 0 || d2 == 0) {
			cout << "The demoniator can not be 0." << endl;
		}else {
			if(isInt == false){
				fractions firstFracTemp(num, dem);
				firstFrac = firstFracTemp;
				fractions secondFracTemp(n1, d2);
				secondFrac = secondFracTemp;
			}
			else {
				if (isInt == true) {
					fractions firstFracTemp(num, dem);
					firstFrac = firstFracTemp;
					fractions secondFracTemp(n1, d2);
					secondFrac = secondFracTemp;
				}
				else {
					fractions firstFracTemp(num, dem);
					firstFrac = firstFracTemp;
					fractions secondFracTemp(n1, d2);
					secondFrac = secondFracTemp;
				}
			}
			
	
			firstFrac.reduce();
			secondFrac.reduce();


			switch (UsingOperator) {
			case '+':
				result = firstFrac + secondFrac;
				cout << "Here is your new fraction!" << endl;
				cout << result << endl;
				break;
			case '-':
				result = firstFrac - secondFrac;
				cout << "Here is your new fraction!" << endl;
				cout << result << endl;
				break;
			case '*':
				if (isInt == false && isInt2 == false) {
					result = firstFrac * secondFrac;
				}else {
					if (isInt == true) {
						result = firstNumber * secondFrac;
					}else {
						result = firstFrac * secondNumber;
					}
				
				}

				cout << "Here is your new fraction!" << endl;
				cout << result << endl;
				break;
			case '/':
				result = firstFrac / secondFrac;
				cout << "Here is your new fraction!" << endl;
				cout << result << endl;
				break;
			case '=':
				isEqual = firstFrac == secondFrac;
				if (isEqual) {
					cout << "They ARE equal! :)" << endl;
				}
				else {
					cout << "They AREN'T equal. :()" << endl;
				}
				break;
			}
			cout << endl;
			dem = 0;
		}
	}
	
	
	
	return 0;
}
