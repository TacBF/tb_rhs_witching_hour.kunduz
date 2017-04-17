// ---------------------------------------------------------------------------
// File:
//    ts_check.sqf
//
// Description:
//    Performs a check on the TS server and channel passed as arguments to make
//    sure player is connected to them, and blocks the screen otherwise
//
// Parameters:
//    _this select 0 : name of the TS server the player must be connected to.
//    _this select 1 : prefix of the chanel in the TS server the player must be
//                     in. Using the prefix and not the full name to allow multiple 
//                     TFR channels named after the different game servers.
//
// Example:
//    ["TacBF - Tactical Battlefield PvP Modification for A3", "OfficialTFR"] call compileFinal preprocessFileLineNumbers "ts_check.sqf";
//
// License:
//    This project is licensed under Arma Public License Share Alike 
//    https://www.bistudio.com/community/licenses/arma-public-license-share-alike
//    Copyright 2016 Alonso.E
// ---------------------------------------------------------------------------

private ["_tsServerName", "_tsChannelPrefix"];

_tsServerName = _this select 0;
_tsChannelPrefix = _this select 1;

diag_log format ["TS server name: [%1]", call TFAR_fnc_getTeamSpeakServerName];

player enableSimulation false;

if ((call TFAR_fnc_getTeamSpeakServerName)  != _tsServerName) then
{
   cutText ["Please connect to TacBF TS at [ts3.tacbf.com]", "BLACK OUT", 3, true];
   waitUntil {
      sleep 0.1;
      (call TFAR_fnc_getTeamSpeakServerName) == _tsServerName;
   };
   cutText ["", "BLACK IN"];
};

diag_log format ["TS channel name: [%1]", call TFAR_fnc_getTeamSpeakChannelName];

if (((call TFAR_fnc_getTeamSpeakChannelName) select [0, count _tsChannelPrefix]) != _tsChannelPrefix) then
{
   cutText ["You are not in the TFR channel and people won't be able to hear you. Reload your TFR plugin", "BLACK OUT", 3, true];
   waitUntil {
      sleep 0.1;
      (call TFAR_fnc_getTeamSpeakChannelName) select [0, count _tsChannelPrefix] == _tsChannelPrefix;
   };
   cutText ["", "BLACK IN"];
};

player enableSimulation true;
