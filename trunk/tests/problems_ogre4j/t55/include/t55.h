
#ifndef __T55_H__
#define __T55_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * unsigned char ** as parameter, see bug 1728985
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <iostream>


namespace Ogre {

	class EXPORT VertexElement {
		unsigned char** mChar;
		unsigned char* mHelper;
	public:
		VertexElement() {
			mHelper = new unsigned char;
			mChar = &mHelper;
		}
		VertexElement(const VertexElement& rhs) {
			**mChar = **(rhs.mChar);
		}
		~VertexElement() {
			delete mHelper;
		}

		void baseVertexPointerToElement (void *pBase, unsigned char **pElem) const {}

		void* getVoidPointer() {return (void*)*mChar;}
		unsigned char** getPointerPointer() {
			std::cout << "returning: " << (int)*(*mChar) << "\n";
			return mChar;
		}
		void setChar(unsigned char para) {
			std::cout << "got: " << (int)para << "\n";
			*(*mChar) = para;
			std::cout << "stored: " << (int)*(*mChar) << "\n";
		}
	};

}

#endif
