#include <iostream>
#include "Vector3.h"

int main()
{
	Math::Vector3<float> v;
	
	v.setVectorData(1.f, 2.f, 0.f);

	Math::Vector3<float> v2(v);

	std::cout << v2 << "\n";

	Math::Vector3<float> devision = 2 * v;

	try
	{
		devision /= v;
	}
	catch (std::runtime_error& r)
	{
		std::cout << r.what() << "\n";
	}
	

	std::cout << devision;

	return 0;
}