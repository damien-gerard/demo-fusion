#ifndef __YUNI_CORE_STATIC_HAS_METHOD_H__
# define __YUNI_CORE_STATIC_HAS_METHOD_H__

# include "../../yuni.h"
# include "remove.h"


/*!
** \def YUNI_IMPL_STATIC_HAS_METHOD
** \brief Macro for implementing a check for Determining whether a class has a specific typedef or not
**
** \bug The signature is not checked in C++11
*/
# if !defined(YUNI_HAS_CPP_KEYWORD_FINAL)

// No keyword final, thus we always can inherit from the given Type

# define YUNI_IMPL_STATIC_HAS_METHOD(METHOD, RETURN_TYPE, ...)  \
		template<class T> \
		class METHOD final \
		{ \
			typedef struct {char a[2];}   TrueType; \
			typedef char  FalseType; \
			typedef typename ::Yuni::Static::Remove::All<T>::Type  Type; \
			\
			typedef RETURN_TYPE  ReturnType; \
			struct BaseMixin { ReturnType  METHOD __VA_ARGS__ { return RETURN_TYPE(); } }; \
			struct Base : public Type, public BaseMixin {}; \
			template<class C, C> struct Identity ;\
			\
			template<class C, class U> static TrueType deduce(C*, U C::* = 0); \
			template<class C> static FalseType deduce(...); \
			\
			template<class C> static FalseType  deduce(C*, Identity<RETURN_TYPE (BaseMixin::*)__VA_ARGS__, &C::METHOD>* = 0); \
			static TrueType deduce(...); \
			\
		public: \
			enum \
			{ \
				yes = sizeof(deduce((Base*) 0)) == sizeof(TrueType), \
				no = !yes, \
			}; \
		}


# else

# include <type_traits>

# define YUNI_IMPL_STATIC_HAS_METHOD(METHOD, RETURN_TYPE, ...)  \
		template<class T> \
		class METHOD final \
		{ \
			typedef struct {char a[2];}   TrueType; \
			typedef char  FalseType; \
			typedef typename ::Yuni::Static::Remove::All<T>::Type  Type; \
			template<int> struct Helper; \
			template<class C, C> struct Identity ;\
			\
			template<class C> static TrueType  deduce(C*, Helper<std::is_member_function_pointer<decltype(&C::METHOD)>::value>* = 0); \
			template<class C> static FalseType deduce(...); \
			\
		public: \
			enum \
			{ \
				yes = sizeof(deduce<Type>(0)) == sizeof(TrueType), \
				no =  ! yes, \
			}; \
		}


# endif



namespace Yuni
{
namespace Static
{
namespace HasMethod
{

	/*!
	** \brief Determine whether a class has the method `addRef`
	*/
	YUNI_IMPL_STATIC_HAS_METHOD(addRef, void, ());


	/*!
	** \brief Determine whether a class has the method `release`
	*/
	YUNI_IMPL_STATIC_HAS_METHOD(release, bool, ());


	/*!
	** \brief Determine whether a class has the method `hasIntrusiveSmartPtr`
	*/
	YUNI_IMPL_STATIC_HAS_METHOD(hasIntrusiveSmartPtr, bool, ());






} // namespace HasMethod
} // namespace Static
} // namespace Yuni

#endif // __YUNI_CORE_STATIC_HAS_METHOD_H__
