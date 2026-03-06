#include <iostream>
<<<<<<< HEAD

int main()
{
	std::cout << "Math library\n";
=======
#include "Vector3.h"

int main()
{
	Math::Vector3<float> v;
	
	v.setVectorData(1.f, 2.f, 3.f);
	std::cout << v.length() << "\n";

	v.normalize();
	std::cout << v.length() << "\n";

	std::cout << v << "\n";

	Math::Vector3<float> v2(v);

	std::cout << v2 << "\n";

>>>>>>> 6ac0a6d (Project setup)
	return 0;
}