#ifndef CLASS_H
#define CLASS_H

class Sample {

public:

	Sample();
	~Sample();

	int		getFoo(void) const;
	void	setFoo(int v);

private:

	int _foo;

};

#endif // !CLASS_H
