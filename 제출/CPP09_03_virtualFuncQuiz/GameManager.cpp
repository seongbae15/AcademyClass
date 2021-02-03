#include "GameManager.h"

void SetConsoleWindow(int iWidth, int iHeight)
{
	char buf[256];
	int width = (iWidth * 2) + 1;
	int height = iHeight + 1;
	sprintf(buf, "mode con: lines=%d cols=%d", height, width);
	system(buf);
}

void GameManager::DispLoby()
{
	BLUE
	m_gmMapDraw.BoxDraw(0,0,WIDTH,HEIGHT);
	ORIGINAL
	m_gmMapDraw.DrawMidText("�١� Creed RPG �ڡ�",WIDTH,HEIGHT*0.3f);
	m_gmMapDraw.DrawMidText("New Game ", WIDTH, HEIGHT * 0.4f);
	m_gmMapDraw.DrawMidText("Load Game", WIDTH, HEIGHT * 0.5f);
	m_gmMapDraw.DrawMidText("Game Exit", WIDTH, HEIGHT * 0.6f);
}

void GameManager::NewGameSet()
{
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	CharacterInfo stTmpInfo;
	ifstream fPlayerLoad;
	fPlayerLoad.open("DefaultPlayer.txt");
	//Set Player
	m_gmCharacter[PLAYER] = new Player;
	YELLOW
	m_gmMapDraw.DrawMidText("Player �̸� �Է� : ", WIDTH, HEIGHT * 0.5f);
	ORIGINAL
	cin >> stTmpInfo.m_strName;
	fPlayerLoad >> stTmpInfo.m_iAttack;
	fPlayerLoad >> stTmpInfo.m_iVital;
	fPlayerLoad >> stTmpInfo.m_iExp;
	fPlayerLoad >> stTmpInfo.m_iGetExp;
	fPlayerLoad >> stTmpInfo.m_iLevel;
	fPlayerLoad >> stTmpInfo.m_iGold;
	m_gmCharacter[PLAYER]->LoadCharacterInfo(stTmpInfo, NEW);
	fPlayerLoad.close();

	//Set Monster
	ifstream fMonsterLoad;
	fMonsterLoad.open("DefaultMonster.txt");
	fMonsterLoad >> m_iMonsterCount;
	for (int i = 1;i<=m_iMonsterCount;i++)
	{
		m_gmCharacter[i] = new Monster;
		fMonsterLoad >> stTmpInfo.m_strName;
		fMonsterLoad >> stTmpInfo.m_iAttack;
		fMonsterLoad >> stTmpInfo.m_iVital;
		fMonsterLoad >> stTmpInfo.m_iExp;
		fMonsterLoad >> stTmpInfo.m_iGetExp;
		fMonsterLoad >> stTmpInfo.m_iLevel;
		fMonsterLoad >> stTmpInfo.m_iGold;
		m_gmCharacter[i]->LoadCharacterInfo(stTmpInfo, NEW);
	}
	fMonsterLoad.close();
}

void GameManager::DispPlayMenu()
{
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	m_gmMapDraw.DrawMidText("�١� Menu �ڡ�", WIDTH, HEIGHT * 0.3);
	m_gmMapDraw.DrawMidText("Dungeon", WIDTH, HEIGHT * 0.3f+2);
	m_gmMapDraw.DrawMidText("Player Info", WIDTH, HEIGHT * 0.3f +4);
	m_gmMapDraw.DrawMidText("Monster Info", WIDTH, HEIGHT * 0.3f + 6);
	m_gmMapDraw.DrawMidText("Weapon Shop", WIDTH, HEIGHT * 0.3f + 8);
	m_gmMapDraw.DrawMidText("Save", WIDTH, HEIGHT * 0.3f + 10);
	m_gmMapDraw.DrawMidText("Exit", WIDTH, HEIGHT * 0.3f + 12);
}

void GameManager::DispInfo(int selection)
{
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	if (selection == (int)PLAY_MENU_PLAYER_INFO)
		m_gmCharacter[PLAYER]->ShowInfo();
	else
	{
		int AddCol = 0;
		for (int j = 1; j < MAX_CHARACTER; j++)
		{
			m_gmCharacter[j]->ShowInfo(AddCol);
			AddCol += 4;
		}
	}
	getch();
}

