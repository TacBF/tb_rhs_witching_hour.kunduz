class ICE
{
   class assets
   {
      class FO
      {
         maxAllowed = 10;
      };
      class SRP
      {
         maxAllowed = 10;
      };
      class HO
      {
         maxAllowed = 10;
      };
      class TRP
      {
         maxAllowed = 10;
      };
   };
	class vehicles
    {
    class armaments
        {
        startFullyRearmed = 1;
        };
	};
  class zones
  {
    #include "zoneList.hpp"
  };  
  class firstAid
  {
    bleedoutTimeSteps[] = {200, 100, 0}; // Controls the bleedout time steps
    bleedoutTimeReset = 300; // Controls the time that you should go incapped within to go down a step. 2 * this time takes you a step back up.
  };
  
  class mission
  {
    gameMode = "A&D";
    missionScale = "medium";
    recommendedTotalPlayers = 30;
    attackingSide = "west"; // required for A&D
	
        class briefings
        {
			class west
			{
				original = "briefing_blue.hpp";
			};
			class east
			{
				original = "briefing_red.hpp";
			};
        };
		class factions // or sides
		{
			class faction
			{
				bluFor = "TB_faction_USA";
				opFor = "OPF_G_F";
			};
			class teamName
			{
				opFor = "Taliban";
			};
			class teamFlag
			{
				opFor = "\ice\ice_main\Images\flags\Taliban.paa";
			};
		};
    class scoring
    {
      class tickets
      {
        // In A&S, specify the tickets per hour, (not total tickets). It will later be scaled by duration.
        // In A&D, specify the tickets per zone. It is usually a 7:5 ratio, for attackers/defenders respectively.
        // In S&D, do not specify any tickets. It is automatically calculated, with the defenders ticket count representing the total caches.
        bluFor = 35;
        opFor = 15;
      };
    };
  };
  class respawn
  {
    class FO
    {
      minSpacingDist = 200;
      maxFriendlySiteDist = 500;
      minZoneDist = 50;
      //minEnemyFBDist = 500;
      //minEnemyBaseDist = 1000;
    };
    class SRP
    {
      maxFriendlySiteDist = 5500;
    };
    class HO
    {
      minSpacingDist = 1000;
      maxFriendlySiteDist = 500;
    };
		class infantry
		{
			baseDuration = 60;
			class unevenTeamsPenaltyTime
			{
				ratioDuration = 60; // "pivot value" where low player count differences result in small time penalties, 
				// but large differences result in exponential time penalties
				maxDuration = 240;
			};
		};
 class vehicles
		{
            class respawnDelay
			{
                multiplier = 1;
            };
        };
  };
  class gameModes
  {
    class objectives
    {
      class zones
      {
        class captureRates
        {
          // Eg: A higher value (eg: 2 to 3) is ideal for smaller missions.
          heldZoneMultiplier = 0.5; // Decimal value between 0 and N. (> 0, < 1 will reduce capture rate), (> 1 will increase capture rate). Eg: 0.25, 0.5, 0.75, 1.0, 1.25, 1.5

          // This value is a cumulative multiplier with 'captureRateMultiplier'. (So if captureRateMultiplier == 2 and neutralZoneCaptureRateMultiplier == 3, then overall rate is 6 times faster.)
          // Eg: A value of 2 is ideal for missions which have very few neutral zones at the start.
          // Eg: A high value (eg: 3 to 6) is ideal for missions which have many neutral zones at the start or for smaller missions.
          neutralZoneMultiplier = 8; // Decimal value between 0 and N. (> 0, < 1 will reduce capture rate), (> 1 will increase capture rate)

          negateNeutral = 1; // set to 1 to make both Multipliers totally independent, not a "cumulative multiplier".
        };
      };
    };
    class AAD
    {
			attackerTicketsPerZoneCapture = 10;
			attackerMaxTotalTickets = 100;
    };
  };
    class gear
    {
        #include "tb_kitDefines.sqh" // Unconfirmed. These files might need to be copied local to mission.
        #include "tb_magazineExclusions.hpp"
	    class NVGogglesForAll
        {
            west = 1;
            east = 0;
            resistance = 0;
            civilian = 1;
        };
    class roles
    {
      #define __unlimited -99
      kits[] =
      {
        // BLUFOR or ALL factions
        {
          // {id, caption, ratio, minimum, minTeamSize, minSquadSize}
          {__ICE_gear_Rifleman, "Rifleman", __unlimited, 0, 0, 0, 0},
          {__ICE_gear_Grenadier, "Grenadier", 6, 0, 0, 2, 3},
          {__ICE_gear_MG, "MG", 5, 0, 0, 2, 3},
          {__ICE_gear_Medic, "Medic", 4, 3, 0, 2, 3},
          {__ICE_gear_CombatEngineer, "Combat Engineer", 6, 1, 0, 2, 3},
          {__ICE_gear_LightAT, "Light AT", 0, 0, 0, 2, 3},
          {__ICE_gear_HeavyAT, "Heavy AT", 0, 0, 0, 2, 3},
          {__ICE_gear_AA, "Anti-Air", 0, 0, 0, 0, 0},
          {__ICE_gear_Marksman, "Marksman", 8, 0, 0, 2, 3},
          {__ICE_gear_Sniper, "Sniper", 12, 0, 0, 2, 3},
          {__ICE_gear_SL, "Squad Leader", __unlimited, 0, 0, 0, 0},
          {__ICE_gear_Crewman, "Crewman", 0, 0, 0, 0, 0},
          {__ICE_gear_Pilot, "Pilot", __unlimited, 0, 0, 0, 0},
          {__ICE_gear_Diver, "UAV Operator", 0, 0, 0, 0, 0}
        },
        // OPFOR (delete OPFOR array or leave OPFOR array empty, to re-use (copy) BLUFOR array for both sides)
        {
          // {id, caption, ratio, minimum, minTeamSize, minSquadSize}
          {__ICE_gear_Rifleman, "Rifleman", __unlimited, 0, 0, 0, 0},
          {__ICE_gear_Grenadier, "Grenadier", 10, 0, 0, 2, 3},
          {__ICE_gear_MG, "MG", 8, 0, 0, 2, 3},
          {__ICE_gear_Medic, "Medic", 4, 3, 0, 2, 3},
          {__ICE_gear_CombatEngineer, "Combat Engineer", 10, 0, 0, 2, 3},
          {__ICE_gear_LightAT, "Light AT", 10, 0, 0, 2, 3},
          {__ICE_gear_HeavyAT, "Heavy AT", 0, 1, 0, 2, 3},
          {__ICE_gear_AA, "Anti-Air", 0, 0, 0, 0, 0},
          {__ICE_gear_Marksman, "Marksman", 10, 0, 0, 2, 3},
          {__ICE_gear_Sniper, "Sniper", 14, 0, 0, 2, 3},
          {__ICE_gear_SL, "Squad Leader", __unlimited, 0, 0, 0, 0},
          {__ICE_gear_Crewman, "Crewman", 0, 0, 0, 0, 0},
          {__ICE_gear_Pilot, "Pilot", 0, 0, 0, 0, 0},
          {__ICE_gear_Diver, "Suicide Bomber", 0, 1, 0, 0, 0}
        };
      };
    };
    class armaments
    {
        
      class TB_faction_USA
      {
        defaultGear = "factions\BLU_F.sqh";
        #include "factions\_common_smallItems.sqh"
        #include "factions\BLU_F_gear.sqh"
        #include "factions\BLU_F_uniforms.sqh"
      };
      class OPF_G_F
      {
        defaultGear = "factions\OPF_G_F.sqh";
        #include "factions\_common_smallItems.sqh"
        #include "factions\OPF_G_F_gear.sqh"
        #include "factions\OPF_G_F_uniforms.sqh"
      };
    };
  };
};
