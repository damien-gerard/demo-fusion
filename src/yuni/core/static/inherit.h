#ifndef __YUNI_CORE_STATIC_INHERIT_H__
# define __YUNI_CORE_STATIC_INHERIT_H__

# include "../../yuni.h"


namespace Yuni
{
namespace Static
{

	/*!
	** \brief Statically check if an arbitrary class C is a descendant of another one
	**
	** \code
	** #include <yuni/static/inherit.h>
	** #include <iostream>
	**
	** class Base {};
	**
	** class A : public Base {};
	**
	** class B {};
	**
	** int main()
	** {
	**	std::cout << "A inherits from Base :" << Yuni::Static::InheritsFrom<A,Base>::Yes << "\n";
	**	std::cout << "B inherits from Base :" << Yuni::Static::InheritsFrom<B,Base>::Yes << "\n";
	**	return 0;
	** }
	** \endcode
	**
	** \tparam C Any class (may be virtual)
	** \tparam BaseT The base class to compare with (may be virtual)
	*/
	template<class C, class BaseT>
	class InheritsFrom final
	{
	private:
		typedef int   TrueType;
		typedef char  FalseType;

		// C obviously inherits from BaseT
		static TrueType  deduce(const BaseT*);
		// C does not inherits from BaseT
		static FalseType deduce(...);
		// A dummy routine, for returning a type C
		static C* Helper();

	public:
		enum
		{
			//! A non-zero value if C inherits from BaseT
			Yes = sizeof(deduce(Helper())) == sizeof(TrueType),
			//! A non-zero value if C does not inherit from BaseT
			No = sizeof(deduce(Helper())) == sizeof(FalseType),
		};
	}; // class InheritsFrom





} // namespace Static
} // namespace Yuni

#endif // __YUNI_CORE_STATIC_INHERIT_H__
