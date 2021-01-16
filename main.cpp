#include <iostream>
#include <fstream>
#include <cwchar>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <list>
#include <mmsystem.h>
#include "person.h"
#include "player.h"
#include "item.h"
#include "map.h"
#include "mob.h"
#include "something.h"
#include "point.h"
#include "gfx.h"
#include "quest.h"
#pragma comment(lib, "winmm.lib")
using namespace std;

bool LoadGame(Player& player, vector<Map*>& allMaps)
{
	fstream file;
	int buf = 0;
	Item  item;
	Food  food;
	Weapon  weapon;
	Armor  armor;
	Mob mob;
	string sss;

	file.open("save", ios::in | ios::binary);
	if (!file.good())
		return false;

	/*zapis gracz*/
	file.read((char*)&player.dmg_output, sizeof(player.dmg_output));
	file.read((char*)&player.profession, sizeof(player.profession));
	file.read((char*)&player.xpToNextLvl, sizeof(player.xpToNextLvl));
	file.read((char*)&player.questID, sizeof(player.questID));
	file.read((char*)&player.mapID, sizeof(player.mapID));

	file.read((char*)&player.sex, sizeof(player.sex));
	file.read((char*)&player.xp, sizeof(player.xp));
	file.read((char*)&player.level, sizeof(player.level));
	file.read((char*)&player.money, sizeof(player.money));
	file.read((char*)&player.backpackMaxWeight, sizeof(player.backpackMaxWeight));
	file.read((char*)&player.backpackWeight, sizeof(player.backpackWeight));
	file.read((char*)&player.armor, sizeof(player.armor));
	file.read((char*)&player.life, sizeof(player.life));
	file.read((char*)&player.lifeMax, sizeof(player.lifeMax));
	file.read((char*)&player.accuracy, sizeof(player.accuracy));
	file.read((char*)&player.strength, sizeof(player.strength));
	file.read((char*)&player.inteligence, sizeof(player.inteligence));
	file.read((char*)&player.agility, sizeof(player.agility));
	file.read((char*)&player.dodging, sizeof(player.dodging));
	file.read((char*)&player.crit_strike, sizeof(player.crit_strike));
	file.read((char*)&player.gfxID, sizeof(player.gfxID));
	//imie
	getline(file, player.name, '\0');
	//pozycja
	file.read((char*)&player.positon, sizeof(player.positon));

	switch (player.profession)
	{
	case 0:
		player.profession_name = "Wojownik";
		break;
	case 1:
		player.profession_name = "Mag";
		break;
	case 2:
		player.profession_name = "Łowca";
		break;
	}

	bool bbuf = true;
	file.read((char*)&bbuf, sizeof(bbuf));

	if (bbuf == true)
	{
		getline(file, weapon.name, '\0');
		getline(file, weapon.desc, '\0');
		file.read((char*)&weapon.weight, sizeof(weapon.weight));
		file.read((char*)&weapon.price, sizeof(weapon.price));

		file.read((char*)&weapon.strength, sizeof(weapon.strength));
		file.read((char*)&weapon.critStrength, sizeof(weapon.critStrength));
		file.read((char*)&weapon.critPropability, sizeof(weapon.critPropability));
		file.read((char*)&weapon.professionBonus, sizeof(weapon.professionBonus));
		file.read((char*)&weapon.neededLvl, sizeof(weapon.neededLvl));

		player.equipedWeapon = new Weapon(weapon);
	}

	file.read((char*)&bbuf, sizeof(bbuf));
	if (bbuf == true)
	{
		getline(file, armor.name, '\0');
		getline(file, armor.desc, '\0');
		file.read((char*)&armor.weight, sizeof(armor.weight));
		file.read((char*)&armor.price, sizeof(armor.price));

		file.read((char*)&armor.armor, sizeof(armor.armor));
		file.read((char*)&armor.professionBonus, sizeof(armor.professionBonus));
		file.read((char*)&armor.neededLvl, sizeof(armor.neededLvl));

		player.equipedArmor = new Armor(armor);
	}

	//ekwipunek
	file.read((char*)&buf, sizeof(buf));
	int itemType = 0;
	for (int i = 0; i < buf; i++)
	{
		file.read((char*)&itemType, sizeof(itemType));

		switch (itemType)
		{
		case 0:
			getline(file, item.name, '\0');
			getline(file, item.desc, '\0');
			file.read((char*)&item.weight, sizeof(item.weight));
			file.read((char*)&item.price, sizeof(item.price));

			player.inventory.push_back(new Item(item));
			break;
		case 1:
			getline(file, food.name, '\0');
			getline(file, food.desc, '\0');
			file.read((char*)&food.weight, sizeof(item.weight));
			file.read((char*)&food.price, sizeof(item.price));
			file.read((char*)&food.healthModifier, sizeof(food.healthModifier));

			player.inventory.push_back(new Food(food));
			break;
		case 2:
			getline(file, weapon.name, '\0');
			getline(file, weapon.desc, '\0');
			file.read((char*)&weapon.weight, sizeof(weapon.weight));
			file.read((char*)&weapon.price, sizeof(weapon.price));

			file.read((char*)&weapon.strength, sizeof(weapon.strength));
			file.read((char*)&weapon.critStrength, sizeof(weapon.critStrength));
			file.read((char*)&weapon.critPropability, sizeof(weapon.critPropability));
			file.read((char*)&weapon.professionBonus, sizeof(weapon.professionBonus));
			file.read((char*)&weapon.neededLvl, sizeof(weapon.neededLvl));

			player.inventory.push_back(new Weapon(weapon));
			break;
		case 3:
			getline(file, armor.name, '\0');
			getline(file, armor.desc, '\0');
			file.read((char*)&armor.weight, sizeof(armor.weight));
			file.read((char*)&armor.price, sizeof(armor.price));

			file.read((char*)&armor.armor, sizeof(armor.armor));
			file.read((char*)&armor.professionBonus, sizeof(armor.professionBonus));
			file.read((char*)&armor.neededLvl, sizeof(armor.neededLvl));

			player.inventory.push_back(new Armor(armor));
			break;
		}
	}/**/

	//moby na mapach
	int mapID = 0;
	int numMobs = 0;
	bool bufd;

	for (int i = 0; i < allMaps.size(); i++)
	{
		//file.read((char*)&mapID, sizeof(mapID));
		file.read((char*)&numMobs, sizeof(numMobs));
		file.read((char*)&bufd, sizeof(bufd));

		allMaps[i]->is_boss_dead = bufd;

		for (int j = 0; j < numMobs; j++)
		{
								 
			file.read((char*)&mob.life, sizeof(mob.life));
			file.read((char*)&mob.armor, sizeof(mob.armor));
			file.read((char*)&mob.dmg, sizeof(mob.dmg));
			file.read((char*)&mob.mob_lvl, sizeof(mob.mob_lvl));
			file.read((char*)&mob.money_from_mob, sizeof(mob.money_from_mob));
			file.read((char*)&mob.exp_after_win, sizeof(mob.exp_after_win));
			file.read((char*)&mob.position, sizeof(mob.position));
			file.read((char*)&mob.gfxID, sizeof(mob.gfxID));
			getline(file, mob.name, '\0');

			allMaps[i]->mobs.push_back(new Mob(mob));
		}
	}

	file.close();
	return true;
}

