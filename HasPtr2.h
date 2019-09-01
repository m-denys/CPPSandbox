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

	HasPtr2(HasPtr2 const& rhs)
	: _pStr(rhs._pStr)
	, _pRefCount(rhs._pRefCount)
	, _i(rhs._i)
	{
		++_pRefCount;
	}

	HasPtr2& operator=(HasPtr2 const& rhs)
	{
		if (this == &rhs)
		{
            return *this;
		}

		if (--_pRefCount == 0)
		{
			delete _pStr;
			delete _pRefCount;
		}	

		_pStr = rhs._pStr;
		_pRefCount = rhs._pRefCount;
		_i = rhs._i;
		return *this;
	}

	~HasPtr2()
	{
		if (--_pRefCount == 0)
		{
			delete _pStr;
			delte _pRefCount;	
		}
	}

	bool operator==(HasPtr2 const& rhs)
	{
		if (_pStr && rhs._pStr)
		{
			return _pStr == rhs._pStr;
		}
		return false;		
	}

private:
	std::string* _pStr;
	int* _pRefCount;
	int _i;
};