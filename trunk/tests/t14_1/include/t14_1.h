/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles arrays as parameters.
 *
 * Note:
 * It currently fails because arrays are not implemented.
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
