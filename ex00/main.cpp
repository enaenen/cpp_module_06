#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cstring>

int main( int argc, char **argv ) {
	std::string input;
	if ( argc != 2 ) {
		std::cout << "Usage : ./convert { input }" << std::endl;
		return EXIT_FAILURE;
	}
	char *doubleEnd = NULL;
	char *longEnd = NULL;
	double d = std::strtod( argv[1], &doubleEnd );
	long l = std::strtol( argv[1], &longEnd, 10 );

	if ( std::strcmp( doubleEnd, "f" ) == 0 ||
		 std::strcmp( doubleEnd, "F" ) == 0 )
		d = static_cast<double>( static_cast<float>( d ) );
	std::cout << std::fixed << std::setprecision( 1 );

	std::cout << "char: ";
	if ( argv[1] == longEnd || l < std::numeric_limits<char>::min() ||
		 std::numeric_limits<char>::max() < l )
		std::cout << "impossible";
	else {
		char c = static_cast<char>( l );
		if ( std::isprint( c ) )
			std::cout << "\'" << c << "\'";
		else
			std::cout << "Non displayable";
	}
	std::cout << std::endl;

	std::cout << "int: ";
	if ( argv[1] == longEnd || l < std::numeric_limits<int>::min() ||
		 std::numeric_limits<int>::max() < l )
		std::cout << "impossible";
	else
		std::cout << static_cast<int>( l );
	std::cout << std::endl;

	std::cout << "float: ";
	std::cout << static_cast<float>( d ) << "f";
	std::cout << std::endl;

	std::cout << "double: ";
	std::cout << d;
	std::cout << std::endl;

	return EXIT_SUCCESS;
}