#include "ReinterpretCast.hpp"
#include <iostream>

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

int main()
{
	Data		data;
	Data		*deserialized;
	uintptr_t	uin;

	data.d21 = 21;
	uin = serialize(&data);
	deserialized = deserialize(uin);
	std::cout << "before serialization: " << data.d21
				<< "\nafter serialization: " << uin
				<< "\nafter deserialization: " << deserialized->d21 << "\n";

}
