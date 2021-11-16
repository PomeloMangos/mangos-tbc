#include "WclItemMgr.h"
#include "Tools/Language.h"

#define STORE_ITEM_ENTRY 90000 // fake item

std::list<uint32> WclItemMgr::LoadFromDB(uint32 charactor_id) 
{
	std::list<uint32> ret;
	QueryResult* result = CharacterDatabase.PQuery(
		"select `item_id` from `pomelo_wcl_item_sync` "
		"where `charactor_id` = %u and `delivered` = 0", 
		charactor_id);

	if (result) 
	{
		do
		{
			Field* field = result->Fetch();
			ret.push_back(field[0].GetUInt32());
		} while (result->NextRow());
	}

	delete result;
	return ret;
}

void WclItemMgr::SaveToDB(uint32 charactor_id)
{
	CharacterDatabase.DirectPExecute(
		"update `pomelo_wcl_item_sync` "
		"set `delivered` = 1 "
		"where `charactor_id` = %u;",
		charactor_id);
}

void WclItemMgr::SyncItemsForUser(Player* player)
{
	// Get items
	std::list<uint32> items = LoadFromDB(player->GetGUIDLow());

	// Check empty slots
	ItemPosCountVec dest;
	if (player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, STORE_ITEM_ENTRY, items.size()) != EQUIP_ERR_OK)
	{
		player->GetSession()->SendNotification(LANG_WCL_LACK_OF_SLOT);
		return;
	}

	for (auto i : items)
	{
		ChatHandler(player).HandleAddItemCommandInternal((char*)std::to_string(i).c_str(), true);
	}

	SaveToDB(player->GetGUIDLow());
}