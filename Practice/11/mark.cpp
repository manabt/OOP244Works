#include <iostream>
#include "mark.h"
#include "utils.h"

using namespace std;

namespace sdds {

	int maxMarkValue = 1000;

	void Mark::setSafeEmpty() {
		deAllocate();
		m_title = nullptr;
		m_value = -1;
		m_max = 0;
	}
	void Mark::deAllocate() {
		delete[] m_title;
		m_title = nullptr;
	}
	Mark::Mark() {
		m_title = nullptr;
		setSafeEmpty();
	}
	Mark::~Mark() {
		deAllocate();
	}
	Mark::Mark(const char* title, int value, int max) { // for creating an instance of the object and assining values to it at the moment of creation
		m_title = nullptr;
		set(title, value, max);
	}
	Mark::Mark(const Mark& toCopyFrom) { // copy constructer, to initilize an object to another
		m_title = nullptr;
		set(toCopyFrom.m_title, toCopyFrom.m_value, toCopyFrom.m_max);
	}
	Mark& Mark::operator=(const Mark& toCopyFrom) {
		delete[] m_title;
		m_title = nullptr;
		set(toCopyFrom.m_title, toCopyFrom.m_value, toCopyFrom.m_max);
		return *this;
	}
	Mark& Mark::set(const char* title, int value, int max) {
		setTitle(title);
		setMax(max);
		setValue(value);
		return *this;
	}
	Mark& Mark::setValue(int value) {
		if (value > -1 && value <= maxValue())
		{
			m_value = value;
		}
		else {
			setSafeEmpty();
		}
		return *this;
	}
	Mark& Mark::setTitle(const char* markTitle) {
		deAllocate();
		if (markTitle != nullptr)
		{
			m_title = new char[strLen(markTitle) + 1];
			strCpy(m_title, markTitle);
		}
		else
		{
			setSafeEmpty();
		}
		return *this;
	}
	Mark& Mark::setMax(int max) {
		if (max > 0 && max <= maxMarkValue)
		{
			m_max = max;
		}
		else {
			setSafeEmpty();
		}
		return *this;
	}
	istream& Mark::read(const char* prompt, istream& istr) {
		int value = getint(prompt, istr);
		if (value < 0 || value > maxValue())
		{
			cout << "Invalid mark, (0<=value<= " << maxValue() << "), retry: ";
			value = getint(nullptr, istr);
		}
		setValue(value);
		return istr;
	}
	std::ostream& Mark::display(const char* message, ostream& ostr)const {
		if (message)
			cout << message;
		if (isEmpty()) {
			cout << "Invalid Mark!";
		}
		else {
			cout << m_title << ": " << markValue()
				<< "/" << maxValue();
		}
		return cout;
	}

	int Mark::markValue()const {

		return m_value;
	}
	int Mark::maxValue()const {

		return m_max;
	}
	const Mark& Mark::grade(char* grade)const {
		int p = percent();
		if (p < 50) {
			strCpy(grade, "F");
		}
		else if (p < 55) {
			strCpy(grade, "D");
		}
		else if (p < 60) {
			strCpy(grade, "D+");
		}
		else if (p < 65) {
			strCpy(grade, "C");
		}
		else if (p < 70) {
			strCpy(grade, "C+");
		}
		else if (p < 75) {
			strCpy(grade, "B");
		}
		else if (p < 80) {
			strCpy(grade, "B+");
		}
		else if (p < 90) {
			strCpy(grade, "A");
		}
		else if (p <= 100) {
			strCpy(grade, "A+");
		}
		return *this;
	}
	int Mark::percent()const {
		return (int)(markValue() / (double)maxValue() * 100);
	}
	bool Mark::isEmpty()const {
		return m_title == nullptr;
	}
	bool Mark::operator==(const Mark& RO)const {
		return this->percent() == RO.percent();
	}
	bool Mark::operator!=(const Mark& RO)const {
		return !operator==(RO);
	}
	Mark Mark::operator+(const Mark& RO)const {
		Mark sum;
		if (*this && RO) {
			char* title = new char[strlen(m_title) + strlen(RO.m_title) + 6];
			strCpy(title, m_title);
			strCat(title, " and ");
			strCat(title, RO.m_title);
			sum.set(title, this->percent() + RO.percent(), 100);
			delete[] title;
		}
		return sum;
	}
	Mark& Mark::operator<<(int value) {
		return setValue(value);
	}
	Mark& Mark::operator<<(const char* title) {
		return  setTitle(title);
	}
	const Mark& Mark::operator>>(int& mark)const {
		if (*this)
		{
			mark = percent();
		}
		return *this;
	}
	Mark::operator bool()const {
		return !isEmpty();
	}
	Mark::operator const char* ()const {
		return m_title;
	}
	std::ostream& operator<<(std::ostream& LO, const Mark& RO)
	{
		return RO.display(nullptr, LO);
	}
	std::istream& operator>>(std::istream& LO, Mark& RO)
	{
		return RO.read(nullptr, LO);
	}
}