void GameManager::DispEntrance()
{
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	m_gmMapDraw.DrawMidText("====== ���� �Ա� ======", WIDTH, HEIGHT * 0.2f);
	int i;
	for (i = 1; i <= MAX_MONSTER; i++)
	{
		string strTemp;
		strTemp = to_string(i) + " �� ���� : [" + m_gmCharacter[i]->GetName() + "]";
		m_gmMapDraw.TextDraw(strTemp, WIDTH-10, HEIGHT * 0.2f + 3 + 2*i);
	}
	m_gmMapDraw.DrawMidText("���ư���", WIDTH, HEIGHT * 0.2f + 3 + 2*i);
}

int GameManager::WinLoseDraw(int player, int monster)
{
	if (player - monster == 1 || player -monster == -2)
	{
		//Win
		m_gmMapDraw.DrawMidText(" Win", WIDTH, HEIGHT*0.4f+1);
		m_gmMapDraw.DrawMidText("Lose", WIDTH, HEIGHT*0.4f+5);
		return 1;
	}
	else if (player - monster == 0)
	{
		//Draw
		m_gmMapDraw.DrawMidText("Draw", WIDTH, HEIGHT * 0.4f + 1);
		m_gmMapDraw.DrawMidText("Draw", WIDTH, HEIGHT * 0.4f + 5);
		return 2;
	}
	else
	{
		//Lose
		m_gmMapDraw.DrawMidText("Lose", WIDTH, HEIGHT * 0.4f + 1);
		m_gmMapDraw.DrawMidText(" Win", WIDTH, HEIGHT * 0.4f + 5);
		return 3;
	}
}

void GameManager::DispResult(int result, int WinNumber, int LoseNumber)
{
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	RED
	string strTempName = m_gmCharacter[WinNumber]->GetName();
	m_gmMapDraw.DrawMidText(strTempName + " �¸�!!", WIDTH, HEIGHT * 0.3f);
	m_gmMapDraw.DrawMidText(strTempName + "�� ����ġ " + to_string(m_gmCharacter[LoseNumber]->GetGetExp()) + "�� ������ϴ�.", WIDTH, HEIGHT * 0.4f);
	if(result == LOSE)
	{
		getch();
		m_gmMapDraw.DrawMidText("Game Over", WIDTH, HEIGHT * 0.5f);
	}
	ORIGINAL
}

void GameManager:: CheckGameEnd(int MonsterNumber)
{
	if (m_gmCharacter[MonsterNumber]->GetCurVital() == 0)
	{
		getch();
		//�¸� ȭ�� ǥ��
		DispResult(WIN, PLAYER, MonsterNumber);
		m_eSTATE = STATE_WIN;
	}
	else if (m_gmCharacter[PLAYER]->GetCurVital() == 0)
	{
		getch();
		//GameOver ȭ�� ǥ��
		DispResult(LOSE, MonsterNumber, PLAYER);
		m_eSTATE = STATE_OVER;
	}
	else
	{
		m_eSTATE = STATE_ING;
		return;
	}
}

void GameManager::DispLevelUp()
{
	PURPLE
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	m_gmMapDraw.DrawMidText(m_gmCharacter[PLAYER]->GetName() + "������", WIDTH, HEIGHT*0.4f);
	m_gmMapDraw.DrawMidText("���ݷ� " + to_string(m_iAddAttack) + " ����!!", WIDTH, HEIGHT*0.5f);
	m_gmMapDraw.DrawMidText("����� " + to_string(m_iAddVital) + " ����!!", WIDTH, HEIGHT*0.6f);
	ORIGINAL
}

