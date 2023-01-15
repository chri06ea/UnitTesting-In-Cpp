#include "CppUnitTest.h"

#include "../../../Lib/src/services/user_service.hpp"
#include "../../../Lib/src/impl/memory_repository.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace lib;

namespace services
{
	TEST_CLASS(UserServiceRegisterTests)
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

		TEST_METHOD(Can_register_with_valid_details)
		{
			auto result = _user_service->register_(username, password);

			Assert::IsTrue(result);
		}

		TEST_METHOD(Cannot_register_with_existing_username)
		{
			_user_service->register_(username, password);

			auto result = _user_service->register_(username, password);

			Assert::IsFalse(result);
		}

		TEST_METHOD(Cannot_register_with_username_less_than_3_characters)
		{
			auto result = _user_service->register_("ab", password);

			Assert::IsFalse(result);
		}

	private:
		static inline String
			username = "username",
			password = "password";

		static inline IRepository<User>* _user_repository;
		static inline UserService* _user_service;
	};
}