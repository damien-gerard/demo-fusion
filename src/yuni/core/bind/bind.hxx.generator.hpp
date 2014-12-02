#ifndef __YUNI_CORE_BIND_BIND_HXX__
# define __YUNI_CORE_BIND_BIND_HXX__

<%
require File.dirname(__FILE__) + '/../../../tools/generators/commons.rb'
generator = Generator.new()
%>
<%=generator.thisHeaderHasBeenGenerated("bind.hxx.generator.hpp")%>




namespace Yuni
{


<%
(0..(generator.argumentCount)).each do |i|
[ ["class R" + generator.templateParameterList(i), "R ("+generator.list(i) + ")", "void"],
  ["class R" + generator.templateParameterList(i), "R (*)(" + generator.list(i) + ")", "void"],
  ["class ClassT, class R" + generator.templateParameterList(i), "R (ClassT::*)(" + generator.list(i) + ")", "ClassT"] ].each do |tmpl|

%>

	// Constructor
	template<<%=tmpl[0]%>>
	inline Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::Bind()
		: pHolder(new Private::BindImpl::None<R (<%=generator.list(i)%>)>()) // unbind
	{}

	// Constructor
	template<<%=tmpl[0]%>>
	inline Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::Bind(const Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>& rhs) :
		pHolder(rhs.pHolder)
	{}

	# ifdef YUNI_HAS_CPP_MOVE
	// Move Constructor
	template<<%=tmpl[0]%>>
	inline Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::Bind(Bind&& rhs)
	{
		// \important VS may call the other constructor `C&&`...
		pHolder.swap(rhs.pHolder);
	}
	# endif

	// Constructor
	template<<%=tmpl[0]%>>
	inline Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>
	Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::FromSymbol(const Yuni::DynamicLibrary::Symbol& symbol)
	{
		BindType result;
		result.bindFromSymbol(symbol);
		return result;
	}

	# ifdef YUNI_HAS_CPP_BIND_LAMBDA
	// Constructor from a functor
	template<<%=tmpl[0]%>>
	template<class C>
	inline Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::Bind(C&& functor)
	{
		// When moving a bind (instead of copying it), it seems that Visual Studio might call
		// this constructor instead of `Bind&&` (works as expected with gcc and clang)
		if (Static::Type::Equal<C, BindType>::Yes) // moving Bind&& -> Bind&&
		{
			// instanciating the swap method only when the type requires it
			Yuni::Private::BindImpl::MoveConstructor<Static::Type::Equal<C, BindType>::Yes>::SwapBind(pHolder, functor);
		}
		else
			pHolder = new Private::BindImpl::BoundWithFunctor<C, R (<%=generator.list(i)%>)>(std::forward<C>(functor));
	}

	# else

	// Constructor: Pointer-to-function
	template<<%=tmpl[0]%>>
	inline Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::Bind(R (*pointer)(<%=generator.list(i)%>))
	{
		bind(pointer);
	}

	# endif

	// Constructor: pointer-to-member
	template<<%=tmpl[0]%>>
	template<class C>
	inline Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::Bind(C* c, R (C::*member)(<%=generator.list(i)%>))
	{
		bind(c, member);
	}




	// Bind: Pointer-to-function
	template<<%=tmpl[0]%>>
	inline void Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::bind(R (*pointer)(<%=generator.list(i)%>))
	{
		pHolder = new Private::BindImpl::BoundWithFunction<R (<%=generator.list(i)%>)>(pointer);
	}


	// Bind: Pointer-to-function (from a library symbol)
	template<<%=tmpl[0]%>>
	inline void Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::bindFromSymbol(const Yuni::DynamicLibrary::Symbol& symbol)
	{
		if (symbol.valid())
		{
			pHolder = new Private::BindImpl::BoundWithFunction<R (<%=generator.list(i)%>)>(
				reinterpret_cast<FunctionType>(symbol.ptr()));
		}
		else
			unbind();
	}