void GameManager::StartBattle(int MonsterSelection)
{
	m_eSTATE = STATE_ING;
	string strTemp;
	string strVS = " vs ";
	for (int i = 0; i < 2*(WIDTH-2) - strVS.size(); i++)
	{
		strTemp += "-";
		if (i == (2 * (WIDTH - 2) - strVS.size())/2)
			strTemp += strVS;
	}
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	RED
	m_gmMapDraw.DrawMidText(strTemp, WIDTH, HEIGHT * 0.5f);
	m_gmMapDraw.DrawMidText("���� : 1   ���� : 2   �� : 3", WIDTH, HEIGHT * 0.3f);
	m_gmCharacter[PLAYER]->ShowInfo(0);
	m_gmCharacter[MonsterSelection]->ShowInfo(20);
	while (m_eSTATE == STATE_ING)
	{
		int iPlayerRPS;
		iPlayerRPS = getch();
		if (iPlayerRPS >= '1' && iPlayerRPS <= '3')
		{
			//Display Player's RPS
			m_gmCharacter[PLAYER]->ThrowRPS(iPlayerRPS);
			//Display Monster's RPS(Random)
			int iMonsterRPS = rand() % 3 + '1';
			m_gmCharacter[MonsterSelection]->ThrowRPS(iMonsterRPS,MONSTER);
			//Win, Draw, Lose
			int iWDL = WinLoseDraw(iPlayerRPS, iMonsterRPS);
			switch ((WINDRAWLOSE)iWDL)
			{
			case WLD_WIN:
				m_gmCharacter[MonsterSelection]->Damage(m_gmCharacter[PLAYER]->GetAttack());
				m_gmCharacter[MonsterSelection]->ShowInfo(20);
				break;
			case WLD_DRAW:
				break;
			case WLD_LOSE:	
				m_gmCharacter[PLAYER]->Damage(m_gmCharacter[MonsterSelection]->GetAttack());
				m_gmCharacter[PLAYER]->ShowInfo(0);
				break;
			}
			//Check Win or Game Over
			CheckGameEnd(MonsterSelection);
		}
	}
	getch();
	if (m_eSTATE == STATE_OVER)
		return;
	else if (m_eSTATE == STATE_WIN)
	{
		//���� ü�� �ʱ�ȭ
		m_gmCharacter[MonsterSelection]->Respawn();
		//��� + ����ġ ȹ��
		m_gmCharacter[PLAYER]->GetReward(m_gmCharacter[MonsterSelection]->GetGetExp(), m_gmCharacter[MonsterSelection]->GetGold());
		//LEVEL��
		if (m_gmCharacter[PLAYER]->GetCurExp() >= m_gmCharacter[PLAYER]->GetExp())
		{
			m_iAddAttack = rand() % 5 + 1;
			m_iAddVital = rand() % 10 + 1;
			m_gmCharacter[PLAYER]->LevelUp(m_iAddAttack, m_iAddVital, ADD_EXP);
			DispLevelUp();
			getch();
		}
	}
}
void GameManager::DispDetailinfo(string str)
{
	int iDispCount;
	int iSelector;
	int iPage=0;
	vector<Weapon> tmpWeaponList;
	for (int i = 0;i < m_vWeaponList.size();i++)
	{
		if (str == m_vWeaponList[i].GetWeaponType())
			tmpWeaponList.push_back(m_vWeaponList[i]);
	}
	while (1)
	{
		int j;
		if (tmpWeaponList.size() >= 5)
		{
			if(iPage == 0)
				iDispCount = 5;
			else
				iDispCount = tmpWeaponList.size() - 5 * iPage;
		}
		else
			iDispCount = tmpWeaponList.size();
		//Disp
		m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
		m_gmMapDraw.DrawMidText(m_gmCharacter[PLAYER]->GetName() + " Gold : " + to_string(m_gmCharacter[PLAYER]->GetGold()), WIDTH, 2);
		m_gmMapDraw.DrawMidText(str + " Shop", WIDTH, 4);
		for (j=0; j < iDispCount; j++)
			tmpWeaponList[j+iPage*5].ShowWeapon(WIDTH,HEIGHT*0.2f + 3*j);
		m_gmMapDraw.DrawMidText("���� ������", WIDTH, HEIGHT * 0.2f + 3 * j++);
		m_gmMapDraw.DrawMidText("���� ������", WIDTH, HEIGHT * 0.2f + 3 * j++);
		m_gmMapDraw.DrawMidText("������", WIDTH, HEIGHT * 0.2f + 3 * j++);
		m_gmMapDraw.DrawMidText(to_string(iPage + 1) + "Page", WIDTH, HEIGHT-2);
		iSelector = m_gmMapDraw.MenuSelectCursor(iDispCount + 3,3,WIDTH -26, HEIGHT * 0.2f);
		if (iSelector <= iDispCount)
		{
			//Buy Item
			m_gmCharacter[PLAYER]->BuyWeapon(tmpWeaponList[iSelector - 1 + iPage * 5].getWeaponInfo());
		}
		else if (iSelector == iDispCount + 1)
		{
			//Previous Page
			if (iPage != 0)
				iPage--;
		}
		else if (iSelector == iDispCount + 2)
		{
			//Next Page
			if (iPage != (tmpWeaponList.size() - 1) / 5)
				iPage++;
		}
		else
			break;
	}

}
void GameManager::DispWeaponList(int weaponSelection)
{
	string strType;
	switch ((WEAPON_TYPE)weaponSelection)
	{
	case WEAPON_TYPE_DAGGER:
		strType = "Dagger";
		break;
	case WEAPON_TYPE_GUN:
		strType = "Gun";
		break;
	case WEAPON_TYPE_SWORD:
		strType = "Sword";
		break;
	case WEAPON_TYPE_WAND:
		strType = "Wand";
		break;
	case WEAPON_TYPE_BOW:
		strType = "Bow";
		break;
	case WEAPON_TYPE_HAMMER:
		strType = "Hammer";
		break;
	}
	DispDetailinfo(strType);
}

