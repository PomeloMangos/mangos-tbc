#include <list>

#include "Common.h"
#include "Globals/SharedDefines.h"
#include "Platform/Define.h"
#include "Entities/Player.h"

#ifndef MANGOS_WCL_ITEM_MGR_H
#define MANGOS_WCL_ITEM_MGR_H

class WclItemMgr
{
public:
    void SyncItemsForUser(Player* player);
private:
    std::list<uint32> LoadFromDB(uint32 charactor_id);
    void SaveToDB(uint32 charactor_id);
};

#define sWclItemMgr MaNGOS::Singleton<WclItemMgr>::Instance()

#endif