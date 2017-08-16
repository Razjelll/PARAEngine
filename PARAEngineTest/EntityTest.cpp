#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "EntitySystem\Entity.hpp"
#include <assert.h>
#include <iostream>
#include <chrono>
namespace PARAEngineTest
{
	using namespace Para;

	TEST_CLASS(EntityTest)
	{
	public:
		TEST_METHOD(AttachChildTest)
		{
			Entity* entity = new Entity(1);
			Entity* child1 = new Entity(2);
			Entity* child2 = new Entity(3);
			entity->attachChild(child1);
			entity->attachChild(child2);

			Assert::AreEqual(2, entity->getChildrenCount(), L"Do³¹czanie dziecka siê nie powiod³o",LINE_INFO());

			delete entity;
		}

		TEST_METHOD(DettachChildTest)
		{
			Entity* entity = new Entity(1);
			Entity* child1 = new Entity(2);
			Entity* child2 = new Entity(3);
			entity->attachChild(child1);
			entity->attachChild(child2);
			entity->detachChild(child1);
			Assert::AreEqual(1, entity->getChildrenCount(), L"Od³¹czanie dziecka siênie powiod³o", LINE_INFO());
			Assert::IsNull(child1->getParent(), L"Rodzic usuniêtego dziecka nie zosta³ usuniêty", LINE_INFO());
			Assert::AreEqual(child2->getID(), entity->getChildren()[0]->getID(), L"Usuniêto nie to dziecko", LINE_INFO());
			entity->detachChild(3); //usuwanie child2
			Assert::AreEqual(0, entity->getChildrenCount(), L"Od³¹czanie dziecka po ID siênie powiod³o", LINE_INFO());
			Assert::IsNull(child2->getParent(), L"Rodzic usuniêtego dziecka nie zosta³ usuniêty", LINE_INFO());
			Entity* child3 = new Entity(4, "Entity");
			entity->attachChild(child3);
			entity->detachChild("Entity");
			Assert::AreEqual(0, entity->getChildrenCount(), L"Od³¹czanie dziecka po Nazwie siênie powiod³o", LINE_INFO());
			entity->detachChild(1); //próba od³¹czenia nieistniej¹cego dziecka
			Assert::AreEqual(0, entity->getChildrenCount(), L"Od³¹czanie dziecka po Nazwie siênie powiod³o", LINE_INFO());
			Assert::IsNull(child3->getParent(), L"Rodzic usuniêtego dziecka nie zosta³ usuniêty", LINE_INFO());

			//próba usuniêcia po nieistniej¹cej nazwie
			int currentChildrenSize = entity->getChildrenCount();
			entity->detachChild("nonexistent");
			Assert::AreEqual(currentChildrenSize, entity->getChildrenCount(), L"Usuniêto po nieistniej¹cej nazwie", LINE_INFO());
			entity->attachChild(child1);
			entity->attachChild(child2);
			entity->attachChild(child3);
			entity->detachAllChildren();
			Assert::AreEqual(0, entity->getChildrenCount(), L"Od³¹czenie wszystkich dzieci nie powiod³o siê", LINE_INFO());
			Assert::IsNull(child1->getParent(), L"Rodzic usuniêtego dziecka nie zosta³ usuniêty", LINE_INFO());
			Assert::IsNull(child2->getParent(), L"Rodzic usuniêtego dziecka nie zosta³ usuniêty", LINE_INFO());
			Assert::IsNull(child3->getParent(), L"Rodzic usuniêtego dziecka nie zosta³ usuniêty", LINE_INFO());

			delete child1;
			delete child2;
			delete child3;
			delete entity;
		}

		TEST_METHOD(GetChildTest)
		{
			Entity* entity = new Entity(1);
			Entity* child1 = new Entity(2);
			Entity* child2 = new Entity(3);
			entity->attachChild(child1);
			entity->attachChild(child2);
			Entity* result = entity->getChild(3);
			Assert::IsNotNull(result, L" Nie znaleziono szukanego dziecka", LINE_INFO());
			Assert::AreEqual(child2->getID(), result->getID(), L"Zwrócono z³e dziecko", LINE_INFO());
			// wyszukiwanie nieistniej¹cego dziecka
			Entity* result2 = entity->getChild(4);
			Assert::IsNull(result2, L"Wyszukiwanie nieistniej¹cego dziecka zwróci³o dziecko", LINE_INFO());

		
			delete entity;
		}


		/*TEST_METHOD(DetachTimeTest)
		{

			Entity* entity = new Entity(0);
			std::vector<Entity*> entities;
			for (int i = 0; i < 10000; i++)
			{
				Entity* child = new Entity(i + 1);
				entity->attachChild(child);
				entities.push_back(child);
			}

			auto start = std::chrono::steady_clock::now();
			entity->getChild(2);
			auto duration = std::chrono::steady_clock::now() - start;
			
			auto milis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
			/*for (Entity* ent : entities)
			{
				delete ent;
			}
			entities.clear();*/
			
		/*delete entity;
		}*/
	};
}