#pragma once
#include "../../core/defs.hpp"
#include "../../core/repository.hpp"

namespace lib
{
	template <typename Model>
	inline Model* get_by_id(IRepository<Model>& repository, int id)
	{
		return repository.find([&](const Model& x) { return x.id == id; });
	}

	template <typename Model>
	inline Model* get_by_name(IRepository<Model>& repository, const String& name)
	{
		return repository.find([&](const Model& x) { return x.name == name; });
	}
}