#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

/**
 * @class Serializer
 * @brief A class for serialization and deserialization of pointers.
 */
class Serializer {
private:
    /**
     * @brief Private constructor to prevent instantiation.
     */
    Serializer();

    /**
     * @brief Private copy constructor to prevent copying.
     * @param rhs The Serializer object to copy.
     */
    Serializer(Serializer const &rhs);

    /**
     * @brief Private assignment operator to prevent assignment.
     * @param rhs The Serializer object to assign.
     * @return A reference to the assigned Serializer object.
     */
    Serializer &operator=(Serializer const &rhs);

public:
    /**
     * @brief Destructor.
     */
    ~Serializer();

    /**
     * @brief Serialize a pointer to an unsigned integer.
     * @param ptr The pointer to serialize.
     * @return The serialized value as uintptr_t.
     */
    static uintptr_t serialize(void *ptr);

    /**
     * @brief Deserialize an unsigned integer to a pointer.
     * @param raw The serialized value to deserialize.
     * @return The deserialized pointer.
     */
    static void *deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