void GameManager::DispShop()
{
	while (1)
	{
		int iShopSelection;
		int iEnterCusorX = (WIDTH - 8) / 2;
		int iEnterCusorY = HEIGHT * 0.3f + 2;
		m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
		m_gmMapDraw.DrawMidText("�� �� S H O P �� ��", WIDTH, HEIGHT * 0.3f);
		m_gmMapDraw.DrawMidText("Dagger  ", WIDTH, HEIGHT * 0.3f + 2);
		m_gmMapDraw.DrawMidText("Gun     ", WIDTH, HEIGHT * 0.3f + 4);
		m_gmMapDraw.DrawMidText("Sword   ", WIDTH, HEIGHT * 0.3f + 6);
		m_gmMapDraw.DrawMidText("Wand    ", WIDTH, HEIGHT * 0.3f + 8);
		m_gmMapDraw.DrawMidText("Bow     ", WIDTH, HEIGHT * 0.3f + 10);
		m_gmMapDraw.DrawMidText("Hammer  ", WIDTH, HEIGHT * 0.3f + 12);
		m_gmMapDraw.DrawMidText("���ư���", WIDTH, HEIGHT * 0.3f + 14);
		iShopSelection = m_gmMapDraw.MenuSelectCursor(NUMBER_WEAPON_TYPE + 1, 2, iEnterCusorX, iEnterCusorY);
		switch ((WEAPON_TYPE)iShopSelection)
		{
		case WEAPON_TYPE_DAGGER:
		case WEAPON_TYPE_GUN:
		case WEAPON_TYPE_SWORD:
		case WEAPON_TYPE_WAND:
		case WEAPON_TYPE_BOW:
		case WEAPON_TYPE_HAMMER:
			DispWeaponList(iShopSelection);
			break;
		case WEAPON_TYPE_END:
			return;
		}
	}
}

void GameManager::EnterDungeon()
{
	int iMonsterSelect;
	int iEnterCusorX = (WIDTH - 14) / 2;
	int iEnterCusorY = HEIGHT * 0.2f + 5;
	DispEntrance();
	iMonsterSelect = m_gmMapDraw.MenuSelectCursor(MAX_MONSTER+1, 2, iEnterCusorX, iEnterCusorY);
	switch (iMonsterSelect)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		StartBattle(iMonsterSelect);
	case 7:
		return;
	}
}

