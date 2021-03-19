modded class MVCUIMenuManager
{
	override void RegisterMenus()
	{
		super.RegisterMenus();
		
		GetMVCUIManager().RegisterMenu(MVC_PLAYERLIST_MENU, "MVCPlayerListMenu");
	}
}