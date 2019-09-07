/*
	Class member functions can be used with trailing 'reference qualifiers':
	void func() &;  // Used only for l-values 
	void func() &&; // Used only for r-values 
*/

struct RefQual
{
	void printInfo() &
	{
		std::cout << "'printInfo() &' for l-value is called\n";
	}

	void printInfo() &&
	{
		std::cout << "'printInfo() &&' for r-value is called\n";
	}
};

int main(int argc, char const* argv[])
{
	/////////////////////
	RefQual rqLValue;
	rqLValue.printInfo();
	/////////////////////
	RefQual().printInfo();
	/////////////////////
	
	return 0;
}

/*
	Output: 
	'printInfo() &' for l-value is called
	'printInfo() &&' for l-value is called
*/

