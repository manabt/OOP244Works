#include <iostream>
#include "Mark.h"
#include "utils.h"

using namespace std;

namespace sdds {
	int maxMarkValue = 1000;

	Mark& Mark::setSafeEmpty() {
		deAllocate();
		m_value = -1;
		m_max = 0;
		return *this;
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
	Mark::Mark(const char* title, int markValue, int maxValue) {
		set(title, markValue, maxValue);
	}
	Mark& Mark::setValue(int markValue) {
		if (markValue > -1 && markValue <= maxValue())
		{
			m_value = markValue;
		}
		else
		{
			setSafeEmpty();
		}
		return *this;
	}
	Mark& Mark::setTitle(const char* titleOfMark) {
		deAllocate();
		if (titleOfMark != nullptr)
		{
			m_title = new char[strLen(titleOfMark) + 1];
			strCpy(m_title, titleOfMark);
		}
		else
		{
			setSafeEmpty();
		}
		return *this;
	}
	Mark& Mark::setMax(int maxValue) {
		if (maxValue > 0 && maxValue <= maxMarkValue)
		{
			m_max = maxValue;
		}
		else
		{
			setSafeEmpty();
		}
		return *this;
	}
	Mark& Mark::set(const char* title, int markValue, int maxValue) {
		setTitle(title);
		setMax(maxValue);
		setValue(markValue);
		return *this;
	}
	Mark& Mark::read(const char* prompt) {
		int value = getint(prompt);
		if (value < 0 || value > maxValue())
		{
			cout << "Invalid mark, (0<=value<= "<< maxValue() << "), retry: ";
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
		return *this;
	}
	int Mark::percent()const {

		return (int)(markValue() / (double)maxValue() * 100);
	}
	bool Mark::isEmpty()const {
		return m_title == nullptr;
	}
}