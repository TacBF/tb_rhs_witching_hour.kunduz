#include "\ice\tb_main\sys\gameModes\aad_init.sqf"
0 setfog [.01, .18, 35];
if (isServer) then {3000 setFog [ 0,  0, 0];};
[] execVM "functions\initFastRope.sqf";



