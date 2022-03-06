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
	Mark::Mark(const char* title, int value, int max) {
		set(title, value, max);
	}
	Mark::Mark(const Mark& toCopyFrom) {
		m_title = nullptr;
		set(toCopyFrom.m_title, toCopyFrom.m_value, toCopyFrom.m_max);
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
	Mark& Mark::read(const char* prompt) {
		int value = getint(prompt);
		if (value < 0 || value > maxValue())
		{
			cout << "Invalid mark, (0<=value<= " << maxValue() << "), retry: ";
			getint(value);
		}
		setValue(value);
		return *this;
	}
	std::ostream& Mark::display(const char* message)const {
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
}