#pragma once

#include "../core/defs.hpp"
#include "../core/repository.hpp"

namespace lib
{
	template <typename Model>
	class MemoryRepository : public IRepository<Model>
	{
	public:
		
		virtual Model* find(Predicate<Model> predicate) override;
		
		virtual bool create(Model& entity) override;
	
	private:
	
		List<Model> _items;
	};

	template<typename Model>
	inline Model* MemoryRepository<Model>::find(Predicate<Model> predicate)
	{
		for(auto& item : _items)
			if(predicate(item))
				return &item;

		return nullptr;
	}

	template<typename Model>
	inline bool MemoryRepository<Model>::create(Model& entity)
	{
		_items.push_back(entity);
		return true;
	}
}