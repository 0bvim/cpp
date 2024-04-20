#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

/**
 * @brief Represents a point in 2D space with fixed-point coordinates.
 */
class Point {
public:
    /**
     * @brief Default constructor. Initializes the point at (0, 0).
     */
    Point(void);

    /**
     * @brief Constructs a point with the specified x and y coordinates.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     */
    Point(const float x, const float y);

    /**
     * @brief Copy constructor.
     * @param src The point to copy.
     */
    Point(const Point &src);

    /**
     * @brief Copy assignment operator.
     * @param rhs The point to assign from.
     * @return Reference to the assigned point.
     */
    Point &operator=(const Point &rhs);

    /**
     * @brief Destructor.
     */
    ~Point(void);

    /**
     * @brief Gets the x-coordinate of the point.
     * @return The x-coordinate.
     */
    Fixed getX(void) const;

    /**
     * @brief Gets the y-coordinate of the point.
     * @return The y-coordinate.
     */
    Fixed getY(void) const;

private:
    Fixed const _x; /**< The x-coordinate of the point. */
    Fixed const _y; /**< The y-coordinate of the point. */
};

#endif // POINT_HPP
