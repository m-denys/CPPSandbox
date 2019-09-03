#pragma once

class HasPtr2
{
public:
	HasPtr2()
	: _pStr(new std::string(""))
	, _pRefCount(new int(1))
	, _i(0)
	{
	}

	HasPtr2(std::string const& s = std::string())
	: _pStr(new std::string(s))
	, _pRefCount(new int(1))
	, _i(0)
	{
	}

	HasPtr2(HasPtr2 const& other)
	: _pStr(other._pStr)
	, _pRefCount(other._pRefCount)
	, _i(other._i)
	{
		++*_pRefCount;
	}

	HasPtr2& operator=(HasPtr2 const& other)
	{
		if (this == &other)
		{
            return *this;
		}

		if (--*_pRefCount == 0)
		{
			delete _pStr;
			delete _pRefCount;
		}	

		_pStr = other._pStr;
		_pRefCount = other._pRefCount;
		_i = other._i;

		++*_pRefCount;

		return *this;
	}

	~HasPtr2()
	{
		if (--*_pRefCount == 0)
		{
			delete _pStr;
			delte _pRefCount;	
		}
	}

	bool operator==(HasPtr2 const& other)
	{
		if (_pStr && other._pStr)
		{
			return _pStr == other._pStr;
		}
		return false;		
	}

private:
	std::string* _pStr;
	int* _pRefCount;
	int _i;
};