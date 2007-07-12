

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * some C++ operator methods are needed in java
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


class EXPORT Vector {
public:
	Vector(int x, int y, int z);
	Vector(const Vector& rhs);
	~Vector();

	Vector operator+ (const Vector& rkVector) const;
	Vector operator - (const Vector& rkVector) const;
	Vector operator *(const Vector& rkVector) const; // not a real vector product
	Vector operator/(const Vector& rkVector) const;

	const Vector operator+() const;
	const Vector operator-() const;

	const Vector& operator++();
	const Vector operator++(int);

	int operator [](unsigned index);
	int operator[] (unsigned index) const;

	void operator-> () const;

private:
	int i[3];
};


class EXPORT Radian {
public:
	Radian operator * (float f) const {Radian r; return r;}
	Radian operator * (const Radian &f) const {Radian r; return r;}
};