	// Bind: Pointer-to-function + user data
	template<<%=tmpl[0]%>>
	template<class U>
	inline void Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::bind(R (*pointer)(<%=generator.list(i, "A", "", ", ")%>U),
		typename Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::template WithUserData<U>::ParameterType userdata)
	{
		pHolder = new Private::BindImpl::BoundWithFunctionAndUserData
			<typename WithUserData<U>::ParameterType, R (<%=generator.list(i, "A", "", ", ")%>U)>(pointer, userdata);
	}


	# ifdef YUNI_HAS_CPP_BIND_LAMBDA
	// Bind: functor
	template<<%=tmpl[0]%>>
	template<class C>
	inline void Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::bind(C&& functor)
	{
		// When moving a bind (instead of copying it), it seems that Visual Studio might call
		// this constructor instead of `Bind&&` (works as expected with gcc and clang)
		if (Static::Type::Equal<C, BindType>::Yes) // moving Bind&& -> Bind&&
		{
			// instanciating the swap method only when the type requires it
			Yuni::Private::BindImpl::MoveConstructor<Static::Type::Equal<C, BindType>::Yes>::SwapBind(pHolder, functor);
		}
		else
			pHolder = new Private::BindImpl::BoundWithFunctor<C, R (<%=generator.list(i)%>)>(std::forward<C>(functor));
	}
	# endif


	// Bind: pointer-to-member
	template<<%=tmpl[0]%>>
	template<class C>
	void Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::bind(C* c, R (C::*member)(<%=generator.list(i)%>))
	{
		if (c)
		{
			// The object is not null, go ahead
			// Assigning a new bind
			pHolder = new Private::BindImpl::BoundWithMember<C, R(<%=generator.list(i)%>)>(c, member);
		}
		else
			// The object is null, we should unbind
			unbind();
	}


	// Bind: pointer-to-member const
	template<<%=tmpl[0]%>>
	template<class C>
	void Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::bind(const C* c, R (C::*member)(<%=generator.list(i)%>) const)
	{
		if (c)
		{
			// The object is not null, go ahead
			// Assigning a new bind
			typedef R (C::*MemberType)(<%=generator.list(i)%>);
			pHolder = new Private::BindImpl::BoundWithMember<C, R(<%=generator.list(i)%>)>
				(const_cast<C*>(c), reinterpret_cast<MemberType>(member));
		}
		else
			// The object is null, we should unbind
			unbind();
	}


	// Bind: pointer-to-member const
	template<<%=tmpl[0]%>>
	template<class C,
		template <class> class OwspP, template <class> class ChckP, class ConvP,
		template <class> class StorP, template <class> class ConsP>
	inline void
	Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::bind(const SmartPtr<C, OwspP,ChckP,ConvP,StorP,ConsP>& c, R (C::*member)(<%=generator.list(i)%>))
	{
		if (!(!c))
		{
			// The object is not null, go ahead
			// Assigning a new bind
			typedef R (C::*MemberType)(<%=generator.list(i)%>);
			typedef SmartPtr<C, OwspP,ChckP,ConvP,StorP,ConsP> PtrT;
			pHolder = new Private::BindImpl::BoundWithSmartPtrMember<PtrT, R(<%=generator.list(i)%>)>
				(c, reinterpret_cast<MemberType>(member));
		}
		else
			// The object is null, we should unbind
			unbind();
	}


	// Bind: pointer-to-member const
	template<<%=tmpl[0]%>>
	template<class C,
		template <class> class OwspP, template <class> class ChckP, class ConvP,
		template <class> class StorP, template <class> class ConsP>
	inline void
	Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::bind(const SmartPtr<C, OwspP,ChckP,ConvP,StorP,ConsP>& c, R (C::*member)(<%=generator.list(i)%>) const)
	{
		if (!(!c))
		{
			// The object is not null, go ahead
			// Assigning a new bind
			typedef R (C::*MemberType)(<%=generator.list(i)%>);
			typedef SmartPtr<C, OwspP,ChckP,ConvP,StorP,ConsP> PtrT;
			pHolder = new Private::BindImpl::BoundWithSmartPtrMember<PtrT, R(<%=generator.list(i)%>)>
				(c, reinterpret_cast<MemberType>(member));
		}
		else
			// The object is null, we should unbind
			unbind();
	}