void GameManager::SaveSlotInfo(int selector)
{
	ofstream fSaveFile;
	string strFileName = "SavePlayer" + to_string(selector) + ".txt";
	bool bTmp;
	fSaveFile.open(strFileName);
	if(fSaveFile.is_open())
	{
		fSaveFile << m_gmCharacter[PLAYER]->GetName() << " ";
		fSaveFile << m_gmCharacter[PLAYER]->GetAttack() << " ";
		fSaveFile << m_gmCharacter[PLAYER]->GetVital() << " ";
		fSaveFile << m_gmCharacter[PLAYER]->GetExp() << " ";
		fSaveFile << m_gmCharacter[PLAYER]->GetGetExp() << " ";
		fSaveFile << m_gmCharacter[PLAYER]->GetLevel() << " ";
		fSaveFile << m_gmCharacter[PLAYER]->GetGold() << " ";
		fSaveFile << m_gmCharacter[PLAYER]->GetCurExp() << " ";
		fSaveFile << m_gmCharacter[PLAYER]->GetCurVital() << endl;
		bTmp = m_gmCharacter[PLAYER]->GetWeaponState();
		fSaveFile << bTmp << " ";
		if (bTmp == true)
		{
			WEAPON stTmp = m_gmCharacter[PLAYER]->GetWeapon();
			fSaveFile << stTmp.m_strWType << " ";
			fSaveFile << stTmp.m_strWName << " ";
			fSaveFile << stTmp.m_iWAttack << " ";
			fSaveFile << stTmp.m_iWCost;
		}
	}
	fSaveFile.close();
}

int GameManager::DispSaveSlot()
{
	int iCusorX = (WIDTH - 16) / 2;
	int iCusorY = HEIGHT * 0.1f + 2;
	int iSelector;
	string strFileCheck;
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	GREEN
	int i;
	for (i = 1; i <= NUMBER_SAVE_SLOT; i++)
	{
		ifstream tmpLoadFile;
		string strTmp = "SavePlayer" + to_string(i) + ".txt";
		tmpLoadFile.open(strTmp);
		if (tmpLoadFile.is_open())
		{
			strFileCheck = "O";
			tmpLoadFile.close();
		}
		else
			strFileCheck = "X";
		m_gmMapDraw.TextDraw(to_string(i) + "�� ���� : <���� ���� : " + strFileCheck + ">", WIDTH - 12,HEIGHT*0.1f+2*i);
	}
	m_gmMapDraw.TextDraw(to_string(i) + "��. ���ư���", WIDTH - 12,HEIGHT*0.1f+2*i);
	iSelector = m_gmMapDraw.MenuSelectCursor(NUMBER_SAVE_SLOT + 1, 2, iCusorX, iCusorY);
	return iSelector;
}

void GameManager::StartGame()
{
	int iSelect;
	int iSlotSelector;
	int iMainMenuCount = 6;
	int iMainMenuAddCol = 2;
	int iMenuCusorX = (WIDTH - 10) / 2;
	int iMenuCusorY = HEIGHT * 0.3f + 2;
	while (1)
	{
		//Display Play Menu
		DispPlayMenu();
		iSelect = m_gmMapDraw.MenuSelectCursor(iMainMenuCount, iMainMenuAddCol, iMenuCusorX, iMenuCusorY);
		switch ((PLAY_MENU)iSelect)
		{
		case PLAY_MENU_DUNGEON:
			EnterDungeon();
			if (m_eSTATE == STATE_OVER)
				return;
			else
				break;
		case PLAY_MENU_PLAYER_INFO:
			DispInfo(iSelect);
			break;
		case PLAY_MENU_MONSTER_INFO:
			DispInfo(iSelect);
			break;
		case PLAY_MENU_WEAPONG_SHOP:
			DispShop();
			break;
		case PLAY_MENU_SAVE:
			iSlotSelector = DispSaveSlot();
			if (iSlotSelector <= NUMBER_SAVE_SLOT)
			{
				m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
				SaveSlotInfo(iSlotSelector);
				m_gmMapDraw.DrawMidText("Save �Ϸ�", WIDTH, HEIGHT * 0.5f);
				getch();
			}
			else
				return;
			break;
		case PLAY_MENU_EXIT:
			for (int i = 0; i < MAX_CHARACTER; i++)
			{
				if (m_gmCharacter[i] != NULL)
					delete m_gmCharacter[i];
			}
			return;
		}
	}
}

void GameManager::LoadWeapon()
{
	ifstream fWeaponLoad;
	WEAPON stTempWeaponList;
	fWeaponLoad.open("WeaponList.txt");
	while (!fWeaponLoad.eof())
	{
		Weapon tmpWeapon;
		fWeaponLoad >> stTempWeaponList.m_strWType;
		fWeaponLoad >> stTempWeaponList.m_strWName;
		fWeaponLoad >> stTempWeaponList.m_iWAttack;
		fWeaponLoad >> stTempWeaponList.m_iWCost;
		tmpWeapon.LoadWeapon(stTempWeaponList);
		m_vWeaponList.push_back(tmpWeapon);
	}
	fWeaponLoad.close();
}

