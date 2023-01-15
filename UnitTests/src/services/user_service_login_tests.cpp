#include "CppUnitTest.h"

#include "../../../Lib/src/services/user_service.hpp"
#include "../../../Lib/src/impl/memory_repository.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace lib;

namespace services
{
	TEST_CLASS(UserServiceLoginTests)
	{
	public:
		TEST_CLASS_INITIALIZE(Initialize)
		{
			_user_repository = new MemoryRepository<User>();

			_user_service = new UserService(*_user_repository);
		}

		TEST_METHOD_INITIALIZE(MethodInitialize)
		{
			_user_repository->clear();
		}

		TEST_METHOD(Can_login_with_valid_details)
		{
			_user_service->register_(username, password);			

			auto result = _user_service->login(username, password);

			Assert::IsTrue(result != nullopt);
		}

		TEST_METHOD(Cannot_login_with_invalid_username)
		{
			_user_service->register_(username, password);			

			auto result = _user_service->login("invalid_username", password);

			Assert::IsTrue(result == nullopt);
		}

		TEST_METHOD(Cannot_login_with_invalid_password)
		{
			_user_service->register_(username, password);			

			auto result = _user_service->login(username, "invalid_password");

			Assert::IsTrue(result == nullopt);
		}

	private:
		static inline String
			username = "username",
			password = "password";

		static inline IRepository<User>* _user_repository;
		static inline UserService* _user_service;
	};
}