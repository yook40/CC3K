#ifndef _POSN_H_
#define _POSN_H_

class Posn {
	public:
		int x, y;
	bool operator==(const Posn &o);
	Posn(int x = 0, int y = 0);
	Posn operator=(const Posn &o);
};

#endif
