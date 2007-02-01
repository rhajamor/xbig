/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a return values and parameters with pointer pointer.
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

namespace ns1 
{
	class EXPORT A
	{
	public:
		A(){}
		~A(){}
		
		void setIntArray(int array[]) { }
		void setAArray(A array[]) { }
	};   
}

   
