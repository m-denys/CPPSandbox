#pragma once

class HasPtr2
{
public:
	HasPtr2()
	: _pStr(new std::string(""))
	, _pCount(new int(1))
	, _i(0)
	{
	}

	HasPtr2(std::string const& s = std::string())
	: _pStr(new std::string(s))
	, _pCount(new int(1))
	, _i(0)
	{
	}

	HasPtr2(HasPtr2 const& rhs)
	: _pStr(rhs._pStr)
	, _pCount(rhs._pCount)
	, _i(rhs._i)
	{
		++_pCount;
	}

	HasPtr2& operator=(HasPtr2 const& rhs)
	{
		if (this == &rhs)
		{
            return *this;
		}

		if (--_pCount == 0)
		{
			delete _pStr;
			delete _pCount;
		}	

		_pStr = rhs._pStr;
		_pCount = rhs._pCount;
		_i = rhs._i;
		return *this;
	}

	~HasPtr2()
	{
		if (--_pCount == 0)
		{
			delete _pStr;
			delte _pCount;	
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
	int* _pCount;
	int _i;
};