#include <iostream>
#include "AnyType.h"
#include <typeinfo>

AnyType::AnyType(const AnyType& other) {
	this->value = other.value;
	this->type = other.type;
}

AnyType::AnyType(AnyType&& other) {
	this->value = std::move(other.value);
	other.value = NULL;

	this->type = std::move(other.type);
}

void AnyType::Swap(AnyType& other) {
	std::swap(*this, other);
}


std::string AnyType::GetType() {

	return type;
}

int AnyType::ToInt() {
	if (this->type == "int")
	{
		return this->value.i;
	}
	else 
	{
		throw std::exception("Bad cast exception");
	}
}

char AnyType::ToChar() {
	if (this->type == "char")
	{
		return this->value.c;
	}
	else
	{
		throw std::exception("Bad cast exception");
	}
}

bool AnyType::ToBool() {
	if (this->type == "bool")
	{
		return this->value.b;
	}
	else
	{
		throw std::exception("Bad cast exception");
	}
}

double AnyType::ToDouble() {
	if (this->type == "double")
	{
		return this->value.d;
	}
	else
	{
		throw std::exception("Bad cast exception");
	}
}

float AnyType::ToFloat() {
	if (this->type == "float")
	{
		return this->value.i;
	}
	else
	{
		throw std::exception("Bad cast exception");
	}
}
