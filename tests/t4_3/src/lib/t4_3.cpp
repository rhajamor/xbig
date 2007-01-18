

#include "t4_3.h"

A* g_ptr = 0;
n::A* n_ptr = 0;
n::m::A* m_ptr = 0;
o::A* o_ptr = 0;
o::p::A* p_ptr = 0;
o::p::q::A* q_ptr = 0;
o::n::A* on_ptr = 0;

A C::getG() {
	if (g_ptr == 0)
		g_ptr = new ::A;
	return *g_ptr;
}
n::A C::getN() {
	if (n_ptr == 0)
		n_ptr = new n::A;
	return *n_ptr;
}
n::m::A C::getM() {
	if (m_ptr == 0)
		m_ptr = new n::m::A;
	return *m_ptr;
}
o::A C::getO() {
	if (o_ptr == 0)
		o_ptr = new o::A;
	return *o_ptr;
}
o::p::A C::getP() {
	if (p_ptr == 0)
		p_ptr = new o::p::A;
	return *p_ptr;
}
o::p::q::A C::getQ() {
	if (q_ptr == 0)
		q_ptr = new o::p::q::A;
	return *q_ptr;
}
o::n::A C::getON() {
	if (on_ptr == 0)
		on_ptr = new o::n::A;
	return *on_ptr;
}
C::~C() {
	if (g_ptr != 0) { delete g_ptr; g_ptr = 0;}
	if (n_ptr != 0) { delete n_ptr; n_ptr = 0;}
	if (m_ptr != 0) { delete m_ptr; m_ptr = 0;}
	if (o_ptr != 0) { delete o_ptr; o_ptr = 0;}
	if (p_ptr != 0) { delete p_ptr; p_ptr = 0;}
	if (q_ptr != 0) { delete q_ptr; q_ptr = 0;}
	if (on_ptr != 0) { delete on_ptr; on_ptr = 0;}
}

A n::C::getG() {
	if (g_ptr == 0)
		g_ptr = new ::A;
	return *g_ptr;
}
n::A n::C::getN() {
	if (n_ptr == 0)
		n_ptr = new n::A;
	return *n_ptr;
}
n::m::A n::C::getM() {
	if (m_ptr == 0)
		m_ptr = new n::m::A;
	return *m_ptr;
}
o::A n::C::getO() {
	if (o_ptr == 0)
		o_ptr = new o::A;
	return *o_ptr;
}
o::p::A n::C::getP() {
	if (p_ptr == 0)
		p_ptr = new o::p::A;
	return *p_ptr;
}
o::p::q::A n::C::getQ() {
	if (q_ptr == 0)
		q_ptr = new o::p::q::A;
	return *q_ptr;
}
o::n::A n::C::getON() {
	if (on_ptr == 0)
		on_ptr = new o::n::A;
	return *on_ptr;
}
n::C::~C() {
	if (g_ptr != 0) { delete g_ptr; g_ptr = 0;}
	if (n_ptr != 0) { delete n_ptr; n_ptr = 0;}
	if (m_ptr != 0) { delete m_ptr; m_ptr = 0;}
	if (o_ptr != 0) { delete o_ptr; o_ptr = 0;}
	if (p_ptr != 0) { delete p_ptr; p_ptr = 0;}
	if (q_ptr != 0) { delete q_ptr; q_ptr = 0;}
	if (on_ptr != 0) { delete on_ptr; on_ptr = 0;}
}

A n::m::C::getG() {
	if (g_ptr == 0)
		g_ptr = new ::A;
	return *g_ptr;
}
n::A n::m::C::getN() {
	if (n_ptr == 0)
		n_ptr = new n::A;
	return *n_ptr;
}
n::m::A n::m::C::getM() {
	if (m_ptr == 0)
		m_ptr = new n::m::A;
	return *m_ptr;
}
o::A n::m::C::getO() {
	if (o_ptr == 0)
		o_ptr = new o::A;
	return *o_ptr;
}
o::p::A n::m::C::getP() {
	if (p_ptr == 0)
		p_ptr = new o::p::A;
	return *p_ptr;
}
o::p::q::A n::m::C::getQ() {
	if (q_ptr == 0)
		q_ptr = new o::p::q::A;
	return *q_ptr;
}
o::n::A n::m::C::getON() {
	if (on_ptr == 0)
		on_ptr = new o::n::A;
	return *on_ptr;
}
n::m::C::~C() {
	if (g_ptr != 0) { delete g_ptr; g_ptr = 0;}
	if (n_ptr != 0) { delete n_ptr; n_ptr = 0;}
	if (m_ptr != 0) { delete m_ptr; m_ptr = 0;}
	if (o_ptr != 0) { delete o_ptr; o_ptr = 0;}
	if (p_ptr != 0) { delete p_ptr; p_ptr = 0;}
	if (q_ptr != 0) { delete q_ptr; q_ptr = 0;}
	if (on_ptr != 0) { delete on_ptr; on_ptr = 0;}
}

