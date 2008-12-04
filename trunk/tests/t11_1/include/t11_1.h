/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles global variables
 *
 * Note:
 * This test is known to cause a linker error under windows.
 ******************************************************************/

extern int a;
extern int b;
namespace l1
{
  extern int a;
  extern int b;

  namespace l2 {

     extern int a;
     extern int b;
  }

}


