class MVCPlayerListMenuController: Controller
{
	ref ObservableCollection<ref MVCPlayerListEntry> PlayerList = new ObservableCollection<ref MVCPlayerListEntry>(this);
	int PlayerCount = 0;
};