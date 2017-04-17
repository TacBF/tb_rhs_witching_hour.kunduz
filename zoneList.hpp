#include "tb_defines.hpp"

zoneList[] =
{
//ID TEAM          SPAWNTYPE      LINK         SYNC   PROFILE   DEPEND     DEPQTY  ZONE_DESC
{ 0, 0           , 0         ,    {}         , {}    , 1      , {}        , 0      },

{ 1, TEAM_BLUE    , SPAWN_XRAY,     {3,4}          , {}    , 1      , {}        , 0    , "US Rangers Main Base" },
{ 2, TEAM_RED   , SPAWN_XRAY,       {}     , {}    , 1      , {}        , 0    , "Taliban Main base" },



{ 3, TEAM_RED    , SPAWN_NEVER,    {5}     , {4} , 1      , {}        , 0    , "%1" },
{ 4, TEAM_RED    , SPAWN_NEVER,    {5}     , {3} , 1      , {}        , 0    , "%1" },
{ 5, TEAM_RED    , SPAWN_NEVER,    {6}     , {} , 1      , {}        , 0    , "%1" },
{ 6, TEAM_RED    , SPAWN_NEVER,    {2}     , {} , 1      , {}        , 0    , "%1" },
{ 7, TEAM_RED    , SPAWN_INSTANT,    {}     , {} , 1      , {2,3,4,-1}        , 3    , "South Camp" }

};
