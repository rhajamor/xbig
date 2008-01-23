/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles org.xbig.base.NativeBuffer.
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

class EXPORT A
{
public:
	void fillBuffer(void* buffer)
	{
		unsigned char* castedBuffer = (unsigned char*)buffer;
		for (int i=0; i<5; ++i) {
			castedBuffer[i] = i;
		}
	}
};
