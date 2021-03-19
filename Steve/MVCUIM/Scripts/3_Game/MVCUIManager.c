class MVCUIManager
{
    ref MVCScriptViewMenu m_CurrentMenu;
	ref map<int, string> m_Menus;
	ref map<int, MVCScriptViewMenu> m_ActiveMenus;
	
	void MVCUIManager()
	{	
		m_CurrentMenu = NULL;
		m_Menus = new map<int, string>;
		m_ActiveMenus = new map<int, MVCScriptViewMenu>;
	}
	
	void SetMenu(MVCScriptViewMenu view)
	{
		if (m_CurrentMenu)
		{
			delete m_CurrentMenu;
			m_CurrentMenu = NULL;
		}
		
		m_CurrentMenu = view;
	}
	
	ref MVCScriptViewMenu GetMenu()
	{
		return m_CurrentMenu;
	}
	
	void CloseMenu()
	{
		ref MVCScriptViewMenu menu;
		if (m_ActiveMenus.Find(m_CurrentMenu.GetID(), menu))
		{
			Print("[MVC UI MANAGER]: Removing menu " + menu + " with id " + m_CurrentMenu.GetID() + " from UI manager.");
			m_ActiveMenus.Remove(m_CurrentMenu.GetID());
		}
			
		if (m_CurrentMenu)
		{
			if (m_CurrentMenu.IsVisible())
				m_CurrentMenu.Hide();
			
			Print("[MVC UI MANAGER]: Deleting menu instance " + m_CurrentMenu + " with id " + m_CurrentMenu.GetID() + " from UI manager.");
			delete m_CurrentMenu;
		}
	}
	
	void CloseAll()
	{
		foreach (ref MVCScriptViewMenu menu: m_ActiveMenus)
		{
			if (menu.IsVisible())
				menu.Hide();
			
			delete menu;
		}
	}
	
	void RegisterMenu(int id, string className)
	{
		string viewName;
		if (!m_Menus.Find(id, viewName))
		{
			if (viewName != className)
			{
				m_Menus.Insert(id, className);
				Print("[MVC UI MANAGER]: Registered menu " + className + " with id " + id + " to UI manager.");
			}
		}
	}
	
	void CreateSVMenu(int id)
	{
		string viewName;
		if (m_Menus.Find(id, viewName))
		{
			ref MVCScriptViewMenu viewMenu;
			
			if (!m_ActiveMenus.Find(id, viewMenu))
			{
				viewMenu = CreateMenuInstance(viewName);
			}
			else
			{
				delete viewMenu;
				viewMenu = CreateMenuInstance(viewName);
			}
			
			if (viewMenu)
			{
				viewMenu.SetID(id);
				SetMenu(viewMenu);
				m_ActiveMenus.Insert(id, viewMenu);
				viewMenu.Show();
				Print("[MVC UI MANAGER]: Created menu " + viewMenu + " with id " + id + ".");
			}
		}
	}
	
	ref map<int, string> GetMenus()
	{
		return m_Menus;
	}
	
	ref map<int, MVCScriptViewMenu> GetActiveMenus()
	{
		return m_ActiveMenus;
	}
	
	MVCScriptViewMenu CreateMenuInstance(string className)
	{
		return MVCScriptViewMenu.Cast(className.ToType().Spawn());
	}
};