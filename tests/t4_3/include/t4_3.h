/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It is about type resolving
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


namespace n {
	namespace m {
		class EXPORT A {
		public:
			int get1() {return 1;}
		};
	};

	class EXPORT A {
	public:
		int get2() {return 2;}
	};
};

namespace o {
	namespace p {
		class EXPORT A {
		public:
			int get3() {return 3;}
		};

		namespace q {
			class EXPORT A {
			public:
				int get7() {return 7;}
			};
		}
	};

	class EXPORT A {
	public:
		int get4() {return 4;}
	};

	namespace n {
		class EXPORT A {
		public:
			int get6() {return 6;}
		};
	}
};

class EXPORT A {
public:
	int get5() {return 5;}
};


namespace n {
	namespace m {
		class EXPORT B {
		public:
			bool isG(::A a) {return 5 == a.get5();}
			bool isN(n::A a) {return 2 == a.get2();}
			bool isM(A a) {return 1 == a.get1();}
			bool isO(o::A a) {return 4 == a.get4();}
			bool isP(o::p::A a) {return 3 == a.get3();}
			bool isQ(o::p::q::A a) {return 7 == a.get7();}
			bool isON(o::n::A a) {return 6 == a.get6();}
		};
	}

	class EXPORT B {
	public:
		bool isG(::A a) {return 5 == a.get5();}
		bool isN(A a) {return 2 == a.get2();}
		bool isM(m::A a) {return 1 == a.get1();}
		bool isO(o::A a) {return 4 == a.get4();}
		bool isP(o::p::A a) {return 3 == a.get3();}
		bool isQ(o::p::q::A a) {return 7 == a.get7();}
		bool isON(o::n::A a) {return 6 == a.get6();}
	};
}

namespace o {
	namespace p {
		class EXPORT B {
		public:
			bool isG(::A a) {return 5 == a.get5();}
			bool isN(::n::A a) {return 2 == a.get2();}
			bool isM(::n::m::A a) {return 1 == a.get1();}
			bool isO(o::A a) {return 4 == a.get4();}
			bool isP(A a) {return 3 == a.get3();}
			bool isQ(q::A a) {return 7 == a.get7();}
			bool isON(n::A a) {return 6 == a.get6();}
		};

		namespace q {
			class EXPORT B {
			public:
				bool isG(::A a) {return 5 == a.get5();}
				bool isN(::n::A a) {return 2 == a.get2();}
				bool isM(::n::m::A a) {return 1 == a.get1();}
				bool isO(o::A a) {return 4 == a.get4();}
				bool isP(p::A a) {return 3 == a.get3();}
				bool isQ(A a) {return 7 == a.get7();}
				bool isON(n::A a) {return 6 == a.get6();}
			};
		}
	}

	namespace n {
		class EXPORT B {
		public:
			bool isG(::A a) {return 5 == a.get5();}
			bool isN(::n::A a) {return 2 == a.get2();}
			bool isM(::n::m::A a) {return 1 == a.get1();}
			bool isO(o::A a) {return 4 == a.get4();}
			bool isP(p::A a) {return 3 == a.get3();}
			bool isQ(p::q::A a) {return 7 == a.get7();}
			bool isON(A a) {return 6 == a.get6();}
		};
	}

	class EXPORT B {
	public:
		bool isG(::A a) {return 5 == a.get5();}
		bool isN(::n::A a) {return 2 == a.get2();}
		bool isM(::n::m::A a) {return 1 == a.get1();}
		bool isO(A a) {return 4 == a.get4();}
		bool isP(p::A a) {return 3 == a.get3();}
		bool isQ(p::q::A a) {return 7 == a.get7();}
		bool isON(n::A a) {return 6 == a.get6();}
	};
}

class EXPORT B {
public:
	bool isG(A a) {return 5 == a.get5();}
	bool isN(n::A a) {return 2 == a.get2();}
	bool isM(n::m::A a) {return 1 == a.get1();}
	bool isO(o::A a) {return 4 == a.get4();}
	bool isP(o::p::A a) {return 3 == a.get3();}
	bool isQ(o::p::q::A a) {return 7 == a.get7();}
	bool isON(o::n::A a) {return 6 == a.get6();}
};


namespace n {
	namespace m {
		class EXPORT C {
		public:
			::A getG();
			n::A getN();
			A getM();
			o::A getO();
			o::p::A getP();
			o::p::q::A getQ();
			o::n::A getON();
			virtual ~C();
		};
	}

	class EXPORT C {
	public:
		::A getG();
		A getN();
		m::A getM();
		o::A getO();
		o::p::A getP();
		o::p::q::A getQ();
		o::n::A getON();
		virtual ~C();
	};
}

namespace o {
	namespace p {
		class EXPORT C {
		public:
			::A getG();
			::n::A getN();
			::n::m::A getM();
			o::A getO();
			A getP();
			q::A getQ();
			n::A getON();
			virtual ~C();
		};

		namespace q {
			class EXPORT C {
			public:
				::A getG();
				::n::A getN();
				::n::m::A getM();
				o::A getO();
				p::A getP();
				A getQ();
				n::A getON();
				virtual ~C();
			};
		}
	}

	namespace n {
		class EXPORT C {
		public:
			::A getG();
			::n::A getN();
			::n::m::A getM();
			o::A getO();
			p::A getP();
			p::q::A getQ();
			A getON();
			virtual ~C();
		};
	}

	class EXPORT C {
	public:
		::A getG();
		::n::A getN();
		::n::m::A getM();
		A getO();
		p::A getP();
		p::q::A getQ();
		n::A getON();
		virtual ~C();
	};
}

class EXPORT C {
public:
	A getG();
	n::A getN();
	n::m::A getM();
	o::A getO();
	o::p::A getP();
	o::p::q::A getQ();
	o::n::A getON();
	virtual ~C();
};
