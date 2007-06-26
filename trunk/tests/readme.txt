XBiG test cases
====================

t1: template for tests

t2: classes
	t2_1: empty class
	t2_2: class with public attribute
	t2_3: class with method
	t2_4: method with references
	t2_5: method with pointers
	t2_6: class with inner class
	t2_7: static members
	t2_8: objects and std::string
	t2_9: method overloading
	
t3: structs
	t3_1: empty struct
	t3_2: struct with public attribute
	t3_3: struct with method
	t3_4: method with references
	t3_5: method with pointers
	t3_6: class with inner struct
	t3_7: struct with inner struct
	t3_8: struct with inner class
	t3_9: struct inside namespace

t4: namespaces
	t4_1: one namespace
	t4_2: nested namespaces
	t4_3: typeresolving over many namespaces

t5: inheritance
	t5_1: single inheritance
	t5_2: multiple inheritance
	t5_3: inheritance with pure virtual method
	t5_4: diamond problem
	t5_5: inheritance tree with three levels
	t5_6: inherited inner types

t6: templates
	t6_1: template class
	t6_2: template struct
	t6_3: template class with two parameters
	t6_4: template class with two parameters in different namespaces

t7: typedefs
	t7_1: typedef for primitive type
	t7_2: typedef for class
	t7_3: typedef for struct
	t7_4: typedef for template class
	t7_5: typedef for template struct
	t7_6: typedef as inner type

t8: const
	t8_1: pass by value and one const per method
	t8_2: const overloading
	t8_3: const references
	t8_4: const pointers

t9: enums
	t9_1: global enum without initializer
	t9_2: global enum with initializer
	t9_3: enum inside namespaces
	t9_4: enums as return types
	t9_5: unnamed enums

t10: global functions
	t10_1: single global function
	t10_2: global functions with different types

t11: global variables
	t11_1: global function

t12: pointer pointer
	t12_1: objects
	t12_2: primitive types

t13: external types
	t13_1: typedef for an external type
	t13_2: Ogre::VectorIterator
	t13_3: Ogre::MapIterator
	t13_4: typedefs for STL wrapper
	t13_5: pointer as type parameter
	t13_6: const pointer as type parameter
	t13_7: protected type as template parameter in public typedef
	t13_8: long as default mapping for unresolved types in native methods (fails but is considered successful)

t14: arrays
	t14_1: arrays as parameters