A o::C::getG() {
	if (g_ptr == 0)
		g_ptr = new ::A;
	return *g_ptr;
}
::n::A o::C::getN() {
	if (n_ptr == 0)
		n_ptr = new ::n::A;
	return *n_ptr;
}
::n::m::A o::C::getM() {
	if (m_ptr == 0)
		m_ptr = new ::n::m::A;
	return *m_ptr;
}
o::A o::C::getO() {
	if (o_ptr == 0)
		o_ptr = new o::A;
	return *o_ptr;
}
o::p::A o::C::getP() {
	if (p_ptr == 0)
		p_ptr = new o::p::A;
	return *p_ptr;
}
o::p::q::A o::C::getQ() {
	if (q_ptr == 0)
		q_ptr = new o::p::q::A;
	return *q_ptr;
}
o::n::A o::C::getON() {
	if (on_ptr == 0)
		on_ptr = new o::n::A;
	return *on_ptr;
}
o::C::~C() {
	if (g_ptr != 0) { delete g_ptr; g_ptr = 0;}
	if (n_ptr != 0) { delete n_ptr; n_ptr = 0;}
	if (m_ptr != 0) { delete m_ptr; m_ptr = 0;}
	if (o_ptr != 0) { delete o_ptr; o_ptr = 0;}
	if (p_ptr != 0) { delete p_ptr; p_ptr = 0;}
	if (q_ptr != 0) { delete q_ptr; q_ptr = 0;}
	if (on_ptr != 0) { delete on_ptr; on_ptr = 0;}
}

A o::p::C::getG() {
	if (g_ptr == 0)
		g_ptr = new ::A;
	return *g_ptr;
}
::n::A o::p::C::getN() {
	if (n_ptr == 0)
		n_ptr = new ::n::A;
	return *n_ptr;
}
::n::m::A o::p::C::getM() {
	if (m_ptr == 0)
		m_ptr = new ::n::m::A;
	return *m_ptr;
}
o::A o::p::C::getO() {
	if (o_ptr == 0)
		o_ptr = new o::A;
	return *o_ptr;
}
o::p::A o::p::C::getP() {
	if (p_ptr == 0)
		p_ptr = new o::p::A;
	return *p_ptr;
}
o::p::q::A o::p::C::getQ() {
	if (q_ptr == 0)
		q_ptr = new o::p::q::A;
	return *q_ptr;
}
o::n::A o::p::C::getON() {
	if (on_ptr == 0)
		on_ptr = new o::n::A;
	return *on_ptr;
}
o::p::C::~C() {
	if (g_ptr != 0) { delete g_ptr; g_ptr = 0;}
	if (n_ptr != 0) { delete n_ptr; n_ptr = 0;}
	if (m_ptr != 0) { delete m_ptr; m_ptr = 0;}
	if (o_ptr != 0) { delete o_ptr; o_ptr = 0;}
	if (p_ptr != 0) { delete p_ptr; p_ptr = 0;}
	if (q_ptr != 0) { delete q_ptr; q_ptr = 0;}
	if (on_ptr != 0) { delete on_ptr; on_ptr = 0;}
}

A o::p::q::C::getG() {
	if (g_ptr == 0)
		g_ptr = new ::A;
	return *g_ptr;
}
::n::A o::p::q::C::getN() {
	if (n_ptr == 0)
		n_ptr = new ::n::A;
	return *n_ptr;
}
::n::m::A o::p::q::C::getM() {
	if (m_ptr == 0)
		m_ptr = new ::n::m::A;
	return *m_ptr;
}
o::A o::p::q::C::getO() {
	if (o_ptr == 0)
		o_ptr = new o::A;
	return *o_ptr;
}
o::p::A o::p::q::C::getP() {
	if (p_ptr == 0)
		p_ptr = new o::p::A;
	return *p_ptr;
}
o::p::q::A o::p::q::C::getQ() {
	if (q_ptr == 0)
		q_ptr = new o::p::q::A;
	return *q_ptr;
}
o::n::A o::p::q::C::getON() {
	if (on_ptr == 0)
		on_ptr = new o::n::A;
	return *on_ptr;
}
o::p::q::C::~C() {
	if (g_ptr != 0) { delete g_ptr; g_ptr = 0;}
	if (n_ptr != 0) { delete n_ptr; n_ptr = 0;}
	if (m_ptr != 0) { delete m_ptr; m_ptr = 0;}
	if (o_ptr != 0) { delete o_ptr; o_ptr = 0;}
	if (p_ptr != 0) { delete p_ptr; p_ptr = 0;}
	if (q_ptr != 0) { delete q_ptr; q_ptr = 0;}
	if (on_ptr != 0) { delete on_ptr; on_ptr = 0;}
}

A o::n::C::getG() {
	if (g_ptr == 0)
		g_ptr = new ::A;
	return *g_ptr;
}
::n::A o::n::C::getN() {
	if (n_ptr == 0)
		n_ptr = new ::n::A;
	return *n_ptr;
}
::n::m::A o::n::C::getM() {
	if (m_ptr == 0)
		m_ptr = new ::n::m::A;
	return *m_ptr;
}
o::A o::n::C::getO() {
	if (o_ptr == 0)
		o_ptr = new o::A;
	return *o_ptr;
}
o::p::A o::n::C::getP() {
	if (p_ptr == 0)
		p_ptr = new o::p::A;
	return *p_ptr;
}
o::p::q::A o::n::C::getQ() {
	if (q_ptr == 0)
		q_ptr = new o::p::q::A;
	return *q_ptr;
}
o::n::A o::n::C::getON() {
	if (on_ptr == 0)
		on_ptr = new o::n::A;
	return *on_ptr;
}
o::n::C::~C() {
	if (g_ptr != 0) { delete g_ptr; g_ptr = 0;}
	if (n_ptr != 0) { delete n_ptr; n_ptr = 0;}
	if (m_ptr != 0) { delete m_ptr; m_ptr = 0;}
	if (o_ptr != 0) { delete o_ptr; o_ptr = 0;}
	if (p_ptr != 0) { delete p_ptr; p_ptr = 0;}
	if (q_ptr != 0) { delete q_ptr; q_ptr = 0;}
	if (on_ptr != 0) { delete on_ptr; on_ptr = 0;}
}