bool SaveGame(Player& player, vector<Map*>& allMaps)
{
	fstream file;
	//bool bbuf = false;
	Item* item = NULL;
	Food* food = NULL;
	Weapon* weapon = NULL;
	Armor* armor = NULL;
	string sss = "";


	file.open("save", ios::out | ios::binary);
	if (!file.good())
		return false;

	/*zapis gracz*/
	file.write((const char*)&player.dmg_output, sizeof(player.dmg_output));
	file.write((const char*)&player.profession, sizeof(player.profession));
	file.write((const char*)&player.xpToNextLvl, sizeof(player.xpToNextLvl));
	file.write((const char*)&player.questID, sizeof(player.questID));
	file.write((const char*)&player.mapID, sizeof(player.mapID));

	file.write((const char*)&player.sex, sizeof(player.sex));
	file.write((const char*)&player.xp, sizeof(player.xp));
	file.write((const char*)&player.level, sizeof(player.level));
	file.write((const char*)&player.money, sizeof(player.money));
	file.write((const char*)&player.backpackMaxWeight, sizeof(player.backpackMaxWeight));
	file.write((const char*)&player.backpackWeight, sizeof(player.backpackWeight));
	file.write((const char*)&player.armor, sizeof(player.armor));
	file.write((const char*)&player.life, sizeof(player.life));
	file.write((const char*)&player.lifeMax, sizeof(player.lifeMax));
	file.write((const char*)&player.accuracy, sizeof(player.accuracy));
	file.write((const char*)&player.strength, sizeof(player.strength));
	file.write((const char*)&player.inteligence, sizeof(player.inteligence));
	file.write((const char*)&player.agility, sizeof(player.agility));
	file.write((const char*)&player.dodging, sizeof(player.dodging));
	file.write((const char*)&player.crit_strike, sizeof(player.crit_strike));
	file.write((const char*)&player.gfxID, sizeof(player.gfxID));
	//imie
	file.write(player.name.c_str(), player.name.size()+1);
	//pozycja
	file.write((const char*)&player.positon, sizeof(player.positon));
	
	if (player.equipedWeapon != NULL)
	{
		bool bbuf = true;
		file.write((const char*)&bbuf, sizeof(bbuf));

		file.write(player.equipedWeapon->name.c_str(), player.equipedWeapon->name.size()+1);
		file.write(player.equipedWeapon->desc.c_str(), player.equipedWeapon->desc.size() + 1);
		file.write((const char*)&player.equipedWeapon->weight, sizeof(player.equipedWeapon->weight));
		file.write((const char*)&player.equipedWeapon->price, sizeof(player.equipedWeapon->price));

		file.write((const char*)&player.equipedWeapon->strength, sizeof(player.equipedWeapon->strength));
		file.write((const char*)&player.equipedWeapon->critStrength, sizeof(player.equipedWeapon->critStrength));
		file.write((const char*)&player.equipedWeapon->critPropability, sizeof(player.equipedWeapon->critPropability));
		file.write((const char*)&player.equipedWeapon->professionBonus, sizeof(player.equipedWeapon->professionBonus));
		file.write((const char*)&player.equipedWeapon->neededLvl, sizeof(player.equipedWeapon->neededLvl));

	}
	else
	{
		bool bbuf = false;
		file.write((const char*)&bbuf, sizeof(bbuf));
	}
	if (player.equipedArmor != NULL)
	{
		bool bbuf = true;
		file.write((const char*)&bbuf, sizeof(bbuf));
		
		file.write(player.equipedArmor->name.c_str(), player.equipedArmor->name.size()+1);
		file.write(player.equipedArmor->desc.c_str(), player.equipedArmor->desc.size() + 1);
		file.write((const char*)&player.equipedArmor->weight, sizeof(player.equipedArmor->weight));
		file.write((const char*)&player.equipedArmor->price, sizeof(player.equipedArmor->price));

		file.write((const char*)&player.equipedArmor->armor, sizeof(player.equipedArmor->armor));
		file.write((const char*)&player.equipedArmor->professionBonus, sizeof(player.equipedArmor->professionBonus));
		file.write((const char*)&player.equipedArmor->neededLvl, sizeof(player.equipedArmor->neededLvl));
	}
	else
	{
		bool bbuf = false;
		file.write((const char*)&bbuf, sizeof(bbuf));
	}

	//ekwipunek
	int buf = player.inventory.size();
	file.write((const char*) & buf, sizeof(buf));
	int buf2 = 0;
	for (int i = 0; i < player.inventory.size(); i++)
	{
		buf2 = player.inventory[i]->ItemType();
		file.write((const char*)&buf2, sizeof(buf2));
		
		file.write(player.inventory[i]->name.c_str(), player.inventory[i]->name.size() + 1);
		file.write(player.inventory[i]->desc.c_str(), player.inventory[i]->desc.size() + 1);
		file.write((const char*)&player.inventory[i]->weight, sizeof(player.inventory[i]->weight));
		file.write((const char*)&player.inventory[i]->price, sizeof(player.inventory[i]->price));

		switch (player.inventory[i]->ItemType())
		{
		case 0://item
			break;
		case 1://food
			food = (Food*)player.inventory[i];
			file.write((const char*)&food->healthModifier, sizeof(food->healthModifier));
			break;
		case 2://weapon
			weapon = (Weapon*)player.inventory[i];

			file.write((const char*)&weapon->strength, sizeof(weapon->strength));
			file.write((const char*)&weapon->critStrength, sizeof(weapon->critStrength));
			file.write((const char*)&weapon->critPropability, sizeof(weapon->critPropability));
			file.write((const char*)&weapon->professionBonus, sizeof(weapon->professionBonus));
			file.write((const char*)&weapon->neededLvl, sizeof(weapon->neededLvl));
			break;
		case 3://armor
			armor = (Armor*)player.inventory[i];

			file.write((const char*)&armor->armor, sizeof(armor->armor));
			file.write((const char*)&armor->professionBonus, sizeof(armor->professionBonus));
			file.write((const char*)&armor->neededLvl, sizeof(armor->neededLvl));
			break;
		}
	}/**/
	bool bb;
	//moby na mapach
	for (int i = 0; i < allMaps.size(); i++)
	{
		buf = allMaps[i]->mobs.size();
		//file.write((const char*)&allMaps[i]->mapID, sizeof(allMaps[i]->mapID));
		file.write((const char*)&buf, sizeof(buf));
		file.write((const char*)&allMaps[i]->is_boss_dead, sizeof(allMaps[i]->is_boss_dead));
		for (int j = 0; j < allMaps[i]->mobs.size(); j++)
		{

			file.write((const char*)&allMaps[i]->mobs[j]->life, sizeof( allMaps[i]->mobs[j]->life));
			file.write((const char*)&allMaps[i]->mobs[j]->armor, sizeof( allMaps[i]->mobs[j]->armor));
			file.write((const char*)&allMaps[i]->mobs[j]->dmg, sizeof( allMaps[i]->mobs[j]->dmg));
			file.write((const char*)&allMaps[i]->mobs[j]->mob_lvl, sizeof( allMaps[i]->mobs[j]->mob_lvl));
			file.write((const char*)&allMaps[i]->mobs[j]->money_from_mob, sizeof( allMaps[i]->mobs[j]->money_from_mob));
			file.write((const char*)&allMaps[i]->mobs[j]->exp_after_win, sizeof(allMaps[i]->mobs[j]->exp_after_win));
			file.write((const char*)&allMaps[i]->mobs[j]->position, sizeof(allMaps[i]->mobs[j]->position));
			file.write((const char*)&allMaps[i]->mobs[j]->gfxID, sizeof( allMaps[i]->mobs[j]->gfxID));
			
			file.write(allMaps[i]->mobs[j]->name.c_str(), allMaps[i]->mobs[j]->name.size() + 1);
		}
	}


	file.close();
	return true;
}

