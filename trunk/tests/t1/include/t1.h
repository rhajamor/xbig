
#include <string>


#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

/** Test namespace t1.
 */

namespace t1 
{
   /** Nested namespace t11.
    */

   namespace t11
   {
     
     /** Test class T1.
      * 
      */
     class EXPORT T1  {
  
      public:

        /** Default Constructor.
         */
        T1();
      
        /** Constructor (int).
         */
        T1(int i);
      
        /** Constructor (int, unsigned int).
         */
        T1(int i, unsigned int u);
      
        /** Constructor (int, unsigned int, string).
         */
        T1(int i, unsigned int u, const std::string& str);
      
        /** Simple output function.
         */
        void print() const;
        
        /** Test of setting string.
         */
        void setString(const std::string& str);
        
        /** Test of getting string.
         */
        const std::string& getString() const;
        
        /** Test of setting integer value.
         */
        void setInteger(signed int value);
        
        /** Test of getting integer value.
         */
        int getInteger() const;
        
        /** Test of setting unsigned integer value.
         */
        void setUnsignedInteger(const unsigned int& value);        

        /** Test of getting unsigned integer value.
         */
        unsigned int getUnsignedInteger() const;
        
        /** Returns the name of this class
         */
        static const char* getClassName();
        
      private:
        int 		    _test_int;
        unsigned int 	_test_uint;
        std::string     _test_string;
     };
   }
  
   
}
