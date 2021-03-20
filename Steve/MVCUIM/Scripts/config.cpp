class CfgPatches
{
    class Steve_MVCUIM_Scripts
    {
        units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]=
        {
            "DZ_Data", "Steve_MVCUIM_GUI", "JM_CF_Scripts"
        };
    };
};

class CfgMods
{
	class Steve_MVCUIM
	{
		dir = "Steve/MVCUIM";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 1;
		name = "MVC UI Manager";
		credits = "Jacob_Mango, Arkensor, InclementDab";
		creditsJson = "Steve/MVCUIM/Scripts/Data/Credits.json";
		inputs = "Steve/MVCUIM/Scripts/Data/Inputs.xml";
		author = "Steve aka Saluteh";
		authorID = "0"; 
		version = "0.1";
		versionPath = "Steve/MVCUIM/Scripts/Data/Version.hpp";
		extra = 0;
		type = "mod";
		
		dependencies[] = { "Game", "World", "Mission" };
		
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"Steve/MVCUIM/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Steve/MVCUIM/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"Steve/MVCUIM/Scripts/5_Mission"};
			};
		};
	};
};