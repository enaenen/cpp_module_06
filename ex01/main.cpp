#include "data.hpp"

int main( void ) {
	Data original;
	uintptr_t serializedData;
	Data* deserializedData;

	original.d = 42.4242;
	original.f = -4.2;
	original.i = 424242;

	std::cout << "Original Data addr: " << &original << std::endl;
	std::cout << "Original Data Double: " << original.d << std::endl;
	std::cout << "Original Data Float: " << original.f << std::endl;
	std::cout << "Original Data Int: " << original.i << std::endl << std::endl;

	serializedData = serialize( &original );
	std::cout << "Serialized Data addr: "
			  << reinterpret_cast<uint64_t>( &original ) << std::endl;

	std::cout << "Serialized Data Double: "
			  << reinterpret_cast<Data*>( serializedData )->d << std::endl;
	std::cout << "Serialized Data Float: "
			  << reinterpret_cast<Data*>( serializedData )->f << std::endl;
	std::cout << "Serialized Data Int: "
			  << reinterpret_cast<Data*>( serializedData )->i << std::endl
			  << std::endl;

	deserializedData = deserialize( serializedData );
	std::cout << "Deserialized Data addr:  " << deserializedData << std::endl;
	std::cout << "Deserialized Data Double: " << deserializedData->d
			  << std::endl;
	std::cout << "Deserialized Data Float: " << deserializedData->f
			  << std::endl;
	std::cout << "Deserialized Data Int: " << deserializedData->i << std::endl;

	return 0;
}

uintptr_t serialize( Data* ptr ) { return reinterpret_cast<uintptr_t>( ptr ); }
Data* deserialize( uintptr_t raw ) { return reinterpret_cast<Data*>( raw ); }