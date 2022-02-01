#ifndef SDDS_DMAINT_H
#define SDDS_DMAINT_H

namespace sdds {
	
	int* getDynamicInts(int& size, int initialSize);

	extern int allocSize;  // making allocSize variable global

}

#endif