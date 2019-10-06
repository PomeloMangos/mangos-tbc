/**
 *
 * @File : AdvancedDifficultyMgr.h
 * @Authors : yukozh
 * @Date : 10/06/2019
 *
 **/

#ifndef MANGOS_ADVANCED_DIFFICULTY_MGR_H
#define MANGOS_ADVANCED_DIFFICULTY_MGR_H

#include "Common.h"
#include "Globals/SharedDefines.h"
#include "Platform/Define.h"
#include <string>

enum AdvancedDifficulty : uint8
{
    ADVANCED_DIFFICULTY_NORMAL      = 0,
    ADVANCED_DIFFICULTY_TEN_PLAYERS = 1
};

class AdvancedDifficultyMgr
{
public:
};

#define sAdvancedDifficultyMgr MaNGOS::Singleton<AdvancedDifficultyMgr>::Instance()

#endif