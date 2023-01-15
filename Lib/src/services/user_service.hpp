#pragma once

#include <functional>

#include "../core/defs.hpp"
#include "../core/repository.hpp"
#include "../extensions/core/repository_extensions.hpp"
#include "../models/user.hpp"

namespace lib
{
	class UserService
	{
	public:
	
		UserService(IRepository<User>& user_repository)
			: _user_repository(user_repository)
		{
		}

		bool register_(const String& username, const String& password)
		{
			if(get_by_name(_user_repository, username))
				return false;

			if(username.length() < username_minimum_length)
				return false;

			return _user_repository.create({username, password});
		}

		Optional<UserToken> login(const String& username, const String& password)
		{
			if(auto user = get_by_name(_user_repository, username); user)
				if(user->password == password)
					return user->name + ":" + user->password;

			return nullopt;
		}

	private:
		
		IRepository<User>& _user_repository;
	};
}