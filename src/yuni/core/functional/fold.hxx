#ifndef __YUNI_CORE_FUNCTIONAL_FOLD_HXX__
# define __YUNI_CORE_FUNCTIONAL_FOLD_HXX__

# include "view.h"


namespace Yuni
{



	template<class ResultT, class CollectionT, class AccumulatorT>
	ResultT fold(const CollectionT& collection, const ResultT& initval, const AccumulatorT& callback)
	{
		return makeView(collection).fold(initval, callback);
	}




} // namespace Yuni

#endif // __YUNI_CORE_FUNCTIONAL_FOLD_HXX__