int Fight(Player& player, Mob& mobek, int return_map)
{
	//system("cls");
	int tura = 1;
	int mana = 4;
	int pom=0;
	bool dodge = false;
	bool crit = false;
	bool acc=false;

	player.Dmg_formula();

	while (player.life > 0 || mobek.life > 0)
	{
		ClearInfoPlace();
		CDrawText("Tura: " + to_string(tura), { 107,1 }, 0x0003);
		//CDrawText("p: " + to_string(pom), { 107,2 }, 0x0003);
		CDrawText("HP twojego bohatera: " + to_string(player.life), { 107,3 }, 0x0003);
		CDrawText("HP przeciwnika: " + to_string(mobek.life), { 107,4 }, 0x0003);
		CDrawText("Mana: " + to_string(mana), { 107,5 }, 0x0003);
		CDrawText("Wybierz atak! ", { 107,7 }, 0x0003);

		for (int i = 0; i < 1; i++)
		{
			vector<string> s;
			s.push_back("Zwykły atak\n");
			s.push_back("Umiejętność specjalna \n");
			CDrawText("(potrzeba 4pkt many)", { 107,10 }, 0x0003);

			switch (DrawMenu(s, { 107,9 }))
			{
			case 0:
				crit = player.CritIs();
				acc = player.AccIs();
				if (crit)
				{		
					player.dmg_output *= 1.5;
				}
				if (acc)
				{
					mobek.life = mobek.life - (player.dmg_output - mobek.armor);
				}
				else
				{
					mobek.life = mobek.life;
					CDrawText("Przeciwnik uniknął twojego ciosu", { 107,13 }, 0x000b);
				};
				CDrawText("Zadajesz: " + to_string(player.dmg_output - mobek.armor) + " pkt obrażeń", { 107,12 }, 0x000b);
				if (crit)
				{
					CDrawText("Uderzenie krytyczne", { 107,13 }, 0x000b);
					player.dmg_output = player.dmg_output / 1.5;
				}
				continue;
			case 1:
				if (player.profession == 2 && player.life == player.lifeMax)
				{
					CDrawText("Masz pełne zdrowie. ", { 107,12 }, 0x000b);

					i--;
					break;
				}
				else if (player.profession == 2 && mana == 4)
				{
					mobek.life -= player.Spell(mobek.dmg);
					mana = 0;
				}
				else if (player.profession == 1 && mana == 4)
				{
					pom = 3;
					CDrawText("Aktywujesz wokół siebie aurę,", { 107,12 }, 0x000b);
					CDrawText("która zwiększy pancerz", { 107,13 }, 0x000b);

					mobek.dmg = (int)player.Spell(mobek.dmg);
					mana = 0;

				}
				else if (player.profession == 3 && mana == 4)
				{

					CDrawText("Wypuszczasz deszcz strzał...", { 107,12 }, 0x000b);
					CDrawText("Zadajesz: " + to_string(player.Spell(mobek.dmg)) + " pkt obrażeń", { 107,12 }, 0x000b);

					mana = 0;
				}
				else if (mana != 4)
				{
					CDrawText("Nie masz many!", { 107,12 }, 0x000b);
					i--;
				}
			}
		}

		if (pom > 0 && player.profession == 1) pom--;
		if (pom == 0) mobek.dmg *= 2;

		if (mana < 4) mana++;

		if (mobek.life <= 0)
		{
			ClearInfoPlace();
			CDrawText("Brawo wygrałeś tę walkę!", { 107,1 }, 0x000b);
			CDrawText("Zdobywasz: " + to_string(mobek.money_from_mob) + "G", { 107,2 }, 0x000b);

			mobek.dead = true;
			player.money += mobek.money_from_mob;
			player.xp += mobek.exp_after_win;
			return 1;	//wygra
		}

		GetKey();
		
		CDrawText("Twój przeciwnik uderza...", { 107,15 }, 0x000b);
		if (return_map == 1)
		{
			mobek.dmg = 30;// + rand() % (40 - 30 + 1);
		}
		else if (return_map == 2)
		{
			mobek.dmg = 40 + rand() % (50 - 40 + 1);
		}
		else if (return_map == 3)
		{
			mobek.dmg = 50 + rand() % (60 - 50 + 1);
		}
		dodge = player.DodgeIs();
		if (player.profession == 1 && pom > 0 && dodge == false)
		{
			CDrawText("Aura zablokowała : " + to_string((int)mobek.dmg * 0.5) + " pkt obrażeń.", { 107,17 }, 0x000b);
		}

		if (dodge)
		{
			player.life = player.life;
			CDrawText("Udało ci sie uniknąć ciosu przeciwnika!", { 107,16 }, 0x000b);
		}
		else
			player.life = player.life - (mobek.dmg - player.armor);
		CDrawText("Zadaje ci: : " + to_string(mobek.dmg - player.armor) + " pkt obrażeń.", { 107,16 }, 0x000b);

		if (player.life <= 0)
		{
			CDrawText("Poległeś na polu bitwy...", { 107,19 }, 0x000b);
			player.dead = true;
			break;

			return 0;	//przegra
		}

		tura++;
		GetKey();
	}
	return 1;
}

