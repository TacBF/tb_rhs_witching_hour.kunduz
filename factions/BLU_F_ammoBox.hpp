// USA - Special Forces (M81)
// Author: Cole

class TB_BLUBasicAmmunitionBox
{
	transportClear = 1;
	proxyObject = "TB_BLUBasicAmmunitionBox";
	class transportCargo
	{
		transportMagazines[] = {
			{"rhs_mag_30Rnd_556x45_M855A1_Stanag", 20},
			{"rhsusf_20Rnd_762x51_m118_special_Mag", 5},
			{"rhsusf_100Rnd_762x51", 5},
			{"rhs_200rnd_556x45_M_SAW", 5},
			{"rhsusf_5Rnd_300winmag_xm2010", 10},
			{"SmokeShell", 10},
			{"rhs_mag_m67", 10},
			{"rhs_mag_M441_HE", 10},
			{"CUP_MAAWS_HEAT_M", 2},
			{"CUP_M136_M", 2},
			{"LaserBatteries", 2},
			{"DemoCharge_Remote_Mag", 4},
			{"20Rnd_556x45_UW_mag", 20}
		};
		transportWeapons[] = {{"rhs_weap_rsp30_green", 10}, {"CUP_launch_M136",1}, {"rhs_weap_m4a1_blockII",2}};
		//transportBackpacks[] = {};
		//transportItems[] = {};
	};
};
class TB_Box_West_Mines_F
{
	transportClear = 1;
	proxyObject = "TB_Box_West_Mines_F";
	class transportCargo
	{
		transportMagazines[] = {
			{"rhs_mine_M19_mag", 0},
			{"SLAMDirectionalMine_Wire_Mag", 0},
			{"APERSMine_Range_Mag", 0},
			{"APERSBoundingMine_Range_Mag", 0},
			{"APERSTripMine_Wire_Mag", 0},
			{"ClaymoreDirectionalMine_Remote_Mag", 2}
		};
		//transportWeapons[] = {};
		transportBackpacks[] = {{"rhsusf_falconii", 2}};
		transportItems[] = {{"MineDetector", 2}, {"ToolKit", 1}};
	};
};