#pragma once

#include "../core/defs.hpp"

namespace lib
{
	struct User
	{
		User(const String& name, const String& password)
			: name(name), password(password)
		{
		}

		int id{};

		String name;

		String password;
	};
}