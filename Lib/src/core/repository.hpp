#pragma once

#include <optional>

namespace lib
{
	template <typename Model>
	class IRepository
	{
	public:
	
		virtual Model* find(Predicate<Model> predicate) = 0;

		/// <summary>
		/// Stores an entity.
		/// </summary>
		/// <param name="entity"></param>
		/// <returns></returns>
		virtual bool create(Model& entity) = 0;

		virtual void clear()
		{

		}

		bool create(const Model& entity)
		{
			auto temp = entity;
			return create(temp);
		}
	};
}