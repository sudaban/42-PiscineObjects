#include <iostream>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"

int	main(void)
{
	std::cout << "================ CREATION ================" << std::endl;

	Worker			bob("Bob");
	bob.SetCoordonnee(Position(1, 2, 3));
	bob.SetStat(Statistic(5, 120));
	bob.Print();

	Worker			alice("Alice");
	alice.SetCoordonnee(Position(10, 20, 30));
	alice.SetStat(Statistic(3, 60));
	alice.Print();

	Shovel			shovel;
	Hammer			hammer;
	Hammer			extra_hammer;

	std::cout << "\n================ AGGREGATION ================" << std::endl;
	bob.GiveTool(&shovel);
	alice.GiveTool(&hammer);
	alice.GiveTool(&extra_hammer);

	alice.GiveTool(&shovel);

	Tool			*tmp = alice.TakeTool(&extra_hammer);
	if (tmp != NULL)
		bob.GiveTool(tmp);

	std::cout << "\n================ USES ================" << std::endl;
	const std::vector<Tool *>	&bob_tools = bob.GetTools();
	for (std::size_t i = 0; i < bob_tools.size(); ++i)
		bob_tools[i]->Use();

	std::cout << "\n================ BONUS: GetTool<T>() ================"
		<< std::endl;
	Shovel			*bob_shovel = bob.GetTool<Shovel>();
	if (bob_shovel != NULL)
	{
		std::cout << "Bob has a Shovel (uses=" << bob_shovel->GetNumberOfUses()
			<< ")" << std::endl;
	}
	else
		std::cout << "Bob has no Shovel" << std::endl;
	Hammer			*alice_hammer = alice.GetTool<Hammer>();
	if (alice_hammer != NULL)
	{
		std::cout << "Alice has a Hammer (uses="
			<< alice_hammer->GetNumberOfUses() << ")" << std::endl;
	}

	std::cout << "\n================ ASSOCIATION ================"
		<< std::endl;
	Workshop		dig_site("DigSite", "Shovel");
	Workshop		construction_site("ConstructionSite", "Hammer");
	Workshop		general("GeneralWorkshop");

	dig_site.RegisterWorker(&bob);
	dig_site.RegisterWorker(&alice);
	construction_site.RegisterWorker(&alice);
	construction_site.RegisterWorker(&bob);
	general.RegisterWorker(&bob);
	general.RegisterWorker(&alice);

	dig_site.Print();
	construction_site.Print();
	general.Print();

	std::cout << "\n================ WORK DAY ================" << std::endl;
	dig_site.ExecuteWorkDay();
	construction_site.ExecuteWorkDay();

	std::cout << "\n================ DIRECT WORK ================"
		<< std::endl;
	bob.Work();

	std::cout << "\n================ BONUS: AUTO RELEASE ================"
		<< std::endl;
	std::cout << "Alice releases her Hammer..." << std::endl;
	alice.TakeTool(&hammer);
	construction_site.Print();

	std::cout << "\n================ END ================" << std::endl;
	return (0);
}