	// Bind: pointer-to-member const
	template<<%=tmpl[0]%>>
	template<class U, class C,
		template <class> class OwspP, template <class> class ChckP, class ConvP,
		template <class> class StorP, template <class> class ConsP>
	inline void
	Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::bind(const SmartPtr<C, OwspP,ChckP,ConvP,StorP,ConsP>& c, R (C::*member)(<%=generator.list(i,"A", "", ", ")%>U),
		typename Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::template WithUserData<U>::ParameterType userdata)
	{
		if (!(!c))
		{
			// The object is not null, go ahead
			// Assigning a new bind
			typedef SmartPtr<C, OwspP,ChckP,ConvP,StorP,ConsP> PtrT;
			pHolder = new Private::BindImpl::BoundWithSmartPtrMemberAndUserData<
				typename WithUserData<U>::ParameterType, PtrT, R(<%=generator.list(i,"A","",", ")%>U)>
				(c, member, userdata);
		}
		else
			// The object is null, we should unbind
			unbind();
	}


	// Bind: pointer-to-member const
	template<<%=tmpl[0]%>>
	template<class U, class C,
		template <class> class OwspP, template <class> class ChckP, class ConvP,
		template <class> class StorP, template <class> class ConsP>
	inline void
	Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::bind(const SmartPtr<C, OwspP,ChckP,ConvP,StorP,ConsP>& c, R (C::*member)(<%=generator.list(i,"A", "", ", ")%>U) const,
		typename Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::template WithUserData<U>::ParameterType userdata)
	{
		if (!(!c))
		{
			// The object is not null, go ahead
			// Assigning a new bind
			typedef SmartPtr<C, OwspP,ChckP,ConvP,StorP,ConsP> PtrT;
			pHolder = new Private::BindImpl::BoundWithSmartPtrMemberAndUserData<
				typename WithUserData<U>::ParameterType, PtrT, R(<%=generator.list(i,"A","",", ")%>U)>
				(c, member, userdata);
		}
		else
			// The object is null, we should unbind
			unbind();
	}


	template<<%=tmpl[0]%>>
	template<class U, class C>
	void Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::bind(C* c, R (C::*member)(<%=generator.list(i,"A","",", ")%>U),
		typename Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::template WithUserData<U>::ParameterType userdata)
	{
		if (c)
		{
			// The object is not null, go ahead
			// Assigning a new bind
			pHolder = new Private::BindImpl::BoundWithMemberAndUserData<
				typename WithUserData<U>::ParameterType,C, R(<%=generator.list(i,"A","",", ")%>U)>
				(c, member, userdata);
		}
		else
			// The object is null, we should unbind
			unbind();
	}


	template<<%=tmpl[0]%>>
	template<class U, class C>
	void Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::bind(const C* c, R (C::*member)(<%=generator.list(i,"A","",", ")%>U) const,
		typename Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::template WithUserData<U>::ParameterType userdata)
	{
		if (c)
		{
			// The object is not null, go ahead
			// Assigning a new bind
			typedef R (C::*MemberType)(<%=generator.list(i,"A","",", ")%>U);
			pHolder = new Private::BindImpl::BoundWithMemberAndUserData<
				typename WithUserData<U>::ParameterType,C, R(<%=generator.list(i,"A","",", ")%>U)>
				(const_cast<C*>(c), reinterpret_cast<MemberType>(member), userdata);
		}
		else
			// The object is null, we should unbind
			unbind();
	}


	template<<%=tmpl[0]%>>
	inline void Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::bind(const Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>& rhs)
	{
		// Inc the reference count
		pHolder = rhs.pHolder;
	}


	// Bind: unbind
	template<<%=tmpl[0]%>>
	inline void Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::unbind()
	{
		pHolder = new Private::BindImpl::None<R (<%=generator.list(i)%>)>(); // unbind
	}


	// Bind: unbind
	template<<%=tmpl[0]%>>
	inline void Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::clear()
	{
		unbind();
	}


	template<<%=tmpl[0]%>>
	inline bool Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::empty() const
	{
		return pHolder->empty();
	}


