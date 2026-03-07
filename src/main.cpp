#include <iostream>
#include "Vector3.h"
#include "Vector4.h"

int main()
{
	Math::Vector3<float> v;

	Math::Vector4<float> v4;
	v4.setVectorData(1.f, 2.f, 3.f, 1.f);

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
	
	std::cout << v4 << "\n";

	std::cout << devision;

	return 0;
}