int SellItem(Player &player)
{
	vector<string> itNames;
	for (int i = 0; i < player.inventory.size(); i++)
	{
		itNames.push_back(player.inventory[i]->name + " " + [](string s)->string { s.erase(s.end() - 4, s.end()); return s; }(to_string(player.inventory[i]->weight)) + "Kg " + to_string(player.inventory[i]->price) + "G");
	}
	itNames.push_back("Powrót");

	ClearInfoPlace();
	return DrawMenu(itNames, {107,1});
}

int BuyItem( vector<Item*> &sellersItems)
{
	vector<string> itNames;
	for (int i = 0; i < sellersItems.size(); i++)
	{
		itNames.push_back(sellersItems[i]->name + " " + [](string s)->string { s.erase(s.end() - 4, s.end()); return s; }(to_string(sellersItems[i]->weight)) + "Kg " + to_string(sellersItems[i]->price) + "G");
	}
	itNames.push_back("Powrót");
	
	ClearInfoPlace();
	return  DrawMenu(itNames, {107,1});
}

void Shop(Player& player, vector<Food>& allFood, vector<Weapon>& allWeapons, vector<Armor>& allArmor)
{
	vector<Item *> sellersItems;
	vector<string> s;
	s.push_back("Kup");
	s.push_back("Sprzedaj");
	s.push_back("Odejdź");

	int it = 0;

	for (int i = 0; i < 5; i++)
	{
		switch (rand()%3 + 1)
		{
		case 1:	//jedzonko
			sellersItems.push_back(new Food(allFood[rand() % (allFood.size() - 1)]));
			break;
		case 2:	//bron
			sellersItems.push_back(new Weapon(allWeapons[rand() % (allWeapons.size() - 1)]));
			break;
		case 3:	//armor
			sellersItems.push_back(new Armor(allArmor[rand() % (allArmor.size() - 1)]));
			break;
		}
		//sellersItems.push_back(new Item("Tak", "To jest opis", 3 + i, 99 + i * 1));
	}

	ClearInfoPlace();

	switch (DrawMenu(s, {107, 1}))
	{
	case 0:
		it = BuyItem( sellersItems);
		if (it < sellersItems.size())
		{
			if (sellersItems[it]->price < player.money)
			{
				player.money -= sellersItems[it]->price;
				player.inventory.push_back(sellersItems[it]);
				CDrawText("Kupiłeś " + player.inventory[player.inventory.size() - 1]->name, { 107,30 }, 0x0003);
				PlaySound(TEXT("music/Coins8.wav"), NULL, SND_FILENAME | SND_ASYNC);
				GetKey();
			}
			else
			{
				it = sellersItems.size();
				CDrawText("Nie stać Cię!", { 107, 30 }, 0x000c);
			}
		}
		break;
	case 1:
		it = SellItem(player);
		if (it < player.inventory.size())
		{
			CDrawText("Sprzedałeś: " + player.inventory[it]->name + " za: " + to_string(player.inventory[it]->price), {107,30 }, 0x000c);
			PlaySound(TEXT("music/Coins8.wav"), NULL, SND_FILENAME | SND_ASYNC);
			GetKey();
			player.money += player.inventory[it]->price;
			player.inventory[it] = NULL;
			player.inventory.erase(player.inventory.begin() + it);
		}
		it = sellersItems.size();
		break;
	case 2:
		break;
	}

	//GetKey();

	//Czyszczenie ekwipunku sprzedawcy
	s.clear();
	for (int i = 0; i < sellersItems.size(); i++)
	{
		if(i != it)
			sellersItems[i] = NULL;
	}
	sellersItems.clear();
}

