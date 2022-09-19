#pragma once

#include <iostream>
#include <stdint.h>

typedef struct s_data {
	int i;
	float f;
	double d;
} Data;

uintptr_t serialize( Data* ptr );
Data* deserialize( uintptr_t raw );