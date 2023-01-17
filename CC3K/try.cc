#include <iostream>
#include <memory>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;
void foo(char *n) {
	cout << *n << endl;
}

int main() {
	/*
	std::unique_ptr<int> p = std::make_unique<int>(1);
	int *l = p.get();
	
	std::unique_ptr<int> j = std::make_unique<int>(2);
	int *k = j.get();
	std::vector<int *> o;
	o.emplace_back(l);
	o.emplace_back(k);
	foo(o);
	std::cout << *l << ' ' << *k << std::endl;
	*/
	unique_ptr<char> p = make_unique<char>('5');
	foo(p.get());
}