void LoadGameAssets(vector<Food>& allFood, vector<Weapon>& allWeapons, vector<Armor>& allArmor)
{
	allFood.push_back(Food("Bułka", "Można zjeść", 0.05f, 30, 2));
	allFood.push_back(Food("Chleb", "Można zjeść", 0.05f, 30, 2));
	allFood.push_back(Food("Ciasteczka", "Ze stron ;)", 0.01f, 200, 3));
	allFood.push_back(Food("Soczek Jagodowy", "Do picia", 0.3f, 500, 10));
	allFood.push_back(Food("XXX", "Jak nie piłeś lepiej nie pij", 0.5f, 2000, -1));
	
	allWeapons.push_back(Weapon("Srebrny miecz", "", 2.81f, 767, 5, 30, 0.5f, 1));
	allWeapons.push_back(Weapon("Stalowy miecz", "", 2.81f, 767, 30, 10, 0.3f, 1));
	allWeapons.push_back(Weapon("Siekiera", "", 1.76f, 500, 10, 10, 0.8f, 1));


	allArmor.push_back(Armor("Zbroja stalowa", "", 5.0f, 2000, 10, 1));
	allArmor.push_back(Armor("Skurzane ubranko", "", 1.0f, 500, 7, 2));
}

void LoadQuests(list<Quest*>& mainQuest)
{
	mainQuest.push_back(new MainQuest0());
	mainQuest.push_back(new MainQuest1());
	mainQuest.push_back(new MainQuest2());
	mainQuest.push_back(new MainQuest3());
	mainQuest.push_back(new MainQuest4());
	mainQuest.push_back(new MainQuest5());
	mainQuest.push_back(new MainQuest8());

}

