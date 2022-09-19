#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>

#define ASCII_END 127
#define ASCII_SP 32

static void print_num( double dbl );
static void print_char( double dbl );

int main( int argc, char **argv ) {
	std::string input;
	if ( argc != 2 ) {
		std::cout << "Usage : ./convert { input }" << std::endl;
		return EXIT_FAILURE;
	}
	char *end = NULL;
	double dbl = std::strtod( argv[1], &end );
	std::cout << "len : " << strlen( end ) << std::endl;

	//한글자일때 처리
	if ( *end != 0 && strlen( argv[1] ) == 1 ) {
		dbl = static_cast<double>( *argv[1] );
		print_char( dbl );
		print_num( dbl );
		//한글자가 아닐때
	} else {
		// strtod 반환 포인터가 NULL 이 아닐때, f가 아니거나 글자가 더
		// 있다는것은 표현안된다.
		if ( *end != 0 && ( strlen( end ) != 1 || *end != 'f' ) ) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		} else {
			// 한글자가 아닌 숫자를 더플로 전달
			print_char( dbl );
			// nan 인지 판단
			if ( isnan( dbl ) ) {
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: nanf" << std::endl;
				std::cout << "double: nan" << std::endl;
			} else  // 숫자를 찍음
				print_num( dbl );
		}
	}
	return EXIT_SUCCESS;
}

static void print_num( double dbl ) {
	int intTmp = static_cast<int>( dbl );
	float floatTmp = static_cast<float>( dbl );

	if ( INT_MAX < dbl )
		std::cout << "int: " << INT_MAX << std::endl;
	else if ( dbl < INT_MIN )
		std::cout << "int: " << INT_MIN << std::endl;
	else
		std::cout << "int: " << intTmp << std::endl;
	if ( static_cast<float>( dbl ) == floatTmp )
		std::cout << "float: " << floatTmp << ".0f" << std::endl;
	else
		std::cout << "float: "
				  << std::setprecision( std::numeric_limits<float>::digits10 )
				  << floatTmp << 'f' << std::endl;
	if ( static_cast<double>( intTmp ) == dbl )
		std::cout << "double: " << dbl << ".0" << std::endl;
	else
		std::cout << "double: "
				  << std::setprecision( std::numeric_limits<double>::digits10 )
				  << dbl << std::endl;
}

static void print_char( double c ) {
	if ( -1 < c && c <= 127 ) {
		if ( c < ASCII_SP || c == ASCII_END ) {
			std::cout << "char: Non displayable" << std::endl;
		} else {
			std::cout << "char: '" << static_cast<char>( c ) << "'"
					  << std::endl;
		}
	} else {
		std::cout << "char: impossible" << std::endl;
	}
}
