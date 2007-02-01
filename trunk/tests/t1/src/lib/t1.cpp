

#include "t1.h"
#include <iostream>

namespace t1 
{
   
  namespace t11
  {
  	T1::T1()
  	  : _test_int(42)
  	  , _test_uint(43)
  	  , _test_string("default")
  	{
  	}
  	
  	T1::T1(int i)
  	  : _test_int(i)
  	  , _test_uint(43)
  	  , _test_string("default")
  	{
  	}
  	
  	T1::T1(int i, unsigned int u)
  	  : _test_int(i)
  	  , _test_uint(u)
  	  , _test_string("default")
  	{
  	}
  	
  	T1::T1(int i, unsigned int u, const std::string& str)
  	  : _test_int(i)
  	  , _test_uint(u)
  	  , _test_string(str)
  	{
  	}
  	
    void T1::print() const 
    {
      std::cout << "T1::print()" << std::endl;   
    }
    
    void T1::setString(const std::string& str)
    {
    	_test_string = str;
    }
        
    const std::string& T1::getString() const
    {
    	return _test_string;
    }
        
    void T1::setInteger(int value)
    {
    	_test_int = value;
    }
        
    int T1::getInteger() const
    {
    	return _test_int;
    }
        
    void T1::setUnsignedInteger(const unsigned int& value)
    {
    	_test_uint = value;
    }
        
    unsigned int T1::getUnsignedInteger() const
    {
    	return _test_uint;
    }
        
    const char* T1::getClassName()
    {
    	return "T1";
    }

    
  }
   
   
}
