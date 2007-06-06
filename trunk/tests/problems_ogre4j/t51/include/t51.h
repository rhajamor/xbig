
#ifndef __T51_H__
#define __T51_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * pointer as type parameter, see bug 1728969
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <list>
#include <map>


namespace Ogre {

	class EXPORT RenderQueue {};
	class EXPORT Particle {};

	typedef float Real;
	typedef std::list< Particle * > ParticlePtrList;
	typedef std::list< int *> IntPtrList;

	class EXPORT BillboardParticleRenderer  {
	public:
		void _updateRenderQueue(RenderQueue *queue, std::list< Particle * > &currentParticles, bool cullIndividually) {}

		void constTypePara(std::list< const Particle >){}
		void constTypeParaPtr(std::list< const Particle* >){}
		void templatePtr(std::list< Particle >*){}
		void templatePtrWithConstTypeParaPtr(std::list< const Particle* >*){}
		void constTypeParaConst(const std::list< const Particle >){}
		void constTypeParaPtrConst(const std::list< const Particle* >){}
		void templatePtrConst(const std::list< Particle >*){}
		void templatePtrWithConstTypeParaPtrConst(const std::list< const Particle* >*){}

		void primitiveTypePtrAsTypeParameter(std::list< int *>){}
		void primitiveTypePtrAsTypeParameterTemplatePtr(std::list< int *> *){}
		void primitiveTypePtrTypedefAsTypeParameter(std::list< Real *>){}
		void primitiveTypePtrTypedefAsTypeParameterTemplatePtr(std::list< Real *> *){}
		void constPrimitiveTypePtrAsTypeParameter(std::list< const int *>){}
		void constPrimitiveTypePtrAsTypeParameterTemplatePtr(std::list< const int *> *){}
		void constPrimitiveTypePtrTypedefAsTypeParameter(std::list< const Real *>){}
		void constPrimitiveTypePtrTypedefAsTypeParameterTemplatePtr(std::list< const Real *> *){}

		void twoTypeParametersAsPtr(std::map<int*, Particle*>){}
		void twoTypeParametersAsPtrConst(std::map<const int*, const Particle*>){}
		void ptrTwoTypeParametersAsPtr(std::map<int*, Particle*>*){}
		void ptrTwoTypeParametersAsPtrConst(std::map<const int*, const Particle*>*){}
		void ptrTwoTypeParameters(std::map< int, Particle>*){}
		void ptrTwoTypeParametersConst(std::map<const int, const Particle>*){}

		void typeParameterWithOwnTypeParametersAsPtr(std::map<int*, std::pair<Real, std::list<int> >* >){}
		void typeParameterWithOwnTypeParametersMapPtr(std::map<int, std::pair<Real, std::list<int> > >*){}
		void typeParameterWithOwnTypeParametersAllPtr(std::map<int*, std::pair<Real*, std::list<int*> >* >*){}

		void typeParameterWithOwnTypeParametersAsPtrSameConst(std::map<const int*, const std::pair<Real, std::list<int> >* >){}
		void typeParameterWithOwnTypeParametersAsPtrOtherConst(const std::map<int*, std::pair<const Real, const std::list<const int> >* >){}
		void typeParameterWithOwnTypeParametersAllPtrConst(const std::map<const int*, const std::pair<const Real*, const std::list<const int*> >* >*){}
	};
}

#endif
