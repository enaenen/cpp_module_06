#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <exception>
#include <cstdlib>
#include <sys/time.h>

Base::~Base( void ) {
}
static void testing( int caseNumber ) {
	std::cout << "==========TEST " << caseNumber << std::endl;
	Base *randomBase;

	randomBase = generate();

	identify( randomBase );
	identify( *randomBase );

	delete randomBase;
	std::cout << "==========TEST " << caseNumber << " END" << std::endl
			  << std::endl;
}

int main( int argc, char **argv ) {
	if ( argc != 2 ) {
		std::cout << "usage : ./identify {CASES}" << std::endl;
		return EXIT_FAILURE;
	}
	for ( int i = 0; i < std::atoi( argv[1] ); i++ ) testing( i + 1 );
}

Base *generate( void ) {
	struct timeval t;

	gettimeofday( &t, NULL );
	srand( t.tv_usec );
	int type = rand() % 3;
	switch ( type ) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify( Base *p ) {
	if ( dynamic_cast<A *>( p ) )
		std::cout << "*p is << A >>  Class " << std::endl;
	else if ( dynamic_cast<B *>( p ) )
		std::cout << "*p is << B >>  Class " << std::endl;
	else if ( dynamic_cast<C *>( p ) )
		std::cout << "*p is << C >>  Class " << std::endl;
	else
		std::cout << "NOT A, B, C Class" << std::endl;
}

void identify( Base &p ) {
	try {
		(void)dynamic_cast<A &>( p );
		std::cout << "&p is << A >> Class" << std::endl;
		return;
	} catch ( std::exception &e ) {
	}
	try {
		(void)dynamic_cast<B &>( p );
		std::cout << "&p is << B >> Class" << std::endl;
		return;
	} catch ( std::exception &e ) {
	}
	try {
		(void)dynamic_cast<C &>( p );
		std::cout << "&p is << C >> Class" << std::endl;
		return;
	} catch ( std::exception &e ) {
		std::cout << "*EXCEPTION Invalid Class!" << std::endl;
		return;
	}
}