#include <iostream>
#include "Core/Math.h"
#include "Core/Random.h"

#define Name "Savion\n"
using namespace std;

int main() {

	cout << Name;
	cout << "Hello World" << endl;
	cout << Rex::Math::pi << endl;
	for (int i = 0; i < 5; i++) {
		
		cout << Rex::Random::getRandomInt(5,10) << endl;
	}
}