	template<<%=tmpl[0]%>>
	template<class UserTypeT, template<class UserTypeGT, class ArgumentIndexTypeT> class ArgGetterT>
	inline R
	Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::callWithArgumentGetter(UserTypeT userdata) const
	{
		(void) userdata;
		return invoke(<%=
			ret = ''
			(0..i-1).each do |j|
				if j > 0
					ret += ', '
				end
				if ((j + 1).modulo(2) == 0)
					ret += "\n\t\t\t\t"
				end

				ret += "ArgGetterT<UserTypeT, A" + j.to_s + ">::Get(userdata, " + j.to_s + ")"
			end
			ret %>);
	}




	template<<%=tmpl[0]%>>
	inline R Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::invoke(<%=generator.variableList(i)%>) const
	{
		return pHolder->invoke(<%=generator.list(i,'a')%>);
	}


	template<<%=tmpl[0]%>>
	inline bool Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::operator ! () const
	{
		return empty();
	}


	template<<%=tmpl[0]%>>
	inline R Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::operator () (<%=generator.variableList(i)%>) const
	{
		return pHolder->invoke(<%=generator.list(i,'a')%>);
	}


	template<<%=tmpl[0]%>>
	inline R Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::emptyCallback(<%=generator.list(i,"A")%>)
	{
		return R();
	}

	template<<%=tmpl[0]%>>
	inline const void* Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::object() const
	{
		return pHolder->object();
	}

	template<<%=tmpl[0]%>>
	inline const IEventObserverBase* Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::observerBaseObject() const
	{
		return pHolder->observerBaseObject();
	}

	template<<%=tmpl[0]%>>
	inline bool Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::isDescendantOf(const IEventObserverBase* obj) const
	{
		return pHolder->isDescendantOf(obj);
	}

	template<<%=tmpl[0]%>>
	inline bool Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::isDescendantOfIEventObserverBase() const
	{
		return pHolder->isDescendantOfIEventObserverBase();
	}


	template<<%=tmpl[0]%>>
	inline void Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::print(std::ostream& out) const
	{
		return pHolder->print(out);
	}



	template<<%=tmpl[0]%>>
	inline void Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::emptyCallbackReturnsVoid(<%=generator.list(i,"A")%>)
	{
		/* Do nothing */
	}






	template<<%=tmpl[0]%>>
	inline Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>& Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::operator = (R (*pointer)(<%=generator.list(i)%>))
	{
		bind(pointer);
		return *this;
	}


	template<<%=tmpl[0]%>>
	inline Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>& Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::operator = (const Yuni::DynamicLibrary::Symbol& symbol)
	{
		bind(symbol);
		return *this;
	}


	template<<%=tmpl[0]%>>
	inline Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>& Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::operator = (const Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>& rhs)
	{
		// Inc the reference count
		pHolder = rhs.pHolder;
		return *this;
	}


	# ifdef YUNI_HAS_CPP_BIND_LAMBDA
	template<<%=tmpl[0]%>>
	template<class C>
	inline Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>& Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::operator = (C&& functor)
	{
		// Inc the reference count
		pHolder = new Private::BindImpl::BoundWithFunctor<C, R (<%=generator.list(i)%>)>(std::forward<C>(functor));
		return *this;
	}
	# endif


	# ifdef YUNI_HAS_CPP_MOVE
	template<<%=tmpl[0]%>>
	inline Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>& Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::operator = (Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>&& rhs)
	{
		pHolder.swap(rhs.pHolder);
		return *this;
	}
	# endif

	template<<%=tmpl[0]%>>
	inline bool Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::operator == (R (*pointer)(<%=generator.list(i)%>)) const
	{
		return pHolder->compareWithPointerToFunction(pointer);
	}

	template<<%=tmpl[0]%>>
	template<class U>
	inline bool Bind<<%=tmpl[1]%>, <%=tmpl[2]%>>::operator == (const U* object) const
	{
		return pHolder->compareWithPointerToObject(static_cast<const void*>(object));
	}




<% end end %>

} // namespace Yuni

#endif // __YUNI_CORE_BIND_BIND_H__
