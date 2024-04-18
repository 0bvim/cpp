#ifndef CLASS_H
#define CLASS_H

class Sample {

public:

	/* canonical form constructor */
	Sample(void); // canonical
	/* passing the a value to start */
	Sample(int const n);
	/* copy constructor */
	Sample(Sample const & src); //canonical

	/* overload operator */
	Sample & operator=(Sample const & rhs); //canonical

	/* destructor */
	~Sample(); //canonical
	int		getFoo(void) const;
	void	setFoo(int v);

private:

	int _foo;

};

#endif // !CLASS_H
