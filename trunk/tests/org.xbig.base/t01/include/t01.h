/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles org.xbig.base.Native...Buffer.
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
	void fillByteBuffer(void* buffer)
	{
		unsigned char* castedBuffer = (unsigned char*)buffer;
		for (int i=0; i<5; ++i) {
			castedBuffer[i] = i;
		}
	}

	void fillCharBuffer(void* buffer)
	{
		char* castedBuffer = (char*)buffer;
		for (int i=0; i<5; ++i) {
			castedBuffer[i] = i;
		}
	}

	void fillShortBuffer(void* buffer)
	{
		short* castedBuffer = (short*)buffer;
		for (int i=0; i<5; ++i) {
			castedBuffer[i] = i;
		}
	}

	void fillIntBuffer(void* buffer)
	{
		int* castedBuffer = (int*)buffer;
		for (int i=0; i<5; ++i) {
			castedBuffer[i] = i;
		}
	}

	void fillLongBuffer(void* buffer)
	{
		long* castedBuffer = (long*)buffer;
		for (int i=0; i<5; ++i) {
			castedBuffer[i] = i;
		}
	}

	void fillFloatBuffer(void* buffer)
	{
		float* castedBuffer = (float*)buffer;
		for (int i=0; i<5; ++i) {
			castedBuffer[i] = i;
		}
	}

	void fillDoubleBuffer(void* buffer)
	{
		double* castedBuffer = (double*)buffer;
		for (int i=0; i<5; ++i) {
			castedBuffer[i] = i;
		}
	}
};
