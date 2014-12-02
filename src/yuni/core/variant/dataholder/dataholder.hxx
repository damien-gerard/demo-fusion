#ifndef __YUNI_CORE_VARIANT_VARIANT_DATAHOLDER_HXX__
#define __YUNI_CORE_VARIANT_VARIANT_DATAHOLDER_HXX__



namespace Yuni
{
namespace Private
{
namespace Variant
{

	/*!
	** \brief Specialisation for Bool to String.
	*/
	template<>
	struct Converter<bool, String> final
	{
		// Please use Yuni::String << bool
		static bool Value(const bool& from, String& to)
		{
			to = (from) ? "true" : "false";
			return true;
		}
	};


	template<class T> inline T IDataHolder::to() const
	{
		DataConverter<T> dc;
		convertUsing(dc);
		return dc.result;
	}


	template<class T> inline bool IDataHolder::to(T& out) const
	{
		DataConverter<T> dc;
		if (convertUsing(dc))
		{
			out = dc.result;
			return true;
		}
		out = T();
		return false;
	}






} // namespace Variant
} // namespace Private
} // namespace Yuni

#endif // __YUNI_CORE_VARIANT_VARIANT_DATAHOLDER_HXX__
