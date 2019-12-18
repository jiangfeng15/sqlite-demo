#include <iostream>
#include "sqlite3.h"
#include "SQLiteWrapper.h"

using namespace std;
#pragma comment(lib, "sqlite3.lib")

int main()
{
	sqlite3 *db = NULL;  
	char* sql = NULL; 
	char * szErr = NULL;
	//int ret = sqlite3_open("sqltestdb.db3", &db);
	//if(ret != SQLITE_OK)
	//{
	//	cout<<"打开数据库失败"<<endl;
	//}

	//sql = "CREATE TABLE COMPANY(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE INT NOT NULL);";
	//ret = sqlite3_exec(db, sql, 0, 0, &szErr);
	//if(ret != SQLITE_OK)
	//{
	//	cout<<"执行建表语句失败"<<endl;
	//}

	/*确定表名是否存在

	 sql = "select * from sqlite_master where type = 'table' and name = 'COMPANY'"
	*/
	//std::string 


	//sql = "INSERT INTO COMPANY VALUES(\"123456\",\"jiangfeng\", 22)";
	//for(int i=0; i<10000000; i++)
	//{
	//	ret = sqlite3_exec(db, sql, 0, 0, &szErr);
	//	if(ret != SQLITE_OK)
	//	{
	//		cout<<"执行语句失败"<<endl;
	//	}
	//}


	SQLiteWrapper sqlite;
	if (sqlite.Open("sqltestdb.db3"))
		cout << "sqltestdb.db3 created or opened" << endl;
	else
		cout << "can not opent sqltestdb.db3" << endl;
	SQLiteStatement * smt = sqlite.Statement("select * from company");
	int n = 0;
	//while (smt->NextRow())
	//{
	//	cout << smt->DataType(0) << "-" << smt->DataType(1) << "|" << smt->ValueString(0) << "-" << smt->ValueString(1) << endl;
	//	n++;
	//}
	cout << n << endl;
	smt = sqlite.Statement("select count(*) from patchdowntasktb");
	int nsum = smt->ValueInt(0);

	return 0;
}