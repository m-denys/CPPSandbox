#pragma once

class Employee
{
public:
	Employee()
	: _id(s_index++)
	, _name("null")
	{
	}

	Employee(std::string const& name)
	: _id(s_index++)
	, _name(name)
	{
	}

	~Employee()
	{
	}

	int getId() const { return _id; }
	std::string getName() const { return _name; }

private:
	int _id;
	std::string _name;

private:
	static int s_index;
};

int Employee::s_index = 0;