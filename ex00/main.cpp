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
	char *end = NULL;
	double d = std::strtod( argv[1], &end );

	if ( std::strcmp( end, "f" ) == 0 || std::strcmp( end, "F" ) == 0 )
		d = static_cast<double>( static_cast<float>( d ) );
	std::cout << std::fixed << std::setprecision( 1 );

	if ( *end != 0 && ( *end != 'f' || strlen( end ) != 1 ) ) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else {
		if ( argv[1] == end || d < std::numeric_limits<char>::min() ||
			 std::numeric_limits<char>::max() < d )
			std::cout << "char: impossible" << std::endl;
		else {
			char c = static_cast<char>( d );
			if ( std::isprint( c ) )
				std::cout << "char: "
						  << "\'" << c << "\'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		if ( isnan( d ) ) {
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "int: nan" << std::endl;
		} else {
			if ( argv[1] == end || d < std::numeric_limits<int>::min() ||
				 std::numeric_limits<int>::max() < d )
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << static_cast<int>( d );
			std::cout << std::endl;
			if ( *end != 0 && ( strlen( end ) != 1 || *end != 'f' ) ) {
				std::cout << "float: nanf" << std::endl;
			} else if ( isnan( d ) )
				std::cout << "float: nanf" << std::endl;
			else
				std::cout << d << std::endl;
			std::cout << "double: ";
			std::cout << d;
			std::cout << std::endl;
		}
	}
	return EXIT_SUCCESS;
}