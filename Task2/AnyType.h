#include <iostream>
#include <typeinfo>

class AnyType
{
public:

	AnyType() = default;

	template<typename T>
	AnyType(T value)
	{
		this->value = value;
		type = typeid(T).name();
	}

	AnyType(const AnyType& other);
	AnyType(AnyType&& other);

	void Swap(AnyType& other);

	std::string GetType();

	int ToInt(); //Stepan: Please make this method as const

	char ToChar(); //Stepan: Please make this method as const

	bool ToBool(); //Stepan: Please make this method as const

	double ToDouble(); //Stepan: Please make this method as const

	float ToFloat(); //Stepan: Please make this method as const

	AnyType& operator =(const AnyType& other) {
		if (this == &other)
		{
			return *this;
		}

		this->value = other.value;
		return *this;
	}

	~AnyType() = default;

private:

	union Union
	{
		char c;
		bool b;
		int i;
		double d;
		float f;

		Union() = default;

		Union(char c)
		{
			this->c = c;
		}

		Union(bool b)
		{
			this->b = b;
		}

		Union(int i)
		{
			this->i = i;
		}

		Union(double d)
		{
			this->d = d;
		}

		Union(float f)
		{
			this->f = f;
		}
	};

	Union value;
	std::string type;
};