void LoadMaps(vector<Map*>& allMaps)
{
	allMaps.push_back(new MapHome());
	allMaps.push_back(new Map1());
	allMaps.push_back(new Map2());
	allMaps.push_back(new Map3());
}
 



void Game(bool isNewGame)//, Map &map
{
	int mapID = 0;
 
	Player player;
	vector<Food> allFood;
	vector<Weapon> allWeapons;
	vector<Armor> allArmor;
	list<Quest*> mainQuest;
	vector<Map*> allMaps;

	//Mob mob;
	LoadGameAssets(allFood, allWeapons, allArmor);
	LoadQuests(mainQuest);
	LoadMaps(allMaps);

	//Tworzenie/Ładowanie gry
	if (isNewGame)
	{
		player.CreateCharacter();
		player.inventory.push_back(new Armor("Zbroja", "", 3.0f, 1000, 1, 1));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
		player.mapID = 0;
		SaveGame(player,  allMaps);
	}
	else
	{
		LoadGame(player, allMaps);
		mapID = player.mapID;
		for (int i = 0; i < player.questID; i++)
		{
			mainQuest.pop_front();
		}
	}
	
	allMaps[mapID]->LoadVMap(player.positon);
	allMaps[mapID]->ShowMap();
	//map.ShowMap();
	DrawBorder();

	player.ShowStats();
	//system("cls");
	while (1)	//głowna petla gry
	{
		allMaps[mapID]->ShowMap(player.positon);

		//Osługa klawiatury
		switch (GetKey())
		{
		case 'w':
			player.positon.y -= 1;
			if (player.positon.y < 1 || !allMaps[mapID]->CanMove(player.positon))
				player.positon.y += 1;
			break;
		case 's':
			player.positon.y += 1;
			if (player.positon.y > allMaps[mapID]->mapSize.y - 1 || !allMaps[mapID]->CanMove(player.positon))
				player.positon.y -= 1;
			break;
		case 'a':
			player.positon.x -= 1;
			if (player.positon.x < 1 || !allMaps[mapID]->CanMove(player.positon))
				player.positon.x += 1;
			break;
		case 'd':
			player.positon.x += 1;
			if (player.positon.x > allMaps[mapID]->mapSize.x - 1 || !allMaps[mapID]->CanMove(player.positon))
				player.positon.x -= 1;
			break;
		case 'i':
			player.ShowInventory();
			ClearEqPlace();
			break;
		case 'j':
			player.ShowQuests();
			ClearEqPlace();
			break;
		case 'l':
			player.mapID = mapID;
			SaveGame(player, allMaps);
			return;
			break;
		}

		//walka
		if (int buf = allMaps[mapID]->IsFight(player.positon))	
		{
			X(3, 0x000c ,"Na swojej drodze spotkałeś" , allMaps[mapID]->mobs[buf-1]->name.c_str() ,"musisz stanąć z nim do walki!");
			ClearMapPlace();
			ShowGfx_Mobs(allMaps[mapID]->mobs[buf - 1]->gfxID, {(WHEREINFO-50)/2, 5});
			if (Fight(player, *allMaps[mapID]->mobs[buf-1], mapID))
			{
				allMaps[mapID]->KillMob(buf - 1);
			}
			allMaps[mapID]->ShowMap();
		}

		//czy spotka npc
		if (allMaps[mapID]->map[player.positon.y][player.positon.x] == 'S')		
		{
			Shop(player, allFood, allWeapons, allArmor);
		}/**/
		/*if (int buf = allMaps[mapID]->IsWithNpc(player.positon))
		{
			allMaps[mapID]->npcs[buf - 1]->OnInteraction();

			
		}*/

		/*Zabawa z questami*/
		if (mainQuest.size() > 0)
		{
			mainQuest.front()->UpdateQuest(*allMaps[mapID]);
			if (mainQuest.front()->IsQuestDone(player, *allMaps[mapID]))
			{
				player.questID++;
				mainQuest.pop_front();
				if (mainQuest.size() > 0)
				{
					mainQuest.front()->CreateQuest(player, *allMaps[mapID]);
					allMaps[mapID]->ShowMap();
				}
			}
		}
	
		//lvl up
		if (player.xp >= player.xpToNextLvl)	
		{
			player.xp -= player.xpToNextLvl;
			player.xpToNextLvl = (int)player.xpToNextLvl * 1.5;
			player.level++;
			player.Bonus_stats_per_lvl();
			allMaps[mapID]->ShowMap();
		}

		//Następna/poprzednia mapa
		if (allMaps[mapID]->IsNextMap(player.positon))
		{
			mapID++;
			allMaps[mapID]->LoadVMap(player.positon);
			ClearMapPlace();
			allMaps[mapID]->ShowMap();
		}
		if (allMaps[mapID]->IsPrevMap(player.positon))
		{
			mapID--;
			allMaps[mapID]->LoadVMap(player.positon);
			ClearMapPlace();
			allMaps[mapID]->ShowMap();
		}

		//czy gracz żyje
		if(player.dead)
		{
			X(1, 0x0004, "Koniec gry");
			break;
		}
	}
	
	allArmor.clear();
	allWeapons.clear();
	allFood.clear();
	mainQuest.clear();	//<wycieki mozliwe xd chyba xd
}



int main()
{
	srand(time(NULL));
	GenerateWindow();

	//PlaySound(TEXT("music/theme.wav"), NULL,  SND_LOOP | SND_ASYNC);
	
	//_getch();
	//PlaySound(TEXT("music/spirit.wav"), NULL, SND_FILENAME);


	vector<string> s;
	s.push_back("Rozpocznij nowa grę");
	s.push_back("   Wczytaj zapis   ");
	s.push_back("    Sterowanie     ");
	s.push_back("       Wyjdź       ");

	while (1)//główna 
	{
		system("cls");
		ShowGfx_GameName();
		DrawOnlyBorder();
		DrawMenuCharacters();

		switch (DrawMenu(s, {(WIDTHCONSOLE - 20)/2, 15}))
		{
		case 0: //poczatek gry
			system("cls");
			Game(true);//, map
			break;
		case 1:	//wczytanie zapisu
			system("cls");
			Game(false);
			break;
		case 2:	//wyjscie
			return 0;
			break;
		case 3:	//wyjscie
			return 0;
			break;
		}
	}

	return 0;
}