void GameManager::LoadSlotInfo(int selector)
{
	ifstream fLoadFile;
	bool bTmp;
	string strFileName = "SavePlayer" + to_string(selector) + ".txt";
	fLoadFile.open(strFileName);
	if (fLoadFile.is_open())
	{
		m_gmCharacter[PLAYER] = new Player;
		CharacterInfo stTmpInfo;
		fLoadFile >> stTmpInfo.m_strName;
		fLoadFile >> stTmpInfo.m_iAttack;
		fLoadFile >> stTmpInfo.m_iVital;
		fLoadFile >> stTmpInfo.m_iExp;
		fLoadFile >> stTmpInfo.m_iGetExp;
		fLoadFile >> stTmpInfo.m_iLevel;
		fLoadFile >> stTmpInfo.m_iGold;
		fLoadFile >> stTmpInfo.m_iCurExp;
		fLoadFile >> stTmpInfo.m_iCurVital;

		//Player Setting
		m_gmCharacter[PLAYER]->LoadCharacterInfo(stTmpInfo,LOAD);
		
		fLoadFile >> bTmp;
		if (bTmp)
		{
			WEAPON stTmpWinfo;
			fLoadFile >> stTmpWinfo.m_strWType;
			fLoadFile >> stTmpWinfo.m_strWName;
			fLoadFile >> stTmpWinfo.m_iWAttack;
			fLoadFile >> stTmpWinfo.m_iWCost;
			m_gmCharacter[PLAYER]->InstallWeapon(stTmpWinfo);
		}
		else
			m_gmCharacter[PLAYER]->InstallWeapon();
		m_gmMapDraw.DrawMidText("Load �Ϸ�", WIDTH, HEIGHT * 0.5f);
		fLoadFile.close();

		//Monster Set
		ifstream fMonsterLoad;
		fMonsterLoad.open("DefaultMonster.txt");
		fMonsterLoad >> m_iMonsterCount;
		for (int i = 1; i < MAX_CHARACTER; i++)
		{
			m_gmCharacter[i] = new Monster;
			for (int j = 0; j < NUMBER_INFO; j++)
			{
				string strTemp;
				fMonsterLoad >> strTemp;
				m_gmCharacter[i]->SetInfo(strTemp, j);
			}
		}
		fMonsterLoad.close();
	}
	else
		m_gmMapDraw.DrawMidText("�ش� ������ �����ϴ�.", WIDTH, HEIGHT * 0.5f);
	getch();

}

void GameManager::DispLoad()
{
	int iSlotSelector;
	iSlotSelector = DispSaveSlot();
	if (iSlotSelector <= NUMBER_SAVE_SLOT)
	{
		m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
		LoadSlotInfo(iSlotSelector);
		m_gmMapDraw.DrawMidText("Load �Ϸ�", WIDTH, HEIGHT * 0.5f);
		getch();
	}
}

void GameManager::RunGame()
{
	int iCusorCount = 3;
	int iCursorX = (WIDTH-8)/2;
	int iCursorY = HEIGHT*0.4f;
	int iAddCol = 3;
	//Set Console Window
	SetConsoleWindow(WIDTH, HEIGHT);
	//To make random RPS of Monster
	srand((unsigned)time(NULL));
	//Load Weapon Info
	LoadWeapon();
	while (1)
	{
		int iSelect;
		DispLoby();
		iSelect = m_gmMapDraw.MenuSelectCursor(iCusorCount, iAddCol, iCursorX, iCursorY);
		switch ((LOBY_MENU)iSelect)
		{
		case LOBY_MENU_NEW:
			//Init & Set
			NewGameSet();
			//Game Start
			StartGame();
			break;
		case LOBY_MENU_LOAD:
			DispLoad();
			StartGame();
			break;
		case LOBY_MENU_EXIT:
			//Clear Weapon List
			m_vWeaponList.clear();
			return;
		}
	}
}