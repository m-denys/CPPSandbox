#pragma once

class HasPtr
{
public:
	HasPtr()
	: _ps(nullptr)
	, _i(0)
	{
	}

	HasPtr(std::string const& s = std::string())
	: _ps(new std::string(s))
	, _i(0)
	{
	}

	HasPtr(HasPtr const& rhs)
	: _ps(new std::string(*rhs._ps))
	, _i(rhs._i)
	{
	}

	HasPtr& operator=(HasPtr const& rhs)
	{
		delete _ps;
		_ps = new std::string(*rhs._ps);
		_i = rhs._i;
		return *this;
	}

	~HasPtr()
	{
		delete _ps;
	}

	bool operator==(HasPtr const& rhs)
	{
		if (_ps && rhs._ps)
		{
			return *_ps == *rhs._ps;
		}
		return false;		
	}

private:
	std::string* _ps;
	int _i;
};

