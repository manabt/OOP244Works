#include <iostream>
#include "Utils.h"
#include "mark.h"
using namespace std;
using namespace sdds;

Mark showDetailed(Mark M) {
	char grade[3];
	M.grade(grade);
	M.display() << ", " << M.percent() << "% Grade: " << grade << endl;
	return M;
}

const Mark& showRefDetailed(const Mark& M) {
	char grade[3];
	M.grade(grade);
	M.display() << ", " << M.percent() << "% Grade: " << grade << endl;
	return M;
}

int main() {

	Mark A = { "Quiz 2", 18, 20 };

	showDetailed(A);
	//A.display();
	return 0;
}
