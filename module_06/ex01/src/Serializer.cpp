#include "Serializer.hpp"
#include <cstdint>

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &rhs) {
	*this = rhs;
}

Serializer &Serializer::operator=(Serializer const &rhs) {
	(void)rhs;
	if (this != &rhs)
		return *this;
}

Serializer::~Serializer() {}

uintptr_t serialize(void *ptr);

